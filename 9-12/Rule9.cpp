/**
 * @file        Rule9.cpp
 * @author      Lane Plummer
 * @brief       Catching Exceptions example that shows how to catch exceptions thrown instead of ignored or grouped together too 
 *              vaguely
 * @version     0.1
 * @date        2024-04-10
 * 
 * @copyright   Copyright (c) 2024
 * 
 */
#include <iostream>
#include <stdexcept>

//Function that throws an exception
void divide(int a, int b){
    if(b==0){
        throw std::invalid_argument("Division by zero error");
    }
    std::cout << "Result of Division: " << a/b << std::endl;
}

int main(){
    int dividend, divisor;

    std::cout << "Enter whole number dividend:";
    std::cin >> dividend;

    if(std::cin.fail()) {
        std::cerr << "Whole number not entered." << std::endl;
        return 0;
    }

    std::cout << "Enter whole number divisor:";
    std::cin >> divisor;

    if(std::cin.fail()){
        std::cerr << "Whole number not entered." << std::endl;
        return 0;
    }

    try{
        //Attempt the division
        divide(dividend, divisor);
    } catch(const std::invalid_argument& e){
        //Catch the exception and handle it properly
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception& e){
        //Catch any other exception not handled
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}