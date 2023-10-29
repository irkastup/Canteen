#include "takenMealsService.h"

TakenMealsService::TakenMealsService(TakenMealsTxt* takenMeaksRepo, Canteen* MealsRepo) : takenMealsRepo(takenMeaksRepo), MealsRepo(MealsRepo)
{

}

void TakenMealsService::GetTakenMealsByPerson(int personId, Meal*& MealsOut, int& countOut)
{
	takenMeals* takenMeals = takenMealsRepo->GetAll();
	int takenMealsCount = takenMealsRepo->GetCount();

	Meal* meals = MealsRepo->GetAll();
	int MealsCount = MealsRepo->GetCount();

	MealsOut = new Meal[20];
	countOut = 0;

	for (int i = 0; i < takenMealsCount; i++)
	{
		if (takenMeals[i].GetPersonId() != personId)
			continue;

		int carId = takenMeals[i].GetMealId();
		for (int j = 0; j < MealsCount; j++)
			if (meals[j].GetId() == carId)
			{
				MealsOut[countOut++] = meals[j];
				break;
			}
	}
}