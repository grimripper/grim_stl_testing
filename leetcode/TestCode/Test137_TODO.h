#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	//Key idea - design a counter that records state. 
	//The problem can be every one occurs K times except one occurs M times.
	//For this question, K=3,M=1
	//TODO: https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/2

public:
	int singleNumber(const vector<int>& nums) {
		return -1;
	}
};

void run()
{
	cout << Solution().singleNumber({ 5,6,5,6,8 }) << endl;
}
