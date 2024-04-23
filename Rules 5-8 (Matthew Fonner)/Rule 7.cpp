/**
 * @file Rule7.cpp
 * @author Matthew Fonner
 * @brief Integer Overflow Example using the 
 *  addition and subtraction of two random numbers
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <time.h>
#include <climits>

using namespace std;

int main()
{
    //produces random numberseed
    srand(time(nullptr));
    int num = rand()% INT_MAX;
    cout<<"Number 1: " << num<<'\n';
    int num2 = rand()% INT_MAX;
    cout<<"Number 2: " << num2<<'\n';

    // adds two numbers together to see if it is within valid range
    cout<< "The sum of the two numbers is ";
    if(num + num2 < INT_MAX)
    {
        cout << num+num2 << " and within the integer range.\n";
    }
    else{
        cout<<" not within the integer range. \n";
    }

    //subtracts two numbers to see if its within valid range
    cout<<"The difference of the two numbers is ";
    if(num-num2 > INT_MIN)
    {
        cout << num-num2 << " and within the integer range.\n";
    }
    else{
        cout<<" not within the integer range. \n";
    }

}
