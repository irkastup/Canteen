#include "MealTxtSerializer.h"
#include"Meal.h"

BaseEntity* MealTxtSerializer::Read(ifstream& fin)
{
	string name; int id, kkal, protein, fat, carbs;
	fin >> id >> name >> kkal >> protein >> fat >> carbs;
	return (new Meal(id, name, kkal, protein, fat, carbs));
}

void MealTxtSerializer::Write(ofstream& fout, BaseEntity* entity)
{
	Meal* pmeal = static_cast<Meal*>(entity);
	fout
		<< pmeal->GetId() << " "
		<< pmeal->GetName() << " "
		<< pmeal->GetKkal() << " "
		<< pmeal->GetProtein() << " "
		<< pmeal->GetFat() << " "
		<< pmeal->GetCarbs();
}