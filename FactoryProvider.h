#pragma once

#include"AFactory.h"

class FactoryProvider
{
	AFactory* factory;
public:
	FactoryProvider()
	{
		factory = new InheritanceFactory();
	}
	AFactory* GetFactory()
	{
		return factory;
	}
	~FactoryProvider()
	{
		delete factory;
	}
};
