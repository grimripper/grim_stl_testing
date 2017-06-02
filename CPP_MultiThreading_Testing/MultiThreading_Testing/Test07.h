#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

string fetchDataFromDB(string recvdData)
{
	this_thread::sleep_for(chrono::seconds(5));
	return "DB_" + recvdData;
}

string fetchDataFromFile(string recvdData)
{
	this_thread::sleep_for(chrono::seconds(5));
	return "File_" + recvdData;
}

void run()
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	//string dbData = fetchDataFromDB("Data");
	//string fileData = fetchDataFromFile("Data");

	//future<string> result = async(launch::async, fetchDataFromDB, "Data");
	future<string> result = async(launch::async, [](const string& recvdData) {
		this_thread::sleep_for(chrono::seconds(5));
		return "DB_" + recvdData;
	}, "Data");

	string fileData = fetchDataFromFile("Data");
	string dbData = result.get();

	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << diff << " seconds" << endl;
	cout << dbData << " " << fileData << endl;
}
