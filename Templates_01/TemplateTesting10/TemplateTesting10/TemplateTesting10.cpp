// TemplateTesting10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class X
{
public:
	static T s;
};

template <class T> T X<T>::s = 0;
template <> int X<int>::s = 2;
template <> float X<float>::s = 2.2f;


int main()
{
	X<int> x;
	X<float> f;
	cout << x.s << endl;
	cout << f.s << endl;
    return 0;
}

