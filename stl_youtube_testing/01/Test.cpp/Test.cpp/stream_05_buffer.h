#pragma once

#include <iostream>
#include <fstream>

using namespace std;

void run()
{
	{
		//IO operation
		//formatting data --stream
		//communicating data to ext devices --stream buffer

		cout << 34 << endl;
		streambuf* pbuf = cout.rdbuf();

		ostream myCout(pbuf);
		myCout << 35 << endl;

		myCout.setf(ios::showpos);
		myCout.width(20);
		myCout << 36 << endl;
		cout << 36 << endl; //shows that formatting is handled by the stream, not stream buf
	}

	{
		ofstream of("MyLog.txt");
		streambuf* pbuf = cout.rdbuf();
		cout.rdbuf(of.rdbuf()); // Redirecting -> assigning streambuf of of -> cout.rdbuf

		cout << "Hello" << endl;
		cout.rdbuf(pbuf);

		cout << "Goodbye" << endl;
	}

	{
		//stream buffer iterator
		istreambuf_iterator<char> i(cin);
		ostreambuf_iterator<char> o(cout);

		while (*i != 'x') {
			*o = *i;
			++o;
			++i;
		}

		copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
		//End with Ctrl-Z
	}
}
