#include "Meal.h"
#include <iostream>

Meal::Meal(int id, std::string name, int kkal, int protein, int fat, int carbs)
{
	this->id = id;
	this->name = name;
	this->kkal = kkal;
	this->protein = protein;
	this->fat = fat;
	this->carbs = carbs;
}
void Meal::PrintMeal()
{
	std::cout << name << " (" << kkal << " " << protein << " " << fat << " " << carbs << ")" << std::endl;
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