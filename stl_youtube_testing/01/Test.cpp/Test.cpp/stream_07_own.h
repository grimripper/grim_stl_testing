#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Dog {
	int age_;
	string name_;
};

ostream& operator<<(ostream& sm, const Dog& dog) {
	sm << dog.age_ << " " << dog.name_;
	return sm;
}

istream& operator >> (istream& sm, Dog& d) {
	sm >> d.age_;
	sm >> d.name_;
	return sm;
}

void run()
{
	Dog d;
	d.age_ = 5;
	d.name_ = "h";

	cout << d;
}