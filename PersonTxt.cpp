#include "PersonTxtSerializer.h"
#include"Person.h"
#include "PersonTxt.h"

#include<fstream>
using namespace std;

PersonTxt::PersonTxt(int capacity) :
	BaseTxtRepository("persons.txt", new PersonTxtSerializer, capacity)
{ }

void PersonTxt::Add(Person person)
{
	BaseTxtRepository::Add(new Person(person));
}

Person PersonTxt::GetAtIndex(int index)
{
	BaseEntity* entity = BaseTxtRepository::GetAtIndex(index);
	return  *static_cast<Person*>(entity);
}