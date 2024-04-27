/**
 * @file        Rule12.cpp
 * @author      Lane Plummer
 * @brief       Information Leakage example
 * @version     0.1
 * @date        2024-04-10
 * 
 * @copyright   Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>
#include <string.h>
#include <intrin.h>

class SecureData{
private:
    char* data;
    size_t size;

public:
    //Constructor
    SecureData(const char* input, size_t length){
        size = length;
        data = new char[size];

        //Copy input data into secure memory
        memcpy(data, input, size);
    }

    ~SecureData(){
        //Securely erase data before deallocation
        erase();
        delete[] data;
    }

    //Method to securely erase data
    void erase(){
        //Overwrite data with zeros
        if(data != nullptr){
            volatile char* ptr = data; //Volatile to prevent optimization
            for(size_t i = 0; i < size; ++i){
                ptr[i] = 0;
            }
        }
    }

    //Method to display data
    void display(){
        std::cout << "Data: " << data << std::endl;
    }
};

int main(){
    const char* sensitiveInfo = "Sensitive Information";
    size_t length = strlen(sensitiveInfo);

    //Store sensitive information securely
    SecureData secure(sensitiveInfo, length);

    //Display the sensitive information
    std::cout << "Before erasing: " << std::endl;
    secure.display();

    //Erase sensitive information
    secure.erase();

    //Display again (now should show nothing)
    std::cout << "After erasing: " << std::endl;
    secure.display();

    return 0;
}