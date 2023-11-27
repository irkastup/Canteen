#include"MealMemoryRepository.h"

MealMemoryRepository::MealMemoryRepository(int capacity)
{
	count = 0;
	items = new Meal[capacity]; 
}

MealMemoryRepository::~MealMemoryRepository()
{
	delete[] items;
}

void MealMemoryRepository::Add(Meal meal)
{
	items[count] = meal;
	count++;
}

Meal* MealMemoryRepository::GetAll()
{
	return items;
}

int MealMemoryRepository::GetCount()
{
	return count;
}