#pragma once
#include"BaseEntity.h"
#include"BaseTxtSerializer.h"
#include<string>
using namespace std;

class BaseTxtRepository
{
	BaseEntity** items;
	int count;

	void ReadFromFile();
	void WriteToFile();
	string fileName;

	BaseTxtSerializer* txtSerializer;
public:
	BaseTxtRepository(string fileName, BaseTxtSerializer* txtSerializer, int capacity = 100);
	void Add(BaseEntity* entity);
	int GetCount();
	BaseEntity* GetAtIndex(int index);
	~BaseTxtRepository();
};


