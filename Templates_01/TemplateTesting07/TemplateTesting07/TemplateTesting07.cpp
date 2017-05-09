// TemplateTesting07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template <>
char* max(char* a, char* b)
{
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	cout << max(3, 4) << endl;
	cout << max("hello", "bye") << endl;

    return 0;
}

