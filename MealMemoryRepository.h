#pragma once
#include"Meal.h"
class MealMemoryRepository
{
	Meal* items;
	int count;
public:
	MealMemoryRepository(int capacity = 100);
	void Add(Meal meal);
	Meal* GetAll();
	int GetCount();
	~MealMemoryRepository();
};