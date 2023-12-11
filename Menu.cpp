#include"Menu.h"
#include"Queue.h"
#include"Logger.h" 
#include<iostream>
using namespace std;

Menu::Menu()
{
	mealRepo = factoryProvider.GetFactory()->GetMealRepository();
	personRepo = factoryProvider.GetFactory()->GetPersonRepository();

	takenMealsService = new TakenMealsService(&takenMealsRepo, mealRepo);
}

void Menu::Show()
{

	std::cout << "Welcome to the canteen!\n\n";

	while (true)
	{
		std::cout << "\nThere's some options that you can choose:\n\t"
			<< "1) Calculate nutrition norm\n\t"
			<< "2) Take a menu card\n\t"
			<< "3) Take an order\n\t"
			<< "4) Print all regular customers\n\t"
			<< "5) Add a new regular customer\n\t"
			<< "6) Show all meals taken by person\n\n"


			<< "Enter a number of action you would like to do.\n";
		
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
			cout << "Menu card:" << endl;

			for (int i = 0; i < mealRepo->GetCount(); i++)
				cout << mealRepo->GetAtIndex(i).ToString() << endl;
		}
		else if (x == 3)
		{
			Queue mainQueue(7);

			std::cin.get();
			mainQueue.Wait();

			int personId, MealNum;
			//cout << "Enter info:\n";
			cout << "What's your person id?: "; cin >> personId;
			std::cout << "\nTo choose your meal enter its number\n";
			std::cin >> MealNum;


			takenMealsRepo.Add(takenMeals(personId, MealNum));
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
		else if (x == 6)
		{
			int pid; Meal* PersonsMeals = new Meal(); int mcount;
			cout << "Enter person id: " << endl;
			cin >> pid;
			takenMealsService->GetTakenMealsByPerson(pid, PersonsMeals, mcount);
			if (mcount == 0)
			{
				cout << "This person don't have any order" << endl;
			}
			for (int i = 0; i < mcount; i++)
			{
				cout << endl << i + 1 << ")  " << PersonsMeals[i].ToString() << endl;
			}
		}
		else
		{
			std::cout << "Thank you for visiting our canteen!\n\n";
			break;
		}
	}
		
}
/*
* void Menu::PrintMenu()
{
	BaseEntity** meals = mealRepo.GetAll();

	for (int i = 0; i < mealRepo.GetCount(); i++)
	{
		static_cast<Meal*>(meals[i])->PrintMeal();

	}

}
*/

void Menu::PrintAllPersons()
{
	cout << "All regular customers:\n";


	for (int i = 0; i < personRepo->GetCount(); i++)
		cout << personRepo->GetAtIndex(i).ToString() << endl;
}



int Menu::AddNewPerson()
{
	while (true)
	{
		try
		{

			int id = personRepo->GetCount() + 1;
			Person* newPerson = new Person(id);
			newPerson->Input();
			personRepo->Add(*newPerson);

			cout << "Person added successfully!\n";
			return id;
		}
		catch (const char* err)
		{
			Logger::GetInstance().Log(err);
		}
	}
	
}


