/**
 * @file Rule6.cpp
 * @author Matthew Fonner
 * @brief Format string problems examples.
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char userInput[] = "Hello %s";

    //printf with no command is bad practice as users can inject commands into an unformatted string themselves
    printf("This is unformatted as there is no commands in the printf function.", userInput);

    //printf with a format command is better as it formats the string before using it for other data.
    printf("%s", "This is formatted as there is a %s formatting command in the printf function.");
    printf("%s\n", userInput);

    return 0;
}