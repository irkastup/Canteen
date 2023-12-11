#pragma once

#include"AMealRepository.h"
#include"APersonRepository.h"
#include"Canteen.h"
#include"PersonTxt.h"
#include"MealTxtTemplateRepository.h"
#include"PersonTxtTemplateRepository.h"

class AFactory
{
public:
	virtual AMealRepository* GetMealRepository() = 0;
	virtual APersonRepository* GetPersonRepository() = 0;
	virtual ~AFactory() {}
};

class InheritanceFactory : public AFactory
{
	Canteen* mealRepo;
	PersonTxt* personRepo;

public:
	InheritanceFactory()
	{
		mealRepo = new Canteen();
		personRepo = new PersonTxt();
	}
	AMealRepository* GetMealRepository()
	{
		return mealRepo;
	}
	APersonRepository* GetPersonRepository()
	{
		return personRepo;
	}

	~InheritanceFactory()
	{
		delete mealRepo;
		delete personRepo;
	}
};

class TemplateFactory : public AFactory
{
	MealTxtTemplateRepository* mealRepo;
	PersonTxtTemplateRepository* personRepo;
public:
	TemplateFactory()
	{
		mealRepo = new MealTxtTemplateRepository();
		personRepo = new PersonTxtTemplateRepository();

	}
	AMealRepository* GetMealRepository()
	{
		return mealRepo;
	}
	APersonRepository* GetPersonRepository()
	{
		return personRepo;
	}

	~TemplateFactory()
	{
		delete mealRepo;
		delete personRepo;
	}
};