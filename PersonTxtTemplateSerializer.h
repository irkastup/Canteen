#pragma once

#include"Person.h"

#include<fstream>

using namespace std;
class PersonTxtTemplateSerializer
{
public:
	Person Read(ifstream& fin)
	{
		int id, age; char sex; float weight, height;

		fin >> id >> sex >> age >> weight >> height;

		return Person(id, sex, age, weight, height);
	}

	void Write(ofstream& fout, Person person)
	{
		fout
			<< person.GetId() << " "
			<< person.GetSex() << " "
			<< person.GetAge() << " "
			<< person.GetWeight() << " "
			<< person.GetHeight();
	}
};
