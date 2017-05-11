#pragma once
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void run()
{
	{
		string s1 = "Variety is the spice of life.";
		int num = count(s1.begin(), s1.end(), 'e');
		cout << num << endl;

		num = count_if(s1.begin(), s1.end(), [](char c) {return c <= 'e' && c >= 'a'; });
		cout << num << endl;

		s1 = "Goodness is better than beauty.";
		//string::iterator itr = search_n(s1.begin(), s1.end() + 20, 2, 's');
		//cout << *itr << endl;

		auto itr = s1.begin() + 5;
		s1.erase(itr, itr + 5);
		cout << s1 << endl;

		s1.insert(itr, 3, 'x');
		cout << s1 << endl;

		s1.replace(itr, itr + 3, 3, 'y'); //replace substrings
		cout << s1 << endl;

		s1 = "abc";
		string s2 = "bca";
		cout << is_permutation(s1.begin(), s1.end(), s2.begin()) << endl;

		replace(s1.begin(), s1.end(), 'a', ' '); //replacing characters
		cout << s1 << endl;

		s1 = "abcdefghijklmnopqrstuvwxyz";
		s2 = s1;
		transform(s1.begin(), s1.end(), s2.begin(), [](char c) {if (c < 'n') return 'a'; else return 'z'; });
		cout << s2 << endl;

		//rotate
	}

	{
		string s;
		u16string s1; //string char16_t
		u32string s2; //string char32_t
		wstring s3; //string wchar_t (wide character)

		//to_wstring(8);
	}
}
