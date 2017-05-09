// TemplateTesting08.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T=int, int elements=10>
class A
{
public:
	T a;
	void output()
	{
		cout << a*elements << endl;
	}
};

int main()
{
	A<float> b;
	b.a = 5.5f;
	b.output();

	A<> c;
	c.a = 2;
	c.output();

	A<int, 30> d;
	d.a = 2;
	d.output();

    return 0;
}

