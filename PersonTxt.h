#pragma once
#include"Person.h"
#include"BaseTxtRepository.h"
#include "PersonTxtSerializer.h"
#include <iostream>
#include <string>
using namespace std;

class PersonTxt : public BaseTxtRepository
{
public:
	PersonTxt(int capacity = 100);
	void Add(Person person);
	Person GetAtIndex(int index);
};

