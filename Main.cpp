#include <iostream>

#include "Menu.h"

int main() 
{
	Menu menu;
	menu.Show();
	//Canteen mainCanteen(20); 
	//mainCanteen.ReadMealsFile("AvailableMeals.txt", mainCanteen);


	/*
	mainCanteen.AddMeal(Meal("plov", 432, 4, 18, 72));
	mainCanteen.AddMeal(Meal("mashed potato and kotleta", 398, 8, 20, 48));
	mainCanteen.AddMeal(Meal("lasagna", 514, 12, 28, 56));
	mainCanteen.AddMeal(Meal("pasta with chicken", 365, 24, 18, 46));
	mainCanteen.AddMeal(Meal("Spinach pie", 276, 12, 13, 60));
	*/
	


	/*



	std::cout << "Welcome to the canteen!\n\n";
	while (true)
	{
		int x = 0;

		std::cout << "\nThere's some options that you can choose:\n\t1) Calculate nutrition norm\n\t2) Take a menu card\n\t3) Take an order\n\nEnter a number of action you would like to do.\n";
		std::cin >> x;
		std::cout << "\n";
		if (x == 1)
		{
			std::cout << "Let's count your nutrition norm!\n\n";
			Person mainPerson;
			mainPerson.Input();
			mainPerson.CalculateNutrition();
		}
		else if (x == 2)
		{
			mainCanteen.PrintMenu();
		}
		else if (x == 3)
		{
			Queue mainQueue(7);

			std::cin.get();
			mainQueue.Wait();


			//mainCanteen.PrintMenu();
			mainCanteen.GetMeal();
		}
		else
		{
			std::cout << "Thank you for visiting our canteen!\n\n";
			break;
		}
	}
	*/
	return 0;
}