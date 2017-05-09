// TemplateTesting11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class X
{
private:
	T a;
	int g;

friend void f1();
//friend void f2(X<T>&); - doesn't work
//friend class Y<T>; - doesn't work
};

X<int> x;

template <class T>
class Y
{
public:
	void f1()
	{
		x.g = 1;
		cout << x.g << endl;
	}

	void f2()
	{
		x.g = 2;
		cout << x.g << endl;
	}
};

void f1()
{
	x.g = 4;
	cout << x.g << endl;
}

//template <class T>
//void f2(X<T>& y)
//{
//	y.g = 5;
//	cout << y.g << endl;
//}

#pragma warning (push)
#pragma warning (disable: 4700)

int main()
{
	f1();

	//X<int> s;
	//f2<int>(s);

	//Y<int> y;
	//y.f1();
	//y.f2();

    return 0;
}

#pragma warning (pop)
