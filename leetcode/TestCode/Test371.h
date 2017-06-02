#pragma once
#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int i = 0;
		int c = 0;
		int carry = 0;
		while (i < 32) {
			int a_bit = (a & (1 << i)) >> i;
			int b_bit = (b & (1 << i)) >> i;
			int c_bit = a_bit ^ b_bit;
			int c_bit_xor_carry = c_bit ^ carry;

			carry = (a_bit & b_bit) | (c_bit & carry);
			c = c | (c_bit_xor_carry << i);

			++i;
		}

		return c;
	}
};

void run()
{
	cout << Solution().getSum(45, 25) << endl;
}
