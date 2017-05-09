// TemplateTesting12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <typename T> struct restrictor {};
template <> struct restrictor<float> { typedef float result; };
template <> struct restrictor<double> { typedef double result; };

//template <typename T>
//template restrictor<T>::result
//distance(T a1)
//{
//	return a1;
//}

int main()
{
	//distance<float>(4.4);

    return 0;
}

