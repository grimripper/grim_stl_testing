#pragma once
#include <thread>
#include <iostream>

using namespace std;

void thread_func()
{
	for (int i = 0; i < 10000; ++i)
		cout << "thread func executing" << endl;
}

class DisplayThread
{
public:
	void operator()()
	{
		for (int i = 0; i < 10000; ++i)
			cout << "display thread executing" << endl;
	}
};

void run()
{
	//thread tObj(thread_func);
	//thread tObj( (DisplayThread()) );
	thread tObj([] {
		for (int i = 0; i < 10000; ++i)
			cout << "display thread executing" << endl;
		cout << "threadid from inside thread" << std::this_thread::get_id() << endl;
	});
	auto thread_id = tObj.get_id();
	for (int i = 0; i < 10000; ++i)
		cout << "display from mainthread" << endl;
	tObj.join();
	cout << "threadid from outside thread" << thread_id << endl;
	cout << "exit of main function" << endl;
}
