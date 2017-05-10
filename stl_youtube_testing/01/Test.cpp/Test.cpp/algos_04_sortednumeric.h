#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include "common.h"

using namespace std;

void run()
{
	//Can only work on sorted data
	//binary search, merge, set operations

	{
		vector<int> vec = { 8,9,9,45,87,90 };
		bool found = binary_search(vec.begin(), vec.end(), 9);
		cout << found << endl;

		vector<int> s = { 9, 45, 90 };
		found = includes(vec.begin(), vec.end(), s.begin(), s.end());
		cout << found << endl;

		auto itr = lower_bound(vec.begin(), vec.end(), 9);
		cout << distance(vec.begin(), itr) << endl;

		itr = upper_bound(vec.begin(), vec.end(), 9);
		cout << distance(vec.begin(), itr) << endl;

		auto pair_itr = equal_range(vec.begin(), vec.end(), 9);
		cout << distance(vec.begin(), pair_itr.first) << "<->"
			<< distance(vec.begin(), pair_itr.second) << endl;
	}

	{
		//2. merge

		vector<int> vec = { 8, 9, 9, 10 };
		vector<int> vec2 = { 7,9,10 };
		vector<int> vec_out(7);

		merge(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
		print_vec(vec_out);

		vector<int> vec3 = { 1,2,3,4,1,2,3,4,5 };
		//1 step of merge sort
		inplace_merge(vec3.begin(), vec3.begin() + 4, vec3.end());
		print_vec(vec3);
	}

	{
		//Set union
		vector<int> vec = { 8,9,9,10 };
		vector<int> vec2 = { 7,9,10 };
		vector<int> vec_out(5);

		set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
		print_vec(vec_out);

		fill(vec_out.begin(), vec_out.end(), 0);
		set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
		print_vec(vec_out);

		//set_difference

		//set_symmetric_difference
		fill(vec_out.begin(), vec_out.end(), 0);
		set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin());
		print_vec(vec_out);
	}

	{
		//Numeric algos - accumulate, inner product, partial sum, adjacent difference
		vector<int> vec{ 1,2,3 };
		int x = accumulate(vec.begin(), vec.end(), 0);
		cout << x << endl;

		x = accumulate(vec.begin(), vec.end(), 1, multiplies<int>());
		cout << x << endl;
	}

	{
		vector<int> vec = { 1,2,3,10,1,2,3 };
		int x = inner_product(vec.begin(), vec.begin() + 3, vec.end() - 3, 0);
		//1*1 + 2*2 + 3*3
		cout << x << endl;

		x = inner_product(vec.begin(), vec.begin() + 3, vec.end() - 3, 1, multiplies<int>(), plus<int>());
		//(1+1)*(2+2)*(3+3)
		cout << x << endl;
	}

	{
		//partial_sum, adjacent_difference

		vector<int> vec{ 1,2,3,4 };
		partial_sum(vec.begin(), vec.end(), vec.begin());
		print_vec(vec);

		//adjacent_difference
	}
}
