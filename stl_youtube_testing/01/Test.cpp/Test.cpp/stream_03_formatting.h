#pragma once

#include <fstream>
#include <iomanip>

using namespace std;

void run()
{
	{
		cout << 34 << endl;
		cout.setf(ios::oct, ios::basefield);
		cout << 34 << endl;

		cout.setf(ios::showbase);
		cout << 34 << endl;

		cout.setf(ios::hex, ios::basefield);
		cout << 34 << endl;

		cout.unsetf(ios::showbase);
		cout << 34 << endl;

		cout.setf(ios::dec, ios::basefield);

		cout.width(10);
		cout << 26 << endl;

		cout.setf(ios::left, ios::adjustfield);
		cout << 26 << endl;
	}

	{
		//Floating point value
		cout.setf(ios::scientific, ios::floatfield);
		cout << 340.1 << endl;
		cout.setf(ios::fixed, ios::floatfield);
		cout << 340.1 << endl;
		cout.precision(3);
		cout << 340.1 << endl;
	}

	{
		int i;
		//cin.setf(ios::hex, ios::basefield);
		//cin >> i;
	}

	{
		ios::fmtflags f = cout.flags();
		cout << f << endl;
		cout.flags(ios::oct | ios::showbase);
	}

	{
		//Member functions for unformatted IO
		//input
		ifstream inf("MyLog.txt");
		char buf[80];
		inf.get(buf, 80); //read up to 80 characters
		inf.getline(buf, 80); //read up to 80 characters or until '\n'
		inf.read(buf, 20); //read 20 chars
		inf.ignore(3); //ignore next 3 characters
		inf.peek(); //return character
		inf.unget(); //return a char back to the stream! no param -> always puts back same character
		inf.putback('z'); //will put back a specific character
		inf.get();
		inf.gcount(); //return the number of chars being read by last unformatted read
		//for get(), it was 1, so it would be 1.
	}

	{
		ofstream of("MyLog.txt");
		char buf[80];
		fill(buf, buf+80, '0');
		of.put('c');
		of.write(buf, 6); //write first 6 chars of buf into stream
		of.flush(); //will flush the output
	}
}
