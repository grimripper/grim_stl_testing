#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include "common.h"

using namespace std;

//Sequence container, unordered container -> it = c.erase(it)
//Associative container -> c.erase(it++)

bool equalVal(int e, int val) {
	if (e == val) {
		cout << e << " will be removed" << endl;
		return true;
	}
	return false;
}

void run()
{
	{
		multiset<int> c = { 1,4,6,1,1,1,1,12,18,16 };
		for (multiset<int>::iterator it = c.begin(); it != c.end(); )
		{
			if (*it == 1)
			{
				cout << "Erasing one item of " << *it << endl;
				//hmmmm
				//need to return the next iterator, itr itself is invalidated
				c.erase(it++); 
			}
			else
			{
				it++;
			}
		}

		print(c, "after");
	}

	{
		vector<int> c = { 1,4,6,1,1,1,1,12,18,16 };
		for (vector<int>::iterator it = c.begin(); it != c.end(); )
		{
			if (*it == 1)
			{
				cout << "Erasing one item of " << *it << endl;
				//For a vector, as soon as you erase,
				//everything after the current element is invalidated
				//c.erase(it++);
				it = c.erase(it);
			}
			else
			{
				it++;
			}
		}

		print(c, "after");
	}

	{
		vector<int> c = { 1,4,6,1,1,1,1,12,18,16 };
		auto it = remove_if(c.begin(), c.end(), bind(equalVal, placeholders::_1, 1));
		//or lambda function
		c.erase(it, c.end());
		print(c, "new");
	}
}
