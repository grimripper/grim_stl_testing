// TemplatesTesting03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class Z
{
public:
	Z() {}
	~Z() {}
};

template <class T>
void Test(T a)
{
	cout << a << endl;
}

//template class Z<int>;
//template class Z<float>;
template void Test<int>(int);
int main()
{
	//Z<int> *f;
	Test(4);
	Test(3.3);
    return 0;
}

