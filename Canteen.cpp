#include "Canteen.h"
#include <iostream>
#include <fstream>
#include "Meal.h"
#include <string>
using namespace std;

Canteen::Canteen(int maxMealsCount, const string fileName)
{
	cout << "Canteen constructor done" << fileName << endl;
	this->availableMeals = new Meal[maxMealsCount];
	this->maxMealsCount = maxMealsCount;
	this->availbeMealsCount = 0;
	this->fileName = fileName;
	
	ReadFromFile();
}
Canteen::~Canteen()
{
	cout << "Canteen destructor worked\n";
	WriteToFile();

	delete[] availableMeals;
}
int Canteen::GetCount()
{
	return availbeMealsCount;
}
void Canteen::AddMeal(Meal meal) {

	availableMeals[availbeMealsCount] = meal;
	availbeMealsCount += 1;
}

Meal* Canteen::GetAll()
{
	return availableMeals;
}


void Canteen::ReadFromFile()
{
	ifstream inputFile(fileName);
	cout << "read from file function\n";
	if (inputFile.is_open()) {
		int id;
		std::string MealName;
		int kkal;
		int protein;
		int fat;
		int carbs;
		cout << "file opened";
		while (inputFile >> id >> MealName >> kkal >> protein >> fat >> carbs) {
			AddMeal(Meal(id, MealName, kkal, protein, fat, carbs));
			cout << "meal added\n";
		}
		inputFile.close();
	}

}
void Canteen::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < availbeMealsCount; i++)
	{
		fout
			<< availableMeals[i].GetId() << " "
			<< availableMeals[i].GetName() << " "
			<< availableMeals[i].GetKkal() << " "
			<< availableMeals[i].GetProtein() << " "
			<< availableMeals[i].GetFat() << " "
			<< availableMeals[i].GetCarbs();

		if (i < (availbeMealsCount - 1))
			fout << endl;
	}

	fout.close();
}
/*
void Canteen::PrintMenu()
{
	std::cout << "Available meals: (kkal, protein, fat, carbs in portion)\n" ;
	for (int i = 0; i < availbeMealsCount; i++)
	{
		std::cout << i + 1 << ". ";
		availableMeals[i].PrintMeal();
	}

}*/

int Canteen::GetMeal(int PersonId)
{
	int MealNum;

	std::cout << "\nTo choose your meal enter its number\n";
	std::cin >> MealNum;

	//availableMeals[availbeMealsCount] = Get
	ofstream fout("takenMeals.txt", std::ios_base::app);
	
	fout << PersonId << " " << MealNum << endl;

	fout.close();


	std::cout << "\nIt's your ";
	availableMeals[MealNum - 1].PrintMeal();
	std::cout<< "Enjoy!\n\n";

	return 0;
}