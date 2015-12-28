#pragma once

#include <unordered_set>
#include <unordered_map>
#include <string>

void foo(const std::unordered_map<char, std::string>& m)
{
    //m['S'] = "SUNDAY"; // won't compile
    //std::cout << m['S'] << std::endl; // also won't compile since it provides write access
    // the only way this can work:
    auto itr = m.find('S');
    if (itr != m.end())
        std::cout << itr->first << " " << itr->second << std::endl;
}

// New in C++ 11
void n04_unorderedcontainers()
{
    using namespace std;

    // Unordered set/multiset or map/multimap
    // Internally implemented as a hash table

    unordered_set<string> myset = { "red", "green", "blue" };
    unordered_set<string>::const_iterator it = myset.find("green"); // O(1) amortized
    if (it != myset.end())
        cout << *it << endl;
    myset.insert("yellow");//O(1)

    for (auto it2 : myset) cout << it2 << " "; cout << endl;

    vector<string> vec = { "purple", "pink", "violet", "mauve", "beige" };
    myset.insert(vec.begin(), vec.end());
    for (auto it2 : myset) cout << it2 << " "; cout << endl;

    //Hash-table specific APIs
    cout << "load_factor = " << myset.load_factor() << endl;
    string x = "red";
    cout << x << " is in bucket #" << myset.bucket(x) << endl;

    cout << "Total bucket #" << myset.bucket_count() << endl;

    // unordered multiset: allows duplicated elements
    // unordered map: unordered set of pairs
    // unordered multimap: unordered map that allows dupe keys

    // hash collision => performance degrade

    // Properties:
    // 1. Fastest search and insert O(1)
    // 2. Element value or key cannot be changed because it corrupts the data structure

    // Associative array can be implemented as a map/unordered map
    unordered_map<char, string> day = { { 'S', "Sunday" }, { 'M', "Monday" } };
    for (auto it3 : day) cout << it3.first << "=>" << it3.second << " "; cout << endl;

    cout << day['S'] << endl; // no range check
    cout << day.at('S') << endl; // has range check

    vector<int> vec2 = { 1, 2, 3 };
    //vec2[5] = 5; // compile error should happen, but doesn't.

    day['W'] = "Wednesday"; // inserting {'W', "Wednesday"}
    day.insert(make_pair('F', "Friday"));
    for (auto it3 : day) cout << it3.first << "=>" << it3.second << " "; cout << endl;

    auto it4 = day.insert(make_pair('M', "MONDAY")); // Fails to modifys
    cout << "Succeeded to modify: " << it4.second << endl;

    for (auto it3 : day) cout << it3.first << "=>" << it3.second << " "; cout << endl;
    day['M'] = "MONDAY"; //Succeeds because it provides write access to the container
    for (auto it3 : day) cout << it3.first << "=>" << it3.second << " "; cout << endl;

    foo(day);

    //Properties for Associative array:
    //1. Search time: unordered_map, O(1): map, O(log(n)): map better for real-time system because it provides guarantees
    //2. Unordered_map: may degrade to O(n)
    //3. Can't use multimap and unordered_multimap, they don't have [] operator

    //Container Adaptor
    // - Provide a restricted interface to meet special needs
    // - Implemented with fundamental container classes
    //  1. stack: LIFO, push(), pop(), top()
    //  2. queue: FIFO, push(), pop(), front(), back()
    //  3. priority queue: (only guarantee is that first item has a higher pri) push(), pop(), top()

    // Array-based containers: vector, dequeu
    //  Node based containers: list + assoc + unordered
    // Array-based containers invalidates pointers:
    //  - Native pointers, iterators, references

    vector<int> vec_test = { 1, 2, 3, 4 };
    int* p = &vec_test[2]; // points to 3
    vec_test.insert(vec_test.begin(), 0);
    cout << *p << endl; // can point to 2 or garbage or crash - undefined behavior
}

