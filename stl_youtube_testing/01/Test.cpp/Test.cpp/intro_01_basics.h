#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

void run()
{
    using namespace std;

    vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    vector<int>::iterator itr1 = vec.begin(); // half-open: [begin, end)
    vector<int>::iterator itr2 = vec.end();

    // cout << *vec.end() << endl; //undefined.

    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

	cout << std::distance(itr1, itr2) << endl;
	cout << vec.size() << endl;
    sort(itr1, itr2);

    for (vector<int>::const_iterator itr = itr1; itr != itr2; ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
