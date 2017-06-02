#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> lookup;
		for (int i = 0; i < nums.size(); ++i)
		{
			lookup[nums[i]] = i;
		}

		int first_idx = -1;
		int second_idx = -1;
		for (int i = 0; i < nums.size(); ++i)
		{
			first_idx = i;
			int desired_num = target - nums[first_idx];
			if (lookup.count(desired_num))
			{
				second_idx = lookup[desired_num];
				break;
			}
		}

		vector<int> result;
		result.push_back(first_idx);
		result.push_back(second_idx);
		return result;
	}
};

class Solution2
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> lookup;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (lookup.count(target - nums[i]))
			{
				return{ lookup[target - nums[i]], i };
			}

			lookup[nums[i]] = i;
		}

		return {};
	}
};

void run()
{
	vector<int> v{ 2,7,11,15 };
	vector<int> v2 = Solution2().twoSum(v, 9);
	for (auto it : v2)
	{
		cout << it << endl;
	}
}
