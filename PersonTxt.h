#pragma once
#include"Person.h"
#include"BaseTxtRepository.h"
#include <iostream>
#include <string>
using namespace std;

class PersonTxt : public BaseTxtRepository
{
	
public:
	PersonTxt(int capacity);
	void Add(Person person);

	~PersonTxt();
};

