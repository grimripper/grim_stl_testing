#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <iterator>

class X
{
public:
	void operator()(std::string str)
	{
		std::cout << str << std::endl;
	}
	//NOTE: the following is a type conversion
	//operator std::string() const { return "X"; }
};

class X2
{
public:
	X2(int i) {}
	void operator()(std::string x)
	{
	}
};

//If ok to do at compile time
template <int val>
void add2(int i)
{
	using namespace std;
	cout << i + val << endl;
}

void addval(int i, int val)
{
	using namespace std;
	cout << i + val << endl;
}

class AddVal {
	int _j;
public:
	AddVal(int j) : _j(j) {}
	void operator()(int i) {
		using namespace std;
		cout << i + _j << endl;
	}
};

double Pow(double x, double y)
{
	return pow(x, y);
}

class lsb_less
{
public:
	bool operator()(int x, int y)
	{
		return (x % 10) < (y % 10);
	}
};

class NeedCopy
{
public:
	bool operator()(int x)
	{
		return (x > 20) || (x < 5);
	}
};

void run()
{
	using namespace std;
	{
		X foo;
		foo("hello"); //calling functor X with parameter hello
		//it 'behaves' like a function

		//Benefits of functor:
		//1. Smart function: capabilities beyond operator(). It can remember state
		//2. It can have its own type

		//Parameterized function
		//Why do this instead of take a function that takes 2 params
		//Allows us to use in std::algorithms
		X2(5)("hello");

		vector<int> vec = { 2,3,4,5 };
		for_each(vec.begin(), vec.end(), add2<5>);

		//Functors provide max flexibility
		int x = 5;
		for_each(vec.begin(), vec.end(), AddVal(x));

		//Can also use 'bind'
		for_each(vec.begin(), vec.end(), bind(addval, placeholders::_1, x));

		//Built-in functors
		//less, greater, greater_equal, less_equal, not_equal_to
		//logical_and, logical_not, logical_or
		//multiples, minus, plus, divide, modulus, negate

		x = multiplies<int>()(5, 6);
		cout << x << endl;

		if (not_equal_to<int>()(5, 6))
		{
			cout << "not same" << endl;
		}
	}

	{
		//Parameter binding
		set<int> myset{ 2,3,4,5 };
		vector<int> vec;

		transform(myset.begin(), myset.end(), back_inserter(vec),
			bind(multiplies<int>(), placeholders::_1, 10));
		//vec = {20,30,40,50}

		vector<int> d;
		auto f = function<double(double, double)>(Pow); //c++11 only
		transform(myset.begin(), myset.end(), back_inserter(d),
			bind(f, placeholders::_1, 2));

		set<int> myset2 = { 3,1,25,7,12 };
		//when (x > 20) || (x < 5)
		vector<int> d2;

		////Possible, but nasty
		//transform(myset2.begin(), myset2.end(), back_inserter(d2),
		//	bind(logical_or<bool>(),
		//		bind(greater<int>(), placeholders::_1, 20),
		//		bind(less<int>(), placeholders::_1, 5))
		//);

		transform(myset2.begin(), myset2.end(), back_inserter(d2),
			[](int x) { return (x > 20) || (x < 5); });
	}

	{
		//Why do we need functor in STL?
		set<int> myset1{ 13,1, 5 };
		set<int, greater<int>> myset2{ 13,1,5 };
		set<int, lsb_less> myset3{ 13, 1, 5 };
		for_each(myset1.begin(), myset1.end(), [](const int& n) {cout << n << " "; });
		cout << endl;
		for_each(myset2.begin(), myset2.end(), [](const int& n) {cout << n << " "; });
		cout << endl;
		for_each(myset3.begin(), myset3.end(), [](const int& n) {cout << n << " "; });
		cout << endl;
	}

	{
		//Predicate
		//Functor that returns boolean and does not modify data (pass by value)
		//Used for comparison or condition check
		set<int> myset1{ 13,1, 5 };
		vector<int> v;
		transform(myset1.begin(), myset1.end(), back_inserter(v),
			NeedCopy());
	}
}
