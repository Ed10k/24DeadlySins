/**
 * @file Rule8.cpp
 * @author Matthew Fonner
 * @brief C++ Catastrophes example using proper memory allocation
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>


using namespace std;

class testClass
{
    public:
    testClass()
    {
        //Default constructor properly allocates dynamic memory in an array
        cout<<"Creating object \n";
        numDoubles = 5;
        arr = new double[numDoubles];
    }
    ~testClass()
    {
        //Destructor properly clear dynamic memory
        clear();
    }
    testClass operator=(const testClass &rhs)
    {
        //assignment operator prevents race conditions or dangling pointers
        //by creating new copy of object and deleting the old.
        if(this != &rhs)
        {
            clear();
            copy(rhs);
        }
        return *this;
    }


    private:
    //helper methods to avoid code duplication
    void copy(const testClass &rhs)
    {
        //perform a deep copy and allocate memory for the other pointer
        cout<<"Copying object\n";
        numDoubles = rhs.numDoubles;
        arr = new double[numDoubles];
        for(int i = 0; i< numDoubles; i++)
        {
            arr[i] = rhs.arr[i];
        }
    }

    void clear()
    {
        //perform the appropriate delete operation
        cout<<"Clearing object\n";
        delete[] arr;
    }

    double* arr; //dynamic array
    int numDoubles; //number of Doubles in array

};

int main()
{
    testClass t1 = testClass();
    testClass t2 = t1;
    return 0;
}