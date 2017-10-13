#include <iostream>
#include "MyClass.h"

using namespace std;

MyClass::MyClass()
{
    cout << "This is the constructor calling." << endl;
}

MyClass::~MyClass()
{
    cout << "This is the destructor calling." << endl;
}

void MyClass::myPrint()
{
    cout << "Hello" << endl;
}
