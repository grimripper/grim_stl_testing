// STLTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "STLTesting.h"

#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

namespace STLTesting03
{
	void run()
	{
		int v1Arr[] = { 2,3,4,5,6 };
		vector<int> v1;
		v1.assign(v1Arr, v1Arr + sizeof(v1Arr)/sizeof(int));

		vector<int> v2;
		v2 = v1;
		//v2.assign(v1.begin() + v1.size()/2, v1.end());

		v2.clear();
		//copy(v1.begin() + v1.size()/2, v1.end(), back_inserter(v2));

		//v2.insert(v2.begin(), v1.begin() + v1.size()/2, v1.end());

		copy(v1.begin() + v1.size()/2, v1.end(), inserter(v2, v2.begin()));
	}
}