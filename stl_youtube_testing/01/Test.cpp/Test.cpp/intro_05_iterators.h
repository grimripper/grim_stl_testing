#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <set>

bool isOdd(int i) {
	return i % 2;
}

void run()
{
    using namespace std;

	//Random access iterator - vector, deque, array
	//vector<int>::iterator itr;
	//itr = itr + 5;
	//itr = itr - 4;
	//++itr; //faster than itr
	//--itr; 

	//Bidirectional iterator: list, set, multiset, map, multimap
	//list<int>::iterator itr2;
	//++itr2;
	//--itr2;

	//Forward iterator only
	//forward_list<int>::iterator itr3;
	//++itr3;

	//Unordered containers provide "at least" forward iterators
	//Have the option to provide bidirectional

	//Input iterator (read only) - can only move forward 
	//subset of forward iterator
	//int x = *itr;

	//Output iterator (write only) - can only move forward
	//subset of forward iterator
	//*itr = 100;

	//iterator
	//const_iterator for all containers

	//Only in C++11
	{
		set<int>::const_iterator citr;
		set<int> set2 = { 1,2,3 };

		for (citr = set2.cbegin(); citr != set2.cend(); ++citr)
		{
			cout << *citr << " ";
		}
		cout << endl;

		vector<int> v{ 1,2,3,4 };
		for_each(v.begin(), v.end(), [](int& i) {++i; });
		for_each(v.cbegin(), v.cend(), [](const int& i) {cout << i << " "; });
		cout << endl;

		auto it = v.begin();
		advance(it, 4);
		cout << distance(it, v.begin()) << endl; //-ve distance
		cout << distance(v.begin(), it) << endl; //+ve distance

		//For set, can only read even if you use .end() (not modify)
		for_each(set2.cbegin(), set2.cend(), [](const int& i) {cout << i << " "; });
		cout << endl;
	}

	//Iterator adaptor (Predefined iterator)
	//1. Insert iterator

	{
		vector<int> v1{ 4,5 };
		deque<int> v2{ 12,14,16,18 };
		deque<int>::iterator it2 = find(v2.begin(), v2.end(), 16);
		insert_iterator<deque<int>> i_itr1(v2, it2);
		front_insert_iterator<deque<int>> i_itr2(v2);
		//Other insert iterators: back_insert_iterator, front_insert_iterator

		//copy(v1.begin(), v1.end(), i_itr1);
		copy(v1.begin(), v1.end(), i_itr2);

		for_each(v2.cbegin(), v2.cend(), [](const int& i) {cout << i << " "; });
		cout << endl;
	}

	//2. Stream iterator - to iterate to/from stream - don't work
	{
		vector<string> v4{ "hello", "bye", "good" };
		//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v4));

		//copy(v4.begin(), v4.end(), ostream_iterator<string>(cout, " "));
		//copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));
	}
	//3. Reverse iterator
	{
		vector<int> v5{ 4,5,6,7 };
		reverse_iterator<vector<int>::iterator> ritr;
		for (ritr = v5.rbegin(); ritr != v5.rend(); ritr++)
			cout << *ritr << endl;
	}
	//4. Move iterator (C++11)
	{
	}


	//ALGORITHMS - Mostly loops
	//If you have loops -> replace with std::algorithm::*
	{
		vector<int> vec = { 3,3,2,5,6,4,5,6,7 };
		vector<int>::iterator it = min_element(vec.begin(), vec.end());
		cout << *it << endl;

		//NOTE 1: Algorithms always process ranges in a half-open way
		sort(vec.begin(), it+1); //2 3 3
		reverse(it+1, vec.end()); //2 3 3 7 6 5 4 6 5
		//now it points to the old location

		//NOTE 2: sometimes the function needs 2 ranges of data
		vector<int> vec2(3);
		it = find(vec.begin(), vec.end(), 4); 
		copy(it + 1, vec.end(), vec2.begin()); //vec2 should have at least 2 elements
		//STL sacrifices safety here sometimes
	}

	{
		//NOTE 3:
		//To overcome safety issue, provide back_inserter
		vector<int> vec{ 1,2,3 };
		vector<int> vec3;
		copy(vec.begin(), vec.end(), back_inserter(vec3));

		//safe, but not efficient

		//to get efficient and safe
		vec3.insert(vec3.end(), vec.begin(), vec.end());
	}

	{
		//NOTE 4: Algorithm with function
		vector<int> vec = { 2,4,5,9,2 };
		vector<int>::iterator it = find_if(vec.begin(), vec.end(), isOdd);
		cout << "Odd one: " << *it << endl;
	}

	{
		//NOTE 5: Algorithm with native C++ array
		int arr[4] = { 6,3,7,4 };
		sort(arr, arr + 4); //works because a pointer can be thought of as an iterator
	}


}

