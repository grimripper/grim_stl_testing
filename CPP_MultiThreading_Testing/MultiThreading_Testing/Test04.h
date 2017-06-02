#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

using namespace std;

class Wallet
{
	int mMoney;
	mutex m;
public:
	Wallet() :mMoney(0) {}
	int getMoney() { return mMoney; }
	void addMoney(int money)
	{
		lock_guard<mutex> lg(m);
		for (int i = 0; i < money; ++i)
		{
			mMoney++;
		}
	}
};

int testMultithreadedWallet()
{
	Wallet walletObject;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 100000));
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
	return walletObject.getMoney();
}

void run()
{

	int val = 0;
	for (int k = 0; k < 1000; k++)
	{
		if ((val = testMultithreadedWallet()) != 500000)
		{
			std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
		}
	}
}
