#pragma once
#include"takenMeals.h"
#include<string>
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
	void Add(takenMeals takenMeal);
	takenMeals* GetAll();
	int GetCount();
	~takenMealsTxt();
};

