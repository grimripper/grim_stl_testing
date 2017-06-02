#pragma once
#include <thread>
#include <iostream>
#include <future>

using namespace std;

void initiazer(std::promise<int> * promObj)
{
	std::cout << "Inside Thread" << std::endl;     
	promObj->set_value(35);
	std::this_thread::sleep_for(chrono::milliseconds(1000));
	std::cout << "Done Thread" << std::endl;
}

void run()
{
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();

	std::thread th(initiazer, &promiseObj);
	cout << futureObj.get() << endl;
	cout << "Wait for join" << endl;
	th.join();
	cout << "Done" << endl;
}
