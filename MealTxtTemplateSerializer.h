#pragma once

#include<fstream>
#include"Meal.h"
using namespace std;
class MealTxtTemplateSerializer
{
public:
	Meal Read(ifstream& fin)
	{
		string name; int id, kkal, protein, fat, carbs;
		fin >> id >> name >> kkal >> protein >> fat >> carbs;
		return  Meal(id, name, kkal, protein, fat, carbs);
	}

	void Write(ofstream& fout, Meal meal)
	{
		fout
			<< meal.GetId() << " "
			<< meal.GetName() << " "
			<< meal.GetKkal() << " "
			<< meal.GetProtein() << " "
			<< meal.GetFat() << " "
			<< meal.GetCarbs();
	}
};