#pragma once
#include <thread>
#include <string>
#include <iostream>

using namespace std;

void threadCallback(const int& x, string str)
{
	int& y = const_cast<int&>(x);
	++y;
	cout << x << " " << str << endl;
}

void run()
{
	int x = 10;
	string str = "he";
	thread tObj(threadCallback, std::ref(x), str);
	//cout << "start" << endl;
	//chrono::milliseconds dura(1000);
	//chrono::high_resolution_clock::time_point p;
	//this_thread::sleep_for(dura);
	//auto d = chrono::high_resolution_clock::now() - p;
	//cout << chrono::duration_cast<chrono::milliseconds>(d).count() << endl;
	//cout << "stop (1s later)" << endl;
	tObj.join();
	cout << x << endl;
}
