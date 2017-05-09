// TemplateTesting05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <int N>
struct Factorial
{
	static const int value = N*Factorial<N - 1>::value;
};

template <>
struct Factorial<0>
{
	static const int value = 1;
};

int main()
{
	cout << Factorial<5>::value << endl;
	cout << Factorial<1>::value << endl;
	//cout << Factorial<-1>::value << endl;
	return 0;
}

