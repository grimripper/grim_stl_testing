#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
	uint16_t reverseBits(uint16_t n) {
		uint16_t reversed = (n >> 8 | n << 8);
		//cout << hex << reversed << endl;
		reversed = ((reversed & 0xF0F0) >> 4) | ((reversed & 0x0F0F) << 4);
		//cout << hex << reversed << endl;
		reversed = ((reversed & 0xCCCC) >> 2) | ((reversed & 0x3333) << 2);
		//cout << hex << reversed << endl;
		reversed = ((reversed & 0xAAAA) >> 1) | ((reversed & 0x5555) << 1);
		//cout << hex << reversed << endl;
		return reversed;
	}
};

void run()
{
	int reversed = Solution().reverseBits(0x3EF6);
	cout << showbase << uppercase << hex << reversed << endl;
}