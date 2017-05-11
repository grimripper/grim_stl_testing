#pragma once

#include <iostream>
#include <string>

using namespace std;

void run()
{
	{
		string s1 = "Goodbye";
		cout << s1[2] << endl;
		s1[2] = 'x';
		cout << s1 << endl;
		s1.at(2) = 'y'; // this has range check
		cout << s1 << endl;
		//cout << s1[20] << endl;

		cout << s1.front() << endl;
		cout << s1.back() << endl;

		s1.push_back('z');
		cout << s1 << endl;
		s1.pop_back();
		cout << s1 << endl;

		//s1.begin() and s1.end() are iterators
		//vector is similar to string

		//Like vector, string doesn't have push_front and pop_front

		string s3(s1.begin(), s1.begin() + 3);
		cout << s3 << endl;
	}

	{
		//Ranged access
		//assign, append, insert, replace

		string s2 = "Dragon Land";
		string s1;
		s1.assign(s2); // s1 = s2
		cout << s1 << endl;

		s1.assign(s2, 2, 4); //start_pos, size (if only one specified, then start_pos)
		cout << s1 << endl;

		s1.assign("Wisdom", 3); //size
		cout << s1 << endl;

		s1.assign(4, 'x');
		cout << s1 << endl;

		s1.assign({ 'a', 'b', 'c' });
		cout << s1 << endl;
	}

	{
		string s1("abc");
		string s2 = "Dragon Land";
		s1.append(" def");
		cout << s1 << endl;

		s1.insert(2, "mountain", 4);
		cout << s1 << endl;

		s1.replace(2, 5, s2, 3, 3);
		cout << s1 << endl;
	}

	{
		//erase
		string s1 = "abcog def";
		s1.erase(1, 4);
		cout << s1 << endl;

		string s2 = "Dragon Land";
		cout << s2.substr(2, 4) << endl;

		s1 = "abc";
		cout << s1.c_str() << endl; //'abc\0' in C++11
		cout << s1.data() << endl; //'abc\0'in C++11

		s1.swap(s2);
		cout << s1 << endl;
	}
}
