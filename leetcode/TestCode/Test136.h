#pragma once

//Single number in a vector of numbers appearing twice
//Idea is to XOR all numbers

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNumber(const vector<int>& nums) {
		int xor = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			xor ^= nums[i];
		}
		return xor;
	}
};

void run()
{
	cout << Solution().singleNumber({5,6,5,6,8}) << endl;
}