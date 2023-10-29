#pragma once
#include"Person.h"
#include <iostream>
#include <string>
using namespace std;

class PersonTxt
{
	Person* people;
	int count;

	void ReadFromFile();
	void WriteToFile();
	string fileName;
public:
	PersonTxt(int capacity);
	void Add(Person person);
	Person* GetAll();
	int GetCount();
	~PersonTxt();
};

