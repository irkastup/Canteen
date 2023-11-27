#pragma once

#include"BaseTxtTemplateRepository.h"
#include"Meal.h"
#include"MealTxtTemplateSerializer.h"
#include"AMealRepository.h"
class MealTxtTemplateRepository : private BaseTxtTemplateRepository<Meal, MealTxtTemplateSerializer>,
	public AMealRepository
{
public:
	MealTxtTemplateRepository(int capacity = 100) :
		BaseTxtTemplateRepository("AvailableMeals.txt", MealTxtTemplateSerializer(), capacity)
	{}

	void Add(Meal meal)
	{
		BaseTxtTemplateRepository::Add(meal);
	}

	Meal GetAtIndex(int index)
	{
		return BaseTxtTemplateRepository::GetAtIndex(index);
	}

	int GetCount()
	{
		return BaseTxtTemplateRepository::GetCount();
	}
};