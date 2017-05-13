#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include "common.h"

using namespace std;

class Dog {};

void run()
{
	{
		//Drawbacks:
		//1. Expensive reallocation
		//2. Requires contiguous memory

		vector<int> vec = { 2,3,4,5 };
		cout << "vec size: " << vec.size() << " capacity: " << vec.capacity() << endl;
		cout << "vec address: " << &vec[0] << endl;

		vec.push_back(6);
		//capacity = 1.5*capacity
		cout << "vec size: " << vec.size() << " capacity: " << vec.capacity() << endl;
		cout << "vec address: " << &vec[0] << endl;
	}

	{
		vector<Dog> vec(6);
		cout << "vec size: " << vec.size() << " capacity: " << vec.capacity() << endl;

		vector<Dog> vec2;
		cout << "vec2 size: " << vec2.size() << " capacity: " << vec2.capacity() << endl;
		vec2.resize(6); 
		cout << "vec2 size: " << vec2.size() << " capacity: " << vec2.capacity() << endl;

		vector<Dog> vec3;
		vec3.reserve(6); //only increases capacity, not size
		//No Dog's default constructor invoked
		//So, a good idea would be to reserve that amount of memory
		//avoids default constructor and avoids reallocation
		cout << "vec3 size: " << vec3.size() << " capacity: " << vec3.capacity() << endl;
	}

	//Strategy of minimizing reallocation:
	//If max # of items is known, reserve(MAX)
	//If end of grow is known, reserve as much memory as we can, once all data is inserted, trim off the rest
	//shrink_to_fit or vector<int>(c).swap(c);

	{
		//Implementation of deque
		//Deque grows linearly wtih a fixed size

		//No reallocation
		//deque has no reserve() and capacity()

		//Slightly slower than vector
		//-> More complex data structure (slight runtime cost)
		//-> Locality (doesn't sit in contiguous memory -> more cache misses)
	}
	
}
