#include <utility>
#include <iostream>
#include "RvalueRef.hpp"
using namespace std;

struct W
{
    W(int &, int &) {}
};

struct X
{
    X(const int &, int &) {}
};

struct Y
{
    Y(int &, const int &) {}
};

struct Z
{
    Z(const int &, const int &) {}
};

// template <typename T, typename A1, typename A2>
// T *factory(A1 &a1, A2 &a2)
// {
//   return new T(a1, a2);
// }

template <typename T, typename A1, typename A2>
T *factory(A1 &&a1, A2 &&a2)
{
    return new T(std::forward<A1>(a1), std::forward<A2>(a2));
}

// A class that contains a memory resource.
class MemoryBlock
{
    // TODO: Add resources for the class here.
};

void g(const MemoryBlock &)
{
    cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock &&)
{
    cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock &&f(MemoryBlock &&block)
{
    g(block);
    return move(block);
}

template <typename T>
struct S;

// The following structures specialize S by
// lvalue reference (T&), const lvalue reference (const T&),
// rvalue reference (T&&), and const rvalue reference (const T&&).
// Each structure provides a print method that prints the type of
// the structure and its parameter.

template <typename T>
struct S<T &>
{
    static void print(T &t)
    {
        cout << "print<T&>: " << t << endl;
    }
};

template <typename T>
struct S<const T &>
{
    static void print(const T &t)
    {
        cout << "print<const T&>: " << t << endl;
    }
};

template <typename T>
struct S<T &&>
{
    static void print(T &&t)
    {
        cout << "print<T&&>: " << t << endl;
    }
};

template <typename T>
struct S<const T &&>
{
    static void print(const T &&t)
    {
        cout << "print<const T&&>: " << t << endl;
    }
};

// This function forwards its parameter to a specialized
// version of the S type.
template <typename T>
void print_type_and_value(T &&t)
{
    S<T &&>::print(std::forward<T>(t));
}

// This function returns the constant string "fourth".
const string fourth() { return string("fourth"); }

void Test1()
{
    // int a = 4, b = 5;
    // W *pw = factory<W>(a, b);
    // Z *pz = factory<Z>(a, b);
    // Z *p1 = factory<Z>(3, 4);
    g(f(MemoryBlock()));
}

void Test2()
{
    // The following call resolves to:
    // print_type_and_value<string&>(string& && t)
    // Which collapses to:
    // print_type_and_value<string&>(string& t)
    string s1("first");
    print_type_and_value(s1);

    // The following call resolves to:
    // print_type_and_value<const string&>(const string& && t)
    // Which collapses to:
    // print_type_and_value<const string&>(const string& t)
    const string s2("second");
    print_type_and_value(s2);

    // The following call resolves to:
    // print_type_and_value<string&&>(string&& t)
    print_type_and_value(string("third"));

    // The following call resolves to:
    // print_type_and_value<const string&&>(const string&& t)
    print_type_and_value(fourth());
}

void RvalueRef::RunTest()
{
    int&& a = 6;
    //a++;
    printf("%d\n", a++);
    //Test2();
}
