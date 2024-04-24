"""
@File RULE21.PY
@Author: Joseph Edozie
@Brief: Using The Wrong Cryptography
@Date: 2024-04-17

"""
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
import os

def encrypt_data(data, password):
    # Generate a random salt
    salt = os.urandom(16)
    
    # Derive a key from the password using PBKDF2 HMAC SHA-256
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        length=32,
        salt=salt,
        iterations=100000,
        backend=default_backend()
    )
    key = kdf.derive(password.encode())
    
    # Encrypt the data using AES CBC mode
    iv = os.urandom(16)  # Initialization vector
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()
    padded_data = data + b' ' * (16 - len(data) % 16)  # Padding data
    encrypted_data = encryptor.update(padded_data) + encryptor.finalize()
    
    return salt, iv, encrypted_data

def decrypt_data(encrypted_data, password, salt, iv):
    # Derive the same AES key from the password and salt
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        length=32,
        salt=salt,
        iterations=100000,
        backend=default_backend()
    )
    key = kdf.derive(password.encode())
    
    # Decrypt the data using AES CBC mode
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    decryptor = cipher.decryptor()
    decrypted_padded_data = decryptor.update(encrypted_data) + decryptor.finalize()
    return decrypted_padded_data.rstrip(b' ')  # Remove padding

def hash_data(data):
    # Hashing the data using SHA-256
    digest = hashes.Hash(hashes.SHA256(), backend=default_backend())
    digest.update(data.encode())
    return digest.finalize()



def main():

    # Usage
    password = input("What is your password?")
    data = b"Hello, this is sensitive data!"

    # Encrypting the data
    salt, iv, encrypted_data = encrypt_data(data, password)
    print("Encrypted:", encrypted_data)

    # Decrypting the data
    decrypted_data = decrypt_data(encrypted_data, password, salt, iv)
    print("Decrypted:", decrypted_data)

    # Hashing the data
    hashed_data = hash_data("Securely hashed data")
    print("SHA-256 Hashed Output:", hashed_data.hex())


main()