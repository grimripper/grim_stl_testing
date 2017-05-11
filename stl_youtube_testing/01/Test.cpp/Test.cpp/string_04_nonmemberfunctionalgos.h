#pragma once

#include <string>
#include <iostream>

using namespace std;

void run()
{
	{
		string s1 = "hello";
		//getline(cin, s1, ';'); //delimiter is ';'
		//cout << s1;

		s1 = to_string(8);
		cout << s1 << endl;

		s1 = to_string(034);
		cout << s1 << endl;

		s1 = to_string(0xa4);
		cout << s1 << endl;

		//convert a string into a number
		s1 = "190 monkeys";
		int i = stoi(s1);
		cout << i << endl;

		size_t pos;
		i = stoi(s1, &pos);
		cout << pos << endl;

		s1 = "a monkey";
		//i = stoi(s1, &pos); //exception of invalid_argument
		i = stoi(s1, &pos, 16); // will parse 'a' as 10
		cout << i << endl;

		//stol, stod, stof, etc. - does simple string conversion

		//for complex string formatting, use stringstream

		//lexical_cast() from boost library
	}
}
