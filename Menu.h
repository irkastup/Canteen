#pragma once

#include"FactoryProvider.h"
#include"AMealRepository.h"

//#include"Canteen.h"
#include"APersonRepository.h"
#include"takenMealsTxt.h"
#include"takenMealsService.h"

class Menu
{
public:
	void Show();
	Menu();
private:
	FactoryProvider factoryProvider;
	AMealRepository* mealRepo;
	APersonRepository* personRepo;
	takenMealsTxt takenMealsRepo;
	TakenMealsService* takenMealsService;

	
	
	void PrintAllPersons();
	int AddNewPerson();
	void PrintMenu();


};

/*
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
}*/