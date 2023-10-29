#include "TakenMealsTxtSerializer.h"
#include "takenMeals.h"

BaseEntity* TakenMealsTxtSerializer::Read(ifstream& fin)
{
	int personId, mealId;
	fin >> personId >> mealId;
	return new takenMeals(personId, mealId);
}

void TakenMealsTxtSerializer::Write(ofstream& fout, BaseEntity* entity)
{
	takenMeals* takenMeal = static_cast<takenMeals*>(entity);

	fout << endl
		<< takenMeal->GetPersonId() << " "
		<< takenMeal->GetMealId() << endl;
}
