#pragma once
#include"Person.h"
#include"BaseTxtRepository.h"
#include"APersonRepository.h"
#include <iostream>
#include <string>
using namespace std;

class PersonTxt : private BaseTxtRepository, public APersonRepository
{
public:
	PersonTxt(int capacity = 100);
	void Add(Person person);
	Person GetAtIndex(int index);
	int GetCount();
};

