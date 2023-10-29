#pragma once
#include"takenMealsTxt.h"
#include"Canteen.h"

class takenMealsService
{
private:
	takenMealsTxt* takenMealsRepo;
	Canteen* MealsRepo;

public:
	takenMealsService(takenMealsTxt* takenMealsRepo, Canteen* MealsRepo);
	void GetTakenMealsByPerson(int personId, Meal*& MealsOut, int& countOut);
};


