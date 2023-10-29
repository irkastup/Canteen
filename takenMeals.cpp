#include "takenMeals.h"

takenMeals::takenMeals(int PersonId, int MealId) : PersonId(PersonId), MealId(MealId)
{

}
int takenMeals::GetPersonId() const
{
	return PersonId;
}
int takenMeals::GetMealId() const
{
	return MealId;
}