// TemplateTesting04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class stream
{
public:
	void f() { cout << "stream<T>::f()" << endl; }
	void g() { cout << "stream<T>::g()" << endl; }
};

template <>
class stream<char>
{
public:
	void f() { cout << "stream<char>::f()" << endl; }
	
};


int main()
{
	stream<int> si;
	stream<char> sc;

	si.f();
	si.g();
	sc.f();
	//sc.g(); - There is no g()
    return 0;
}

