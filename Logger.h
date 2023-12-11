#pragma once
#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Logger
{
	Logger() {};
	Logger(const Logger& other) = delete; 
	Logger& operator=(Logger& other) = delete;

	static Logger instance;
public:
	void Log(string error)
	{
		ofstream fout("errors.txt", ios_base::app);
		fout << "Error: " << error << endl; // write into file
		fout.close();
	}

	static Logger& GetInstance()
	{
		return instance;
	}
};

Logger Logger::instance; // ctor