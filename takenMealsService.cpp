#include "takenMealsService.h"


TakenMealsService::TakenMealsService(takenMealsTxt* takenMealsRepo, AMealRepository* mealsRepo) : takenMealsRepo(takenMealsRepo), mealsRepo(mealsRepo)
{

}

void TakenMealsService::GetTakenMealsByPerson(int personId, Meal*& mealsOut, int& countOut)
{

	takenMeals* takenMeals = takenMealsRepo->GetAll();
	int takenMealsCount = takenMealsRepo->GetCount();

	int mealsCount = mealsRepo->GetCount();

	mealsOut = new Meal[20];
	countOut = 0;

	for (int i = 0; i < takenMealsCount; i++)
	{
		if (takenMeals[i].GetPersonId() != personId)
			continue;

		int carId = takenMeals[i].GetMealId();
		for (int j = 0; j < mealsCount; j++)
			if (mealsRepo->GetAtIndex(j).GetId() == carId)
			{
				mealsOut[countOut++] = mealsRepo->GetAtIndex(i);
				break;
			}
	}
}