#pragma once
#include <iostream>
#include <iterator>
#include <streambuf>
#include <locale>
#include <cstdio>

void exec10()
{
	using namespace std;

	istreambuf_iterator<char> inpos(cin);
	ostreambuf_iterator<char> outpos(cout);
	istreambuf_iterator<char> endpos;

	while (inpos != endpos)
	{
		*outpos++ = *inpos++;
	}
}

template <typename charT, 
	typename traits = std::char_traits<charT> >
class basic_outbuf : public std::basic_streambuf<charT,traits>
{
protected:
	virtual typename traits::int_type overflow(typename traits::int_type c)
	{
		if (!traits::eq_int_type(c, traits::eof()))
		{
			c = std::toupper(c, this->getloc());

			char cc = std::use_facet<std::ctype<charT>>(this->getloc()).narrow(c, '?');

			if (std::putchar(cc) == EOF)
			{
				return traits::eof();
			}
		}
		return traits::not_eof(c);
	}
};


typedef basic_outbuf<char> outbuf;
typedef basic_outbuf<wchar_t> woutbuf;

void exec11()
{
	using namespace std;
	outbuf ob;
	std::ostream out(&ob);

	out << "31 hex: " << std::hex << 31 << endl;
}

void exec12()
{
	using namespace std;

	cout << cin.rdbuf();

	cout << "Fail: " << (cin.flags() & ios::failbit) << endl;
	cout << "EOF: " << (cin.flags() & ios::eofbit) << endl;
}

int exec1()
{
	//exec10();
	//exec11();
	exec12();
	//exec13();
	//exec14();
	//exec15();
	//exec16();
	//exec17();
	//exec18();
	//exec19();

	return 0;
}


