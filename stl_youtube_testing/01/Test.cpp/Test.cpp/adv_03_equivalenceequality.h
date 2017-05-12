#pragma once

#include <iostream>
#include <set>

using namespace std;

class Lsb_less {
public:
	bool operator()(int x, int y) {
		return (x % 10) < (y % 10);
	}
};


void run()
{
	set<int, Lsb_less> s = { 21, 23, 26, 27 };
	set<int, Lsb_less>::iterator itr1, itr2;

	//didn't compile
	//itr1 = find(s.begin(), s.end(), 36); // looks for equality if (x == y)
	//cout << distance(s.begin(), itr1) << endl;

	//itr2 = s.find(36); //would find 26 // looks for equivalence if (!(x<y) && !(y<x))
	//cout << distance(s.begin(), itr2) << endl;

	//Algorithms of equality (doesn't require data to be sorted typically):
	//search
	//find_end
	//find_first_of
	//adjacent_search

	//Algorithms of equivalence (typically algo works with sorted data or a member function of a container with sorted data such as an associated container)
	//binary_search
	//includes
	//lower_bound
	//upper_bound
}
