#pragma once

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void cpp_fun(const bool* arr, int size)
{
}

void run()
{
	//Need to push_front a lot? -> Deque
	//Built-in-type? -> vector
	//if not built-in-type -> deque
	//contiguous memort/unpredictable growth/pointer integrity -> deque
	//passed to c -> vector

	{
		//1.ElementType
		//When the elements are not of a trivial type, deque is not much less
		//efficient than vector
		// -> cost of construction and deconstruction dominates perf
	}

	{
		//2. Memory availability
		//Could allocation of large contiguous memory be a problem?
		//- Limited memory size
		//- Large trunk of data
		//- Memory fragmentation
	}

	{
		//3. Frequency of unpredictable growth
		//vector<int> vec;
		//for (;;) vec.push(back)
		//lots of reallocations, assuming growth ratio = 2 or 1.5
		//workaround: reserve() if we have some knowledge
	}

	{
		//4. Invalidation of pointers/references/iterators because of growth
		vector<int> vec = { 2,3,4,5 };
		int* p = &vec[3];
		vec.push_back(6);
		cout << *p << endl; //In release, might still point to 5

		deque<int> deq = { 2,3,4,5 };
		p = &deq[3];
		deq.push_back(6);
		cout << *p << endl; //OK

		//Removing or inserting in the middle still will invalidate
	}

	{
		//5. Vector's unique function: portal to C
		//Cannot do with list / deque?

		vector<bool> vec = { true, true, false, true };
		cpp_fun(&vec[0], vec.size()); //Doesn't compile since it is optimized to be a single bit
		//workaround: use vector<int> or bitset
	}
}
