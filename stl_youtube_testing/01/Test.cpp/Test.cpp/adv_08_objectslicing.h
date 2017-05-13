#pragma once

#include <iostream>
#include <deque>
#include "common.h"

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "don't have a name" << endl; }
};

class YellowDog : public Dog
{
	string m_name;
public:
	YellowDog(string name): m_name(name) {}
	void bark() { cout << "have a name: " << m_name << endl; }
};

void foo(Dog& d) {
	d.bark();
}

void run()
{
	deque<Dog> d;
	YellowDog y("Gunner");
	d.push_front(y);
	d[0].bark(); //sliced version of y

	//Use pointer to Dog and polymorphism (virtual)

	Dog d2 = y;
	d2.bark(); //sliced

	foo(y);
}
