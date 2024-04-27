/**
 * @file        Rule10.cpp
 * @author      Lane Plummer
 * @brief       Command Injection example showing how to create mediator code to prevent cmdinj
 * @version     0.1
 * @date        2024-04-10
 * 
 * @copyright   Copyright (c) 2024
 * 
 */
#include <iostream>
#include <cstdlib>
#include <string>

bool isValidFilename(const std::string& filename){
    //This is a basic example of valid characters in a filename
    return filename.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-") == std::string::npos;
}

int main(){
    std::string filename;

    std::cout << "Enter filename: " << std::endl;
    std::cin >> filename;

    if(!isValidFilename(filename)){
        std::cerr << "Invalid filename!" << std::endl;
        return 1;
    }

    //Construct the command using a parameter-based query
    std::string command = "ls -l ";
    command += filename;

    //Use system() to execute the command
    int returnCode = system(command.c_str());

    if(returnCode != 0){
        std::cerr << "Command failed" << std::endl;
        return 1;
    }
    
    return 0;
}