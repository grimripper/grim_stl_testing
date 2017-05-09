// TemplateTesting06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class X
{
public:
	X()
	{
		cout << "hello X<T1,T2>" << endl;
	}
};

template <typename T1>
class X<T1, int>
{
public:
	X()
	{
		cout << "hello X<T1,int>" << endl;
	}
};

template <typename T2>
class X<float, T2>
{
public:
	X()
	{
		cout << "hello X<float, T2>" << endl;
	}
};

int main()
{
	X<char, char> xcc;
	X<char, int> xci;
	X<float, char> xfc;
	//X<float, int> xfi; // fails compile time check

    return 0;
}

