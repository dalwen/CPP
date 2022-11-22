#include <string>
#include <iostream>
#include "RefTest.hpp"
using namespace std;

struct Special 
{
    int data;
    string metadata;
};

// Function to return as return by reference
int& returnValue(int& x)
{
  
    // Print the address
    cout << "x = " << x
         << " The address of x is "
         << &x << endl;
  
    // Return reference
    return x;
}


void RefTest::RunTest()
{
    Special a;
    a.data = 10;
    a.metadata = "dfd";

    Special& s = a;
    cout << s.data << endl;
    int b = 100;
    returnValue(b) = 50;
    cout << "b = " << b <<endl;

    int x = 4;
    auto &r = x;
    r += 2;
    cout << "x = " << x <<endl;
    auto y = x * x;
    cout << "y = " << y <<endl;


}