#include "Canteen.h"
#include"MealTxtSerializer.h"

#include <iostream>

#include "Meal.h"
#include <string>
using namespace std;

Canteen::Canteen(int maxMealsCount) :
	BaseTxtRepository("AvailableMeals.txt", new MealTxtSerializer)
{
	
}

void Canteen::Add(Meal meal)
{
	BaseTxtRepository::Add(new Meal(meal));
}

Meal Canteen::GetAtIndex(int index)
{
	BaseEntity* entity = BaseTxtRepository::GetAtIndex(index);
	return  *static_cast<Meal*>(entity);
}





int Canteen::GetCount()
{
	return BaseTxtRepository::GetCount();
}