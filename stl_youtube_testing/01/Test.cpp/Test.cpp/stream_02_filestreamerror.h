#pragma once

#include <iostream>
#include <fstream>

using namespace std;

void run()
{
	{
		//ofstream of("MyLog.txt"); //Open the file for write, clear contents of the file
		ofstream of("MyLog.txt", ofstream::app);
		of << "Honesty" << endl;
	}

	{
		ofstream of("MyLog.txt", ofstream::in | ofstream::out);
		of.seekp(10, ios::beg); //Move the output pointer 10 + beg
		of << "12345"; //overwrite 5 characters
		of.seekp(-5, ios::end); //Move output pointer to end - 5
		of << "12345";
		of.seekp(-5, ios::cur);
		of << "54321";
	}

	{
		ifstream inf("MyLog.txt");
		int i;
		inf >> i; //read one word
		//Error status: goodbit, badbit, failbit, eofbit
		cout << inf.good() << endl;  //good
		cout << inf.bad() << endl; //non-recoverable
		cout << inf.fail() << endl; // failed stream op
		cout << inf.eof() << endl; // eof happened

		inf.clear(ios::badbit); //to clear all error status (Sets badbit to 1)
		//inf.clear(); // same as inf.clear(ios::goodbit)

		cout << inf.good() << endl;  //good
		cout << inf.bad() << endl; //non-recoverable
		cout << inf.fail() << endl; // failed stream op
		cout << inf.eof() << endl; // eof happened
								   //cout << i;

		cout << inf.rdstate() << endl; // reads the current status flag
		inf.clear(inf.rdstate() & ~ios::failbit);
		//cout << inf.rdstate() << endl; // reads the current status flag

		if (inf)
		{
			cout << "Read successfully";
		}

		if (inf >> i)
		{
			cout << "Read successfully";
		}

		//Can also handle errors with exceptions
		//inf.exceptions(ios::badbit | ios::failbit); //setting the exception mask
		//When badbit or failbit set to 1, exception of ios::failure will be thrown
		//When eofbit set to 1, no exception is thrown

		inf.exceptions(ios::goodbit);
		// Means no exception will be generated
	}
}