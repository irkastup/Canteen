#include "PersonTxtSerializer.h"
#include"Person.h"

BaseEntity* PersonTxtSerializer::Read(ifstream& fin)
{
	int id, age; char sex; float weight, height;

	fin >> id >> sex >> age >> weight >> height;

	return new Person(id, sex, age, weight, height);
}

void PersonTxtSerializer::Write(ofstream& fout, BaseEntity* entity)
{
	Person* pperson = static_cast<Person*>(entity);
	fout
		<< pperson->GetId() << " "
		<< pperson->GetSex() << " "
		<< pperson->GetAge() << " "
		<< pperson->GetWeight() << " "
		<< pperson->GetHeight();
}