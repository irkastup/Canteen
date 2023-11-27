#pragma once

#include "Meal.h"
#include <iostream>
#include <string>
#include"BaseTxtRepository.h"
#include"AMealRepository.h"

using namespace std;
class Canteen : private BaseTxtRepository, public AMealRepository
{
	
public:
	Canteen(int maxMealsCount = 0);

	void Add(Meal meal);
	
	Meal GetAtIndex(int index);

	//int GetMeal(int PersonId, int MealNum);
	int GetCount();
};