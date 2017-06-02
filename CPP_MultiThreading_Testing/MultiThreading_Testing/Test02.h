#pragma once
#include <thread>
#include <iostream>

using namespace std;

class ThreadRAII
{
	std::thread& m_thread;
public:
	ThreadRAII(std::thread& tObj) : m_thread(tObj) {}
	~ThreadRAII()
	{
		if (m_thread.joinable())
		{
			m_thread.detach();
		}
	}
};

void run3()
{
	std::thread tObj([] {});
	ThreadRAII t2(tObj);
}

void run2()
{
	std::thread tObj([] {});
	if (tObj.joinable())
	{
		cout << "yes" << endl;
		tObj.detach();
	}
	if (tObj.joinable())
	{
		cout << "yes" << endl;
		tObj.detach(); //exception if called twice
	}
	if (tObj.joinable())
	{
		cout << "yes" << endl;
		tObj.join(); //weird behavior if you call detach before
	}
	cout << tObj.get_id() << endl; //returns 0
	if (tObj.joinable())
	{
		cout << "yes" << endl;
		tObj.join(); //throws exception
	}
}

void run()
{
	//run3();
	//return;
	std::thread tObj([] {});
	//tObj.detach();
	//tObj.detach(); //exception if called twice
	tObj.join(); //weird behavior if you call detach before
	cout << tObj.get_id() << endl; //returns 0
	//tObj.join(); //throws exception
}
