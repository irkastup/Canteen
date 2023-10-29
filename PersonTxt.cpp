#include "PersonTxt.h"
#include<fstream>
using namespace std;

PersonTxt::PersonTxt(int capacity)
{
	fileName = "Persons.txt";
	count = 0;
	people = new Person[capacity];
	ReadFromFile();
}

PersonTxt::~PersonTxt()
{
	WriteToFile();
	delete[] people;
}

void PersonTxt::Add(Person Person)
{
	people[count] = Person;
	count++;
}

Person* PersonTxt::GetAll()
{
	return people;
}

int PersonTxt::GetCount()
{
	return count;
}

void PersonTxt::ReadFromFile()
{
	ifstream fin(fileName);
	int id, age; char sex; float weight, height;

	while (!fin.eof()) // eof -> true\false
	{
		fin >> id >> sex >> age >> weight >> height;
		people[count++] = Person(id, sex, age, weight, height);
	}

	fin.close();
}

void PersonTxt::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < count; i++)
	{
		fout
			<< people[i].GetId() << " "
			<< people[i].GetSex() << " "
			<< people[i].GetAge() << " "
			<< people[i].GetWeight() << " "
			<< people[i].GetHeight();

		if (i < (count - 1))
			fout << endl;
	}

	fout.close();
}