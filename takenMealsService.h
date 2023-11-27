#pragma once
#include"takenMealsTxt.h"
#include"AMealRepository.h"

class TakenMealsService
{
private:
	takenMealsTxt* takenMealsRepo;
	AMealRepository* mealsRepo;

public:
	TakenMealsService(takenMealsTxt* takenMealsRepo, AMealRepository* mealsRepo);
	void GetTakenMealsByPerson(int personId, Meal*& mealsOut, int& countOut);
};


