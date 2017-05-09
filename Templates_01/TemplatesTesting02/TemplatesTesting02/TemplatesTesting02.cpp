// TemplatesTesting02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class T>
T max(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	cout << max(10.1, 5.5) << endl;
	cout << max(10, 5) << endl;
	cout << max('h', 'i') << endl;
}

