//TODO: NOT OPTIMAL: https://github.com/kamyu104/LeetCode/blob/master/C++/longest-substring-without-repeating-characters.cpp

#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int first_idx = 0;
		int longestSoFar = 0;
		while (first_idx < s.size())
		{
			unordered_set<char> chars_map;
			int length = 0;
			for (int i = first_idx; i < s.size(); ++i)
			{
				if (chars_map.count(s[i]))
				{
					break;
				}
				++length;
				chars_map.insert(s[i]);
			}
			if (length > longestSoFar)
			{
				longestSoFar = length;
			}

			++first_idx;
		}
		return longestSoFar;
	}
};

void run()
{
	int len = Solution().lengthOfLongestSubstring("abcabcbb");
	cout << len << endl;
}
