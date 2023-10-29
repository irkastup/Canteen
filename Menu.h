#pragma once

#include"Canteen.h"
#include"PersonTxt.h"
#include"takenMealsTxt.h"
#include"takenMealsService.h"

class Menu
{
public:
	void Show();
	Menu();
private:
	Canteen mealRepo{20};
	PersonTxt personRepo{};
	TakenMealsTxt takenMealsRepo{};
	TakenMealsService takenMealsService;

	
	
	void PrintAllPersons();
	int AddNewPerson();
	void PrintMenu();


};

