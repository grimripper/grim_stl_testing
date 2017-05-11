#pragma once

#include <string>
using namespace std;

void run()
{
	{
		//Constructors
		string s1("hello");
		cout << s1 << endl;
		string s2("hello", 3); //size
		cout << s2 << endl;
		string s3(s1, 2); //starting position
		cout << s3 << endl;
		string s4(s1, 2, 2); //size and starting position
		cout << s4 << endl;
		string s5(5, 'a');
		cout << s5 << endl;
		string s6({ 'a', 'b', 'c' });
		cout << s6 << endl;
	}

	{
		//Size
		string s1 = "Goodbye";
		cout << s1.size() << s1.length() << endl;  // size = length
		cout << s1.capacity() << endl; // capacity > size
		s1.reserve(100);
		cout << s1.capacity() << endl;
		s1.reserve(5); // reserve doesn't change the content... so just a hint?
		cout << s1 << endl; // s1:"Goodbye" and size == 7
		cout << s1.capacity() << endl;

		s1.shrink_to_fit();
		cout << s1.capacity() << endl;

		//Does change the content of the string
		s1.resize(9);
		cout << s1 << endl;
		cout << s1.size() << endl;
		s1.resize(12, 'x');
		cout << s1 << endl;
		cout << s1.size() << endl;
		s1.resize(3);
		cout << s1 << endl;
		cout << s1.size() << endl;
	}
}
