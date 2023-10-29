#pragma once
#include "takenMeals.h"
#include <iostream>
using namespace std;

class takenMealsTxt
{
	takenMeals* items;
	int count;

	void ReadFromFile();
	void WriteToFile();
	string fileName;
public:
	takenMealsTxt(int capacity = 100);
	void Add(takenMeals takenMeals);
	takenMeals* GetAll();
	int GetCount();
	~takenMealsTxt();
};

