/**
 * @file Rule5.cpp
 * @author Matthew Fonner
 * @brief Buffer overrun problems examples.
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    //sample string to copy into
    char str1[] = "This is a sample string.";
    cout<<str1 << '\n';

    //string to copy from
    string str2;
    cout<<"Please enter the string you wish you copy: ";
    cin>>str2;

    //convert 2nd string into c string
    const char* str3 = str2.c_str();

    //determine size of both strings
    size_t str3len = strlen(str3);
    size_t str1len = strlen(str1);

    //if the source string is larger than the destination, don't copy
    if(str3len > str1len)
    {
        cout<<"String is too large. Please use a string smaller than: " << str1len << " characters\n";
    }
    else{
        strcpy(str1,str3);
        cout<<"Strings copied. New string: " << str1;
    }

    delete[] str3;
    return 0;
}