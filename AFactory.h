#pragma once

#include"AMealRepository.h"
#include"APersonRepository.h"
#include"Canteen.h"
#include"MealTxtTemplateRepository.h"
class AFactory
{
public:
	virtual AMealRepository* GetMealRepository() = 0;
	//virtual APersonRepository* GetPersonRepository() = 0;
	virtual ~AFactory() {}
};

class InheritanceFactory : public AFactory
{
	Canteen* mealRepo;
public:
	InheritanceFactory()
	{
		mealRepo = new Canteen();
	}
	AMealRepository* GetMealRepository()
	{
		return mealRepo;
	}
	~InheritanceFactory()
	{
		delete mealRepo;
	}
};

class TemplateFactory : public AFactory
{
	MealTxtTemplateRepository* mealRepo;
public:
	TemplateFactory()
	{
		mealRepo = new MealTxtTemplateRepository();
	}
	AMealRepository* GetMealRepository()
	{
		return mealRepo;
	}
	~TemplateFactory()
	{
		delete mealRepo;
	}
};