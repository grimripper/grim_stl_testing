#pragma once

#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;

void run()
{
	{
		//containers v/s algorithms
		//are there dupe functions? yes

		//List dupes
		//remove(const T), <T>remove_if
		//unique()
		//sort
		//merge
		//reverse

		//Associative container
		//count
		//find
		//lower_bound
		//upper_bound
		//equal_range

		//Unordered container
		//count
		//find
		//equal_range

		//Even though there are dupes, they are different
	}
	{
		unordered_set<int> s = { 1,2,3,4,5,6 };
		auto it = s.find(4); // O(1)
		it = find(s.begin(), s.end(), 4); //O(n)

		//map<char, string> mymap = {};
		//mymap.find(); // O(log(n))
		//find(mymap.begin(), mymap.end(), make_pair('F', "Friday")); //O(n)

		//list.remove // O(n) --> more efficient implementation (linked list)
		//s:{2,1,8,5,9}
		//itr = remove()// O(n) --> bad since it does copying linear number of times (assumes it is an array)
		//s:{2,1,8,5,9,9} --> user has to explicitly remove it
		//s.erase(itr, s.end());

		//Sort
		//s.sort(); 
		//sort(s.begin(), s.end()); // undefined behavior since it needs random-access iterators

		//Prefer member functions over algorithm functions
	}
}
