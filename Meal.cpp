#include "Meal.h"
#include <iostream>
using namespace std;
Meal::Meal(int id, std::string name, int kkal, int protein, int fat, int carbs)
{
	this->id = id;
	this->name = name;
	this->kkal = kkal;
	this->protein = protein;
	this->fat = fat;
	this->carbs = carbs;
}
std::string Meal::ToString()
{
	return to_string(id) + ": " + name + " (" + to_string(kkal) + ", " + to_string(protein) + ", " + to_string(fat) + ", " + to_string(carbs) + ")";
}



int Meal::GetId()
{
	return id;
}
std::string Meal::GetName()
{
	return name;
}
int Meal::GetKkal()
{
	return kkal;
}
int Meal::GetProtein()
{
	return protein;
}
int Meal::GetFat()
{
	return fat;
}
int Meal::GetCarbs()
{
	return carbs;
}