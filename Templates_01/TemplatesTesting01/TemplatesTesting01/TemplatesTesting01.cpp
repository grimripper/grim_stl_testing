// TemplatesTesting01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	typedef Stack<int> IntStack;
	typedef Stack<float> FloatStack;

	FloatStack fs(5);
	float f = 1.1;
	cout << "Pushing elements onto fs" << endl;

	while (fs.push(f))
	{
		cout << f << ' ';
		f += 1.1;
	}
	cout << "Stack full" << endl;
	cout << "Popping elements.. " << endl;
	while (fs.pop(f))
	{
		cout << f << ' ';
	}
	cout << "Stack empty" << endl;

	Stack<int> s;
	s.push(5);
	int val;
	s.pop(val);
	cout << val << endl;
    return 0;
}

