#pragma once
class takenMeals
{
	int PersonId;
	int MealId;
public:
	takenMeals(int PersonId = 0, int MealId = 0);
	int GetPersonId() const;
	int GetMealId() const;
};

