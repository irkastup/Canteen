#include "takenMealsTxt.h"
#include<fstream>
using namespace std;


takenMealsTxt::takenMealsTxt(int capacity)
{
	fileName = "takenMeals.txt";
	count = 0;
	items = new takenMeals[capacity];
	ReadFromFile();
}

takenMealsTxt::~takenMealsTxt()
{
	WriteToFile();
	delete[] items;
}

void takenMealsTxt::Add(takenMeals takenMeals)
{
	items[count] = takenMeals;
	count++;
}

takenMeals* takenMealsTxt::GetAll()
{
	return items;
}

int takenMealsTxt::GetCount()
{
	return count;
}

void takenMealsTxt::ReadFromFile()
{
	ifstream fin(fileName);
	int personId, mealId;

	while (!fin.eof())
	{
		fin >> personId >> mealId;
		items[count++] = takenMeals(personId, mealId);
	}

	fin.close();
}

void takenMealsTxt::WriteToFile()
{
	ofstream fout(fileName);

	for (int i = 0; i < count; i++)
	{
		fout
			<< items[i].GetPersonId() << " "
			<< items[i].GetMealId();

		if (i < (count - 1))
			fout << endl;
	}

	fout.close();
}

