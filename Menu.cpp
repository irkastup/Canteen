#include"Menu.h"
#include"Queue.h"

#include<iostream>
using namespace std;

Menu::Menu() : takenMealsService(&takenMealsRepo, &mealRepo)
{
	
}

void Menu::Show()
{

	std::cout << "Welcome to the canteen!\n\n";

	while (true)
	{
		std::cout << "\nThere's some options that you can choose:\n\t1) Calculate nutrition norm\n\t2) Take a menu card\n\t3) Take an order\n\t4) Print all regular customers\n\t5)Add a new regular customer\n\nEnter a number of action you would like to do.\n";
		
		int x;
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
			PrintMenu();
		}
		else if (x == 3)
		{
			Queue mainQueue(7);

			std::cin.get();
			mainQueue.Wait();

			int PersId;
			cout << "What's your person id? (If you are new customer enter 0)" << endl;
			cin >> PersId;
			if (PersId == 0)
			{
				PersId = AddNewPerson();
				cout << "Your personal id is " << PersId << endl;
			}

			int MealNum;
			std::cout << "\nTo choose your meal enter its number\n";
			std::cin >> MealNum;

			mealRepo.GetMeal(PersId, MealNum);

			takenMeals newTakenMeal{ PersId, MealNum };
			takenMealsRepo.Add(newTakenMeal);
		}
		else if (x == 4)
		{
			PrintAllPersons();
		}
		else if (x == 5)
		{
			int NewId = AddNewPerson();
			cout << "This person's id: " << NewId << endl;

		}
		else
		{
			std::cout << "Thank you for visiting our canteen!\n\n";
			break;
		}
	}
		
}

void Menu::PrintMenu()
{
	Meal* meals = mealRepo.GetAll();

	for (int i = 0; i < mealRepo.GetCount(); i++)
	{
		meals[i].PrintMeal();
	}
		
}
void Menu::PrintAllPersons()
{
	cout << "All regular customers:\n";

	Person* persons = personRepo.GetAll();

	for (int i = 0; i < personRepo.GetCount(); i++)
		cout << persons[i].ToString() << endl;
}

int Menu::AddNewPerson()
{
	try
	{
	
		int id = personRepo.GetCount() + 1;
		Person newPerson{id};
		newPerson.Input();
		personRepo.Add(newPerson);
		
		cout << "Person added successfully!\n";
		return id;
	}
	catch (const char* err)
	{
		cout << "Error: " << err << endl;
		AddNewPerson();
	}
}


