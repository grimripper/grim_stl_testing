#pragma once
#include <iostream>

using namespace std;

int exec20()
{
	int values[] { 1, 2, 3, 4 };
	int j{};
	int k;
	int *p1{};
	int *p2;
	cout << values[0] << endl;
	cout << j << endl;
	cout << k << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	return 0;
}

void print(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p)
	{
		cout << *p << endl;
	}
}

int exec21()
{
	print({ 1, 2, 3, 4, 5 });
	return 0;
}

class P
{
public:
	P(int, int)
	{
		cout << "called arg constructor" << endl;
	}

	explicit P(std::initializer_list<int> vals)
	{
		cout << "called IL constructor" << endl;
	}
};

int exec22()
{
	P p(1, 2);
	P q{ 1, 2 };
	P r = { 2, 3 }; //calls arg constructor
	//P z = { 1, 2, 3 }; // "copy-list-initialization not allowed because explicit"
	return 0;
}

template<typename T>
void print(const std::vector<T>& vec)
{
	for (const auto &elem : vec)
	{
		cout << elem << ",";
	}
	cout << endl;
}

class C
{
	string m_s;
public:
	C() {}
	explicit C(const std::string& s) { m_s = s; }
	void print()
	{
		cout << m_s << endl;
	}
};

int exec23()
{
	vector<double> vec{ 1.1, 2.2, 3.3 };

	print(vec);
	for (auto &elem : vec) // works on the elements
	{
		elem *= 3;
	}
	print(vec);
	for (auto elem : vec) // works on a local copy of elements
	{
		elem *= 3;
	}
	print(vec);
	return 0;
}

// Move semantics
class A
{
public:
	int* arr;
	int len;
	A(const std::vector<int>& inp)
	{
		len = inp.size();
		arr = new int[len];
		for (int i = 0; i < len; ++i)
		{
			arr[i] = inp[i];
		}
	}
	A(const A& other)
	{
		(void)operator=(other);
	}
	A& operator=(const A& other)
	{
		if (this != &other)
		{
			len = other.len;
			arr = new int[other.len];
			for (int i = 0; i < len; ++i)
			{
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}
	A(A&& other)
	{
		(void)operator=(std::move(other));
	}
	A& operator=(A&& other)
	{
		if (this != &other)
		{
			len = other.len;
			arr = other.arr;
			other.len = 0;
			other.arr = nullptr;
			return *this;
		}
	}
};

int exec24()
{
	auto v = std::vector<int>{ 1, 2, 3 };
	A a(v);
	A b(a);
	A c = a;
	A d(std::move(a));
	return 0;
}

int exec25()
{
	static char *x = R"(Hello 
howdy)";

	static char* y = R"hsdkfhsdjkf(oye oye kapde dhoein)hsdkfhsdjkf";

	//const char* z = R"(hello bhai)";
	//char16_t* z1 = u"Hello sirji!";
	//char32_t* z2 = U"Hello sir!";
	wchar_t* z3 = LR"(hello siree)";

	cout << x << endl;
	cout << y << endl;
	//cout << z << endl;
	//cout << z1 << endl;
	//cout << z2 << endl;
	cout << z3 << endl;

	return 0;
}

int exec26()
{

	return 0;
}

int exec2()
{
	//exec20();
	//exec21();
	//exec22();
	//exec23();
	//exec24();
	//exec25();
	exec26();
	return 0;
}
