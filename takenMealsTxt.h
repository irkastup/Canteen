#pragma once
#include "takenMeals.h"
#include "BaseTxtRepository.h"
#include "TakenMealsTxtSerializer.h"
#include <iostream>
using namespace std;

class TakenMealsTxt : public BaseTxtRepository
{
public:
	TakenMealsTxt() : BaseTxtRepository("takenMeals.txt", new TakenMealsTxtSerializer) {

	}
};

