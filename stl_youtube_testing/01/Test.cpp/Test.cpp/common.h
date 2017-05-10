#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print_vec(const vector<T>& vec)
{
	for (auto it : vec) {
		cout << it << " ";
	}
	cout << endl;
}

template <>
void print_vec(const vector<string>& vec)
{
	for (auto it : vec) {
		cout << "'" << it << "' ";
	}
	cout << endl;
}
