#include "takenMealsService.h"

TakenMealsService::TakenMealsService(TakenMealsTxt* takenMeaksRepo, Canteen* MealsRepo) : takenMealsRepo(takenMeaksRepo), MealsRepo(MealsRepo)
{

}

void TakenMealsService::GetTakenMealsByPerson(int personId, Meal** MealsOut, int& countOut)
{

	BaseEntity** tMeals = takenMealsRepo->GetAll();
	int takenMealsCount = takenMealsRepo->GetCount();

	BaseEntity** meals = MealsRepo->GetAll();
	int MealsCount = MealsRepo->GetCount();

	countOut = 0;

	for (int i = 0; i < takenMealsCount; i++)
	{
		takenMeals* tMeal = static_cast<takenMeals*>(tMeals[i]);
			
		if (tMeal->GetPersonId() != personId)
			continue;

		int mealId = tMeal->GetMealId();
		for (int j = 0; j < MealsCount; j++)
		{
			Meal* meal = static_cast<Meal*>(meals[j]);

			if (meal->GetId() == mealId)
			{
				MealsOut[countOut++] = meal;
				break;
			}
		}

	}
}