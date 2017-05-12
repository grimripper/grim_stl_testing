#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include "common.h"

using namespace std;

void run()
{
	//reverse_iterator<vector<int>::iterator> ritr;
	//vector<int>::reverse_iterator ritr;

	//rbegin() -> rend()

	//I can convert itr->ritr, but not ritr->itr

	//itr = ritr.base();

	//if ritr=n, then ritr.base() = n+1

	vector<int> vec = { 1,2,3,4,5 };
	auto ritr = find(vec.rbegin(), vec.rend(), 3);

	//vec.insert(ritr, 9); // would print the same thing if it worked
	//print_vec(vec);

	//NOTE: after inserting/erasing a vec, iterators/pointers/references become invalidated

	vec = { 1,2,3,4,5 };
	vec.insert(ritr.base(), 9);
	print_vec(vec);

	//vec.erase(ritr);
	vec = { 1,2,3,4,5 };
	ritr = find(vec.rbegin(), vec.rend(), 3);
	vec.erase(ritr.base()); //if you just do vec.erase(ritr), it would have been {1,2,4,5}
	print_vec(vec);
}
