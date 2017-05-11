#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//ostream& endl(ostream& sm) {
//	sm.put('\n');
//	sm.flush();
//	return sm;
//}

//ostream& ostream::operator << (ostream& (*func)(ostream&))
//{
//	return (*func)(*this);
//}

void run()
{
	{
		//endl: object? built-in datatype? function?
		cout << endl;
		cout << flush;

		//cin >> ws; //read and discard white spaces
		cout << setw(8) << left << setfill('_') << 99 << endl;

		cout << hex << showbase << 14 << endl;
	}
}
