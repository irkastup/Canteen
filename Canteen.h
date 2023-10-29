#pragma once

#include "Meal.h"
#include <iostream>
#include <string>
#include"BaseTxtRepository.h"

using namespace std;
class Canteen : public BaseTxtRepository
{
	
public:
	Canteen(int maxMealsCount = 0);

	void Add(Meal meal);
	
	Meal GetAtIndex(int index);

	int GetMeal(int PersonId, int MealNum);
};