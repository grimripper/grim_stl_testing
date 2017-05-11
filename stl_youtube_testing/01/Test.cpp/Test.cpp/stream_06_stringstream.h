#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void run()
{
	{
		stringstream ss; //stream without io operation
		//read/write of string
		//a way to use formatting for string (offline formatting of string)

		ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;
		cout << ss.str() << endl;

		int a, b, c;
		string s1;
		ss >> hex >> a; //formatted input works token by token. spaces,tabs,newlines
		cout << a << endl; //a == 137
		ss >> s1;
		cout << s1 << endl;
		ss.ignore(6);
		ss >> s1;
		cout << s1 << endl;
	}

	{
		//better type safety and communicates intent
		//ostringstream - only for formatted output
		//istringstream - only for formatted input 
	}
}
