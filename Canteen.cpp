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



int Canteen::GetMeal(int PersonId, int MealNum)
{

	// Save to the file
	ofstream fout("takenMeals.txt", std::ios_base::app);
	fout << PersonId << " " << MealNum << endl;
	fout.close();

	

	std::cout << "\nIt's your ";
	BaseEntity* entity = items[MealNum - 1];
	Meal* meal = static_cast<Meal*>(entity);

	meal->PrintMeal();
	std::cout<< "Enjoy!\n\n";

	return 0;
}