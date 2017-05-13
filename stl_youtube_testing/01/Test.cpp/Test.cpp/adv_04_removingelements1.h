#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include "common.h"

using namespace std;

void run()
{
	{
		vector<int> c = { 1,4,6,1,1,1,1,12,18,16 };
		print(c, "Original:");

		for (vector<int>::iterator itr = c.begin(); itr != c.end(); )
		{
			if (*itr == 1) {
				itr = c.erase(itr);
			}
			else {
				itr++;
			}
		} // Complexity: O(n*m) //m is the number of 1's
		print(c, "New:");

		c = { 1,4,6,1,1,1,1,12,18,16 };
		//remove(c.begin(), c.end(), 1); //Complexity = O(n)
		//remove doesn't know about vector layout, it simply
		//moves non-removed elements to the front
		auto it = remove(c.begin(), c.end(), 1);
		c.erase(it, c.end());
		print(c, "After remove()");

		//What is the capacity?
		cout << c.capacity() << endl;

		c.shrink_to_fit(); //if you really need to
		cout << c.capacity() << endl;
	}

	{
		list<int> c = { 1,4,6,1,1,1,1,12,18,16 };
		print(c, "Original:");

		auto it = remove(c.begin(), c.end(), 1);
		c.erase(it, c.end());
		print(c, "after erase()");

		c = { 1,4,6,1,1,1,1,12,18,16 };
		c.remove(1);
		print(c, "after remove()"); //FASTER, EASIER, CLEANER
	}

	{
		multiset<int> c = { 1,4,6,1,1,1,1,12,18,16 };

		//Doesn't compile?
		//auto it = remove(c.begin(), c.end(), 1);
		//c.erase(it, c.end()); 
		//print(c, "after erase");

		c.erase(1); //O(log n)
		print(c, "");
	}
}
