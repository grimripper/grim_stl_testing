#pragma once

#include <iostream>
#include <string>

using namespace std;

void run()
{
	{
		//copy, find, compare
		string s1 = "abcdefg";
		char buf[20];
		size_t len = s1.copy(buf, 3);
		cout << len << " " << buf << endl;

		len = s1.copy(buf, 4, 2); //bad design: only exception where 1st param is size, 2nd param is pos
		cout << len << " " << buf << endl;

		s1 = "If a job is worth doing, it's worth doing well";
		size_t found = s1.find("doing");
		cout << found << endl;

		found = s1.find("doing", 20); //start at 20
		cout << found << endl;

		found = s1.find("doing well", 20);
		cout << found << endl;

		found = s1.find("doing well", 0, 5); //start from 0, but only look at 5 characters
		cout << found << endl;

		found = s1.find_first_of("doing"); // one of 'd', 'o', 'i', 'n', 'g'
		cout << found << endl;

		found = s1.find_first_of("doing", 10, 1); //start from 10, only 1 character
		cout << found << endl;

		found = s1.find_first_not_of("doing");
		cout << found << endl;

		//find_last_not_of
	}

	{
		//compare
		string s1 = "abc";
		string s2 = "abcd";
		cout << s1.compare(s2) << endl; // -1

		s2 = "abc";
		cout << s1.compare(s2) << endl; // 0

		//same as if (s1 == s2) or if (s1 > s2)
		//except compare gives you more flexibility

		s2 = "abcd";
		cout << s2.compare(0, 3, s1) << endl; //0
	}

	{
		//concat
		string s1 = "abc";
		string s2 = "def";
		string s3 = s1 + s2; // not a cheap operation

		cout << s3 << endl;
	}
}
