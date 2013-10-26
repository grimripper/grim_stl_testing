#pragma once
#include <iostream>
#include <iomanip>
#include <tuple>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iterator>

void exec00()
{
	using namespace std;
	string s;
	auto x = make_tuple(ref(s));
	get<0>(x) = "hello";

	std::tuple<int,float> t(4,5.5f);
	int y;
	float f;
	std::tie(y,std::ignore) = t;

	cout << y << endl;
	cout << f << endl;
}

void exec01()
{
	using namespace std;

	shared_ptr<string> pNico(new string("nico"), [](string* p) { std::cout << "delete " << *p << std::endl; delete p; });
	shared_ptr<string> pJutta(new string("jutta"));
	shared_ptr<int> p(new int[10], default_delete<int[]>());

	typedef shared_ptr<string> SharedPtrString;

	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	SharedPtrString another = pNico;
	{
		vector<SharedPtrString> v;
		v.push_back(pJutta);
		v.push_back(pJutta);
		v.push_back(pNico);
		v.push_back(pNico);

		cout << "use_count: " << pNico.use_count() << endl;
		v.resize(2);
		cout << "use_count: " << pNico.use_count() << endl;
		pNico = nullptr;
		cout << "use_count: " << pNico.use_count() << endl;
	}

	{
		SharedPtrString another2 = pNico;
		cout << *another << endl;
		cout << "use_count: " << pNico.use_count() << endl;
	}

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << *(v[i]) << endl;
	//}

	//*pNico = "Nicolai";

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << *(v[i]) << endl;
	//}

	cout << "use_count: " << pNico.use_count() << endl;
}

void exec02()
{
	using namespace std;

	try
	{
		shared_ptr<string> sp(new string("hi"));
		weak_ptr<string> wp = sp;
		sp.reset();
		cout << wp.use_count() << endl;
		cout << boolalpha << wp.expired() << endl;
		shared_ptr<string> p(wp);
	}
	catch (const std::exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}

void exec03()
{
	using namespace std;
	cout.setf(ios::showpos | ios::scientific);
	cout << uppercase << 1.5e4 << endl;

	cout << 127 << ' ' << 255 << endl;
	cout << showbase << 127 << ' ' << 255 << endl;
	cout.setf(ios::showbase);
	cout << showbase << hex << 127 << ' ' << 255 << endl;
}

void writeCharSetToFile(const std::string& filename)
{
	using namespace std;

	ofstream file;
	file.open(filename);
	
	if (!file)
	{
		cerr << "Can't open output file" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 32; i < 256; ++i)
	{
		file << "value: " << setw(3) << i << " " << "char: " << static_cast<char>(i) << endl;
	}

	file.close();
}

void outputFile(const std::string& filename)
{
	using namespace std;

	ifstream file;
	file.open(filename);

	if (!file)
	{
		cerr << "Can't open input file" << endl;
		exit(EXIT_FAILURE);
	}

	//char c;
	//while (file.get(c))
	//{
	//	cout.put(c);
	//}
	cout << file.rdbuf();

	//file.close();
}

void exec04()
{
	writeCharSetToFile("charset.out");
	outputFile("charset.out");
}

void exec05()
{
	using namespace std;
	ostringstream os;

	os << "dec: " << 15 << hex << " hex: " << hex << 15;
	cout << os.str() << endl;

	os.seekp(0);

	os << "oct: " << oct << 15;
	cout << os.str() << endl;
}

void exec06()
{
	using namespace std;

	cin.tie(nullptr);
	int x;
	cout << "Please enter a value:" << endl;
	cin >> x;
	cout << "entered:" << x << endl;
}

void hexMultTable(std::streambuf* buffer, int num)
{
	std::ostream hexOut(buffer);
	hexOut << std::hex << std::showbase;

	for (int i = 1; i <= num; ++i)
		for (int j = 1; j <= num; ++j)
			hexOut << i*j << ' ';

	hexOut << std::endl;
}

void exec07()
{
	using namespace std;

	int num = 5;

	cout << "Starting" << endl;
	hexMultTable(cout.rdbuf(), num);
	cout << "Ending" << endl;
}

void exec08()
{
	using namespace std;

	filebuf buffer;
	ostream output(&buffer);
	istream input(&buffer);

	buffer.open("example.dat", ios::in | ios::out | ios::trunc);
	for (int i = 1; i < 4; ++i)
	{
		output << i << ". line" << endl;

		input.seekg(0);
		cout << &buffer << endl;
		input.clear(); // clear eofbit and failbit
	}
}

void exec09()
{
	using namespace std;

	ostreambuf_iterator<char> bufWriter(std::cout.rdbuf());

	string hello("hello, world\n");
	copy(hello.begin(), hello.end(), bufWriter);
}

int exec0()
{
	//exec00();
	//exec01();
	//exec02();
	//exec03();
	//exec04();
	//exec05();
	//exec06();
	//exec07();
	//exec08();
	exec09();

	return 0;
}


