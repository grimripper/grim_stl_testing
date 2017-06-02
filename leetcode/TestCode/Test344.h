#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string s2 = s;
		for (int i = 0, j = s2.size() - 1; i < j; i++, j--)
			swap(s2[i], s2[j]);
		return s2;
	}
};

void run()
{
	cout << Solution().reverseString("hello") << endl;
}
