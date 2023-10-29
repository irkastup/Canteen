#pragma once
#include "takenMeals.h"
#include <iostream>
using namespace std;

class TakenMealsTxt
{
	takenMeals* items;
	int count;

	void ReadFromFile();
	void WriteToFile();
	string fileName;
public:
	TakenMealsTxt(int capacity);
	void Add(takenMeals takenMeals);
	takenMeals* GetAll();
	int GetCount();
	~TakenMealsTxt();
};

