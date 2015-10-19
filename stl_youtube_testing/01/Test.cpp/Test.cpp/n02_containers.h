#pragma once

#include <vector>
#include <deque>
#include <list>
#include <set> // set, multiset
#include <map>  //map, multimap
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric> //some numeric algorithm
#include <functional> // for functors

#include <iostream>

void n02_containers()
{
    using namespace std;

    vector<int> vec; //vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    cout << vec[2] << endl; // 8 (no range check)
    cout << vec.at(2) << endl; // range_error exception if out of range.

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it2 : vec)
        cout << it2 << " ";
    cout << endl;

    //Vector is a dynamically allocated contiguous array in memory
    int *ptr = &vec[0];
    cout << *ptr << endl;
    cout << *(ptr+1) << endl;
    cout << *(ptr+2) << endl;

    if (vec.empty()) { cout << "Not possible\n" << endl; }
    cout << vec.size() << endl;

    vector<int> vec2(vec);
    vec.clear(); // remove all items in vec, vec.size() == 0

    for (auto it3 : vec2)
        cout << it3 << " ";

    vec2.swap(vec); //vec2 becomes empty, and vec has 3 items. 
    for (auto it3 : vec2)
        cout << it3 << " ";

    // Notes: No penalty of abstraction, very efficient (all the penalty has been abstracted away)

    //Properties of vector:
    // 1. Fast insert/remove at the end: O(1)
    // 2. Slow insert/remove at beginning/middle: O(n)
    // 3. Slow search: O(n)
    
    deque<int> deq = { 4, 6, 7 };
    for (auto it : deq)
        cout << it << " ";
    cout << endl;
    deq.push_front(2); // 2,4,6,7
    for (auto it : deq)
        cout << it << " ";
    cout << endl;
    deq.push_back(3);  // 2,4,6,7,3
    for (auto it : deq)
        cout << it << " ";
    cout << endl;

    cout << deq[1]; // 4, similar properties as vector

    // Properties of deque:
    //  1. Fast insert/remove at beginning/end
    //  2. Slow insert/remove in the middle: O(n)
    //  3. Slow search: O(n)

    // NOTE: deque is not contiguous




}
