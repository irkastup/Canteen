#pragma once

#include "Meal.h"
#include <iostream>
#include <string>
using namespace std;
class Canteen
{
	Meal* availableMeals;
	int maxMealsCount;
	int availbeMealsCount;

	void ReadFromFile();
	void WriteToFile();
	const string fileName;
public:
	Canteen(int maxMealsCount = 0, const string fileName = "AvailableMeals.txt");

	Meal* GetAll();
	void AddMeal(Meal meal);
	//void PrintMenu();
	int GetCount();

	int GetMeal(int PersonId);

	~Canteen();

};