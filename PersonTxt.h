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
	PersonTxt() : BaseTxtRepository("Persons.txt", new PersonTxtSerializer()) {

	}
};

