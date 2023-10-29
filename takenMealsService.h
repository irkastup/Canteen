#pragma once
#include"takenMealsTxt.h"
#include"Canteen.h"

class TakenMealsService
{
private:
	TakenMealsTxt* takenMealsRepo;
	Canteen* MealsRepo;

public:
	TakenMealsService(TakenMealsTxt* takenMealsRepo, Canteen* MealsRepo);
	void GetTakenMealsByPerson(int personId, Meal*& MealsOut, int& countOut);
};


