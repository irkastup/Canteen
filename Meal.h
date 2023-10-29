#pragma once

#include <string>

class Meal
{
	int id;
	std::string name;
	int kkal;
	int protein;
	int fat;
	int carbs;

public:
	Meal(int id = 0, std::string name = "gamno", int kkal = 0, int protein = 0, int fat = 0, int carbs = 0);
	
	std::string ToString();
	int GetId();
	std::string GetName();
	int GetKkal();
	int GetProtein();
	int GetFat();
	int GetCarbs();
};