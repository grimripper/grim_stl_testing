#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include "common.h"

using namespace std;

void run()
{
	{
		vector<int> vec_original = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
		vector<int> vec2_original = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 11 items
		vector<int>::iterator itr, itr2;
		pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;
		vector<int> vec(vec_original);
		vector<int> vec2(vec2_original);
		//copy, move, transform, swap, fill, replace, remove

		//1. copy
		copy(vec.begin(), vec.end(), vec2.begin());
		print_vec(vec2);

		vec = vec_original;
		vec2 = vec2_original;

		copy_if(vec.begin(), vec.end(), vec2.begin(), [](int x) { return x > 80; });
		print_vec(vec2);

		vec = vec_original;
		vec2 = vec2_original;

		copy_n(vec.begin(), 4, vec2.begin());
		print_vec(vec2);

		vec = vec_original;
		vec2 = vec2_original;

		//Strange one
		copy_backward(vec.begin(), vec.end(), vec2.end());
		print_vec(vec2);
	}

	{
		//Move
		vector<string> vec_original = { "apple", "orange", "pear", "grape" };
		vector<string> vec2_original = { "","","","","","" };
		vector<string> vec, vec2;

		vec = vec_original;
		vec2 = vec2_original;

		//If move semantics are defined for the element type, elements are moved over.
		//Otherwise, they are copied over with copy constructor (just like copy)
		move(vec.begin(), vec.end(), vec2.begin());
		print_vec(vec);
		print_vec(vec2);

		vec = vec_original;
		vec2 = vec2_original;

		move_backward(vec.begin(), vec.end(), vec2.end());
		print_vec(vec);
		print_vec(vec2);
	}

	{
		//transform
		vector<int> vec_original = { 9, 60, 70, 8, 45, 87, 90 };
		vector<int> vec2_original(vec_original);
		vector<int> vec3_original = { 0,0,0,0,0,0,0,0,0,0,0 };

		vector<int> vec, vec2, vec3;

		vec = vec_original;
		vec2 = vec2_original;
		vec3 = vec3_original;
		transform(vec.begin(), vec.end(), vec3.begin(), [](int x) {return x - 1; });
		print_vec(vec3);

		vec = vec_original;
		vec2 = vec2_original;
		vec3 = vec3_original;

		transform(vec.begin(), vec.end(), vec2.begin(), vec3.begin(), [](int x, int y) { return x + y; });
		print_vec(vec3);

		vec = vec_original;
		vec2 = { 0,0,0,0,0,0,0 };

		//swap - 2-way copy
		swap_ranges(vec.begin(), vec.end(), vec2.begin());

		print_vec(vec);
		print_vec(vec2);
	}

	{
		//Fill
		vector<int> vec = { 0,0,0,0,0 };

		fill(vec.begin(), vec.end(), 9);
		print_vec(vec);

		vec = { 0,0,0,0,0 };
		fill_n(vec.begin(), 3, 9);
		print_vec(vec);

		vec = { 0,0,0,0,0 };
		generate(vec.begin(), vec.end(), rand);
		print_vec(vec);

		vec = { 0,0,0,0,0 };
		generate_n(vec.begin(), 3, rand);
		print_vec(vec);
	}

	{
		//Replace
		vector<int> vec(5);
		fill(vec.begin(), vec.end(), 6);

		print_vec(vec);
		replace(vec.begin(), vec.end(), 6, 9);
		print_vec(vec);

		fill(vec.begin(), vec.end(), 6);
		vector<int> vec2(6);
		replace_copy(vec.begin(), vec.end(),
			vec2.begin(), 6, 9);
		print_vec(vec);
		print_vec(vec2);

		//generalized versions: replace_if, replace_copy_if
	}

	{
		//remove
		vector<int> vec = { 100, 200, 70 };
		vector<int> vec2(3);
		fill(vec2.begin(), vec2.end(), 0);
		//remove - strange behavior
		remove(vec.begin(), vec.end(), 100);
		cout << vec.size() << endl;
		print_vec(vec);

		//strange behavior
		remove_if(vec.begin(), vec.end(), [](int x) {return x > 80; });
		cout << vec.size() << endl;
		print_vec(vec);

		//strange behavior
		remove_copy(vec.begin(), vec.end(), vec2.begin(), 100);
		print_vec(vec);
		print_vec(vec2);
	}

	{
		//unique - strange behaviors
		vector<int> vec{ 1,2,3,4,5,5,5 };

		unique(vec.begin(), vec.end());
		print_vec(vec);

		vec = { 1,2,3,4,5,5,5 };
		unique(vec.begin(), vec.end(), less<int>());
		print_vec(vec);

		vector<int> vec2(10);
		fill(vec2.begin(), vec2.end(), 0);
		unique_copy(vec.begin(), vec.end(), vec2.begin());
	}

	//Order-changing algorithms: reverse, rotate, permute, shuffle
	{
		vector<int> vec = { 9, 60, 7,10 };
		reverse(vec.begin(), vec.end());
		print_vec(vec);

		vec = { 9, 60, 7, 10 };
		reverse(vec.begin() + 1, vec.end() - 1);
		print_vec(vec);

		//reverse_copy
		//rotate
		//rotate_copy
	}

	{
		vector<int> vec{ 1,2,3,4 };

		for (int i = 0; i < 5; ++i)
		{
			//next lexicographically greater permutation
			next_permutation(vec.begin(), vec.end());
			print_vec(vec);
		}

		//prev_permutation
	}

	{
		//shuffle - swap each element with a randomly selected element
		vector<int> vec{ 10,20,30,40 };

		random_shuffle(vec.begin(), vec.end());
		print_vec(vec);

		//random_shuffle(vec.begin(), vec.end(), rand);
		//print_vec(vec);

		//Better random number generation
		shuffle(vec.begin(), vec.end(), default_random_engine());
		print_vec(vec);
	}
}
