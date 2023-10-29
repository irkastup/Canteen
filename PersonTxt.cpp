#include "PersonTxt.h"
#include<fstream>
using namespace std;

PersonTxt::PersonTxt(int capacity)
{
	fileName = "Persons.txt";
	count = 0;
	items = new Person[capacity];
	ReadFromFile();
}

PersonTxt::~PersonTxt()
{
	WriteToFile();
	delete[] items;
}

void PersonTxt::Add(Person Person)
{
	items[count] = Person;
	count++;
}

Person* PersonTxt::GetAll()
{
	return items;
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
		items[count++] = Person(id, sex, age, weight, height);
	}

	fin.close();
}

void PersonTxt::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < count; i++)
	{
		fout
			<< items[i].GetId() << " "
			<< items[i].GetSex() << " "
			<< items[i].GetAge() << " "
			<< items[i].GetWeight() << " "
			<< items[i].GetHeight();

		if (i < (count - 1))
			fout << endl;
	}

	fout.close();
}