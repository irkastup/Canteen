#pragma once
#include"BaseTxtTemplateRepository.h"

#include"PersonTxtTemplateSerializer.h"
#include"APersonRepository.h"

#include"Person.h"


#include<fstream>
using namespace std;
class PersonTxtTemplateRepository : private BaseTxtTemplateRepository<Person, PersonTxtTemplateSerializer>,
	public APersonRepository
{
public:
	PersonTxtTemplateRepository(int capacity = 100) :
		BaseTxtTemplateRepository("Persons.txt", PersonTxtTemplateSerializer(), capacity)
	{}

	void Add(Person person)
	{
		BaseTxtTemplateRepository::Add(person);
	}

	Person GetAtIndex(int index)
	{
		return BaseTxtTemplateRepository::GetAtIndex(index);
	}

	int GetCount()
	{
		return BaseTxtTemplateRepository::GetCount();
	}
};


