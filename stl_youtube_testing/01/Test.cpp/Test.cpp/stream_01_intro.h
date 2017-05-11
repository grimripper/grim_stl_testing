#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include <complex>
using namespace std;

void run()
{
	//cout: a global object of ostream (typedef basic_ostream<char> ostream)
	//<<: member function of ostream ostream& ostream::operator<<(string v);
	//endl: '\n' + flush operation

	//What is stream? Serial IO interface to external devices (file, stdin/stdout, network, etc.)
	string s("Hello");
	s[3] = 't'; //random access
	//cout[3] = 't'; //ERROR
	//file provides limited random access. serial starting from a starting point

	{
		ofstream of("MyLog.txt"); //create a new file for write, if the file didn't exist
		of << "Experience is the mother of wisdom" << endl;
		of << 234 << endl;
		of << 2.3 << endl;

		of << bitset<8>(14) << endl;
		of << complex<int>(2, 3) << endl;
	} // RAII

	//IO operation:
	//formatting the data <---> communicating the data with external devices

	//Software engineering principle: Low coupling -> Reusability
} 
