#pragma once

#include <map>
#include <set>

void run()
{
    using namespace std;

    set<int> myset;
    myset.insert(3); //{3}
    myset.insert(1); //{1,3}
    myset.insert(7); //{1,3,7} 0(log(n))
    for (auto it : myset) cout << it << " "; cout << endl;

    set<int>::iterator it;
    it = myset.find(7); // O(log(n))
    //NOTE: sequence containers don't even have find()
    //member funcions since it takes too long to find

    pair<set<int>::iterator, bool> ret;
    ret = myset.insert(3);
    if (ret.second == false) // no new element inserted
        it = ret.first;

    myset.insert(it, 9); // O(1) if you provide a good hint, otherwise still takes O(log(n))
    for (auto it : myset) cout << it << " "; cout << endl;
    myset.erase(it); // removes 3
    for (auto it : myset) cout << it << " "; cout << endl;
    myset.erase(7);
    for (auto it : myset) cout << it << " "; cout << endl;
    // None of the sequence containers provide this kind of erase (too slow)

    // value of the elements cannot be modified
    // read-only (because they may not be sorted anymore)

    multiset<int> mymultiset; // set that allows duplicate items

    //Properties:
    //1. Fast search: O(log(n))
    //2. Traversing is slow (compared to vector & deque)
    //3. No random access, no [] operator

    //If you want key/value, then use map/multimap
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(make_pair('z', 200)); // infer from parameter types
    cout << "map:" << endl;
    for (auto it : mymap)
        cout << it.first << "=>" << it.second << endl;

    map<char, int>::iterator it2 = mymap.begin();
    mymap.insert(it2, pair<char, int>('b', 300)); // 'it' is a hint
    it2 = mymap.find('z');

    for (auto it : mymap)
        cout << it.first << "=>" << it.second << endl;

    //multimap is a map that allows duplicate keys
    multimap<char, int> mymultimap;

    // Properties:
    // 1. keys cannot be modified
    // 2. type of (*it) is pair<const char,int>
}
