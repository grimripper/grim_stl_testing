// TemplateTesting09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class T {};
//int i;

template <class T, T i>
void f(T t)
{
	T t1 = i;
	//::T t2 = ::i;
}

template <class T, float* f>
class X
{
public:
	X()
	{
		cout << f << endl;
	}
};

int main()
{
	f<char,'s'>('s');
	//const float g = 5.5f;
	//X<int, &g> gS;
    return 0;
}

