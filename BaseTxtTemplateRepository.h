#pragma once

#include<string>
#include<fstream>
using namespace std;
template<class T, class TSerializer>
class BaseTxtTemplateRepository
{
	T* items;
	int count;

	void ReadFromFile();
	void WriteToFile();
	string fileName;

	TSerializer txtSerializer;
public:
	BaseTxtTemplateRepository(string fileName, TSerializer txtSerializer, int capacity = 100);
	void Add(T entity);
	int GetCount();
	T GetAtIndex(int index);
	~BaseTxtTemplateRepository();
};

template<class T, class TSerializer>
BaseTxtTemplateRepository<T, TSerializer>::BaseTxtTemplateRepository(string fileName, TSerializer txtSerializer, int capacity)
{
	this->fileName = fileName;
	this->txtSerializer = txtSerializer;
	count = 0;
	items = new T[capacity];
	ReadFromFile();
}

template<class T, class TSerializer>
BaseTxtTemplateRepository<T, TSerializer>::~BaseTxtTemplateRepository()
{
	WriteToFile();
	delete[] items;
}

template<class T, class TSerializer>
void BaseTxtTemplateRepository<T, TSerializer>::Add(T entity)
{
	items[count] = entity;
	count++;
}

template<class T, class TSerializer>
T BaseTxtTemplateRepository<T, TSerializer>::GetAtIndex(int index)
{
	return items[index];
}

template<class T, class TSerializer>
int BaseTxtTemplateRepository<T, TSerializer>::GetCount()
{
	return count;
}

template<class T, class TSerializer>
void BaseTxtTemplateRepository<T, TSerializer>::ReadFromFile()
{
	ifstream fin(fileName);

	while (!fin.eof())
	{
		items[count++] = txtSerializer.Read(fin);
	}

	fin.close();
}

template<class T, class TSerializer>
void BaseTxtTemplateRepository<T, TSerializer>::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < count; i++)
	{
		txtSerializer.Write(fout, items[i]);

		if (i < (count - 1))
			fout << endl;
	}

	fout.close();
}