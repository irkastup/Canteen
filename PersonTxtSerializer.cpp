#include "PersonTxtSerializer.h"
#include"Person.h"

BaseEntity* PersonTxtSerializer::Read(ifstream& fin)
{
	int id; string name;
	fin >> id >> name;
	return new Person(id, name);
}

void PersonTxtSerializer::Write(ofstream& fout, BaseEntity* entity)
{
	Person* pperson = static_cast<Person*>(entity);
	fout
		<< pperson->GetId() << " "
		<< pperson->GetName();
}