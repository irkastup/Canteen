#include"BaseTxtRepository.h"
#include<fstream>
using namespace std;

BaseTxtRepository::BaseTxtRepository(string fileName, BaseTxtSerializer* txtSerializer, int capacity)
{
	this->fileName = fileName;
	this->txtSerializer = txtSerializer;
	count = 0;
	items = new BaseEntity * [capacity];
	ReadFromFile();
}

BaseTxtRepository::~BaseTxtRepository()
{
	WriteToFile();
	for (int i = 0; i < count; i++)
		delete items[i];
	delete[] items;
}

BaseEntity** BaseTxtRepository::GetAll()
{
	return items;
}

void BaseTxtRepository::Add(BaseEntity* entity)
{
	items[count] = entity;
	count++;
}

BaseEntity* BaseTxtRepository::GetAtIndex(int index)
{
	return items[index];
}

int BaseTxtRepository::GetCount()
{
	return count;
}

void BaseTxtRepository::ReadFromFile()
{
	ifstream fin(fileName);

	while (!fin.eof())
	{
		items[count++] = txtSerializer->Read(fin);
	}

	fin.close();
}

void BaseTxtRepository::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < count; i++)
	{
		txtSerializer->Write(fout, items[i]);

		if (i < (count - 1))
			fout << endl;
	}

	fout.close();
}