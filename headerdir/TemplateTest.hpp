#pragma once
#include "BaseTest.hpp"
#include <iostream>
using namespace std;

template <class T>
class TemplateTest : public BaseTest
{
public:
    TemplateTest(){};

    TemplateTest(T n) : number(n){};

    void RunTest() // https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
    {
        cout << "Got " << typeid(GetNumber()).name() << " with value " << GetNumber() << endl;
    }

    T GetNumber() { return number; }

private:
    T number;
};
