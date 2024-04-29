import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.KeySpec;
import java.util.Base64;
import java.util.Scanner;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;

public class Rule17_19 {
/*
 * Rule 17 has to do with storing data securely. This is an example of encrypting data with SHA 256.
 * Rule 19 has to do with password strength and verification.This program validates that the user has a strong enough password for the application
 */
	
	private static String hash() throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeySpecException, InvalidKeyException, InvalidAlgorithmParameterException, IllegalBlockSizeException, BadPaddingException
	{
		Scanner scan=new Scanner(System.in);
		String pass;
		SecureRandom rand=new SecureRandom();
		
		System.out.println("Enter a password for the program. Password must have one upper case, lower case, number and symbol ( ! . # @ )");
		pass=scan.nextLine();
		while(validatePassword(pass)==false)
		{
			System.out.println("Enter a password for the program. Password must have one upper case, lower case, number and symbol ( ! . # @ )");
			pass=scan.nextLine();
		}
		
		SecretKeyFactory kf=SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
		byte [] salt=new byte[16];
		rand.nextBytes(salt);
		byte[] iv=new byte[16];
		rand.nextBytes(iv);
		IvParameterSpec ivSpec=new IvParameterSpec(iv);
		KeySpec ks=new PBEKeySpec(pass.toCharArray(),salt,65000,256);
		SecretKey sk=new SecretKeySpec(kf.generateSecret(ks).getEncoded(),"AES");
		Cipher cipher=Cipher.getInstance("AES/CBC/PKCS5Padding");
		cipher.init(Cipher.ENCRYPT_MODE, sk,ivSpec);
		byte [] hashedPass=cipher.doFinal(pass.getBytes());
		return Base64.getEncoder().encodeToString(hashedPass);	
	}
	
	private static boolean validatePassword(String password)
	{
		if(password.length()<8)
		{
			System.out.println("Password needs to be 8 characters.");
			return false;
		}
		
		boolean hasUpper=false;
		boolean hasLower=false;
		boolean hasNum=false;
		boolean hasSymbol=false;
		
		for(int i=0;i<password.length();i++)
		{
			char c=password.charAt(i);
			if(c>='0' && c<='9')
			{
				hasNum=true;
			}
			else if(c>='a' && c<='z')
			{
				hasLower=true;
			}
			else if(c>='A' && c<='Z')
			{
				hasUpper=true;
			}
			else if(c=='!' || c=='.' || c=='#' || c=='@')
			{
				hasSymbol=true;
			}
			else
			{
				return false;
			}
				
		}
		if(hasNum && hasLower && hasUpper && hasSymbol)
		{
			return true;
		}
		else return false;
	}
	
	
	
	
	
	public static void main(String[] args) throws InvalidKeyException, NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeySpecException, InvalidAlgorithmParameterException, IllegalBlockSizeException, BadPaddingException {
		// TODO Auto-generated method stub
		
		String hashedPass=hash();
		System.out.println(hashedPass);
	}

}
