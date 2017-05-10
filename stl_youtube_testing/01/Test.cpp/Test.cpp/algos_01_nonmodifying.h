#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run()
{
	{
		//STL algo walkthrough
		//count, min & max, compare, linear search, attribute

		vector<int> vec{ 4,5,6,6,10 };

		cout << count_if(vec.begin(), vec.end(), [](int x) { return x < 10; }) << endl;

		cout << count(vec.begin(), vec.end(), 6) << endl;

		//Returns the first max value
		cout << *max_element(vec.begin(), vec.end()) << endl;

		//LSB
		cout << *max_element(vec.begin(), vec.end(), [](int x, int y) { return (x % 10) < (y % 10); }) << endl;

		//The first smallest element and the largest max element (???)
		auto pair_of_itr = minmax_element(vec.begin(), vec.end());
		cout << *pair_of_itr.first << endl;
		cout << *pair_of_itr.second << endl;
	}

	{
		//Linear searching (use when data is not sorted, otherwise use binary search)
		//Returns the first match
		vector<int> vec{ 4,3,5,2,1,1 };
		cout << *find(vec.begin(), vec.end(), 5) << endl;

		cout << *find_if(vec.begin(), vec.end(), [](int x) { return x > 3; }) << endl;

		cout << *find_if_not(vec.begin(), vec.end(), [](int x) { return x <= 3; }) << endl;

		//Consecutive 2 items of 1
		cout << *search_n(vec.begin(), vec.end(), 2, 1) << endl;
	}

	{
		//Search subrange
		vector<int> vec{ 2,3,4,5,6,7,8, 1,5,6,7 };
		vector<int> sub{ 5,6,7 };
		auto itr = search(vec.begin(), vec.end(), sub.begin(), sub.end());
		cout << *itr << endl;
		cout << distance(vec.begin(), itr) << endl;
		itr = find_end(vec.begin(), vec.end(), sub.begin(), sub.end());
		cout << *itr << endl;
		cout << distance(vec.begin(), itr) << endl;
	}

	{
		//Search any of
		vector<int> vec{ 2,3,4,5,6,7,8, 1,5,6,7 };
		vector<int> items{ 5,6 };

		auto it = find_first_of(vec.begin(), vec.end(), items.begin(), items.end());
		cout << distance(vec.begin(), it) << endl;

		it = adjacent_find(vec.begin(), vec.end());
		cout << distance(vec.begin(), it) << endl;
	}

	{
		//Compare ranges
		//equal
		//is_permutation
		//mismatch
		//lexicographical_compare
	}

	{
		//Check attributes
		//is_sorted
		//is_sorted_until
		//is_partitioned (partitioned according to some condition)
		//is_heap
		//is_heap_until
	}

	{
		vector<int> vec{ 10, 20, 40 };
		bool b = all_of(vec.begin(), vec.end(), [](int x) { return x % 10 == 0; });
		cout << b << endl;

		//any_of
		//none_of
	}
}
