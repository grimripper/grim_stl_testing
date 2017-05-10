#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "common.h"

using namespace std;

bool lsb_less(int x, int y)
{
	return (x % 10) < (y % 10);
}

bool lessThan10(int i)
{
	return (i < 10);
}

void run()
{
	{
		//sorting algorithm requires random access iterators:
		// vector, deque, container array, native array

		vector<int> vec{ 9, 1, 2, 10 };

		//default comparison function is '<' -> ascending order
		sort(vec.begin(), vec.end(), lsb_less);
		print_vec(vec);

		sort(vec.begin(), vec.end(), greater<int>());
		print_vec(vec);
	}

	{
		//Sometimes we don't need complete sorting
		//Find top 5 students

		vector<int> vec = { 1, 4, 5, 2, 6, 7, 10, 12, 56, 33 };

		partial_sort(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
		print_vec(vec);
	}

	{
		//Find top 5 students but don't care about the order

		vector<int> vec = { 1, 4, 5, 2, 6, 7, 10, 12, 56, 33 };

		nth_element(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
		print_vec(vec);
	}

	{
		//Move students whose score is < 10 to the front
		vector<int> vec = { 1, 4, 5, 2, 6, 7, 10, 12, 56, 33 };

		random_shuffle(vec.begin(), vec.end());
		print_vec(vec);

		partition(vec.begin(), vec.end(), lessThan10);
		print_vec(vec);

		//To preserve original order within each partition
		stable_partition(vec.begin(), vec.end(), lessThan10);
		print_vec(vec);
	}

	{
		//Heap algorithms
		//1. First element is always the largest
		//2. Add/remove takes O(log n) time

		vector<int> vec{ 9, 1, 10, 2, 20, 40, 20, 6 };
		make_heap(vec.begin(), vec.end());
		print_vec(vec);

		pop_heap(vec.begin(), vec.end());
		print_vec(vec);

		vec.pop_back();
		print_vec(vec);

		vec.push_back(100);
		print_vec(vec);
		push_heap(vec.begin(), vec.end());
		print_vec(vec);

		//Heap sorting - can only work on a heap
		sort_heap(vec.begin(), vec.end());
		print_vec(vec);
	}
}
