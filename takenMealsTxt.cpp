#include "takenMealsTxt.h"
#include<fstream>
using namespace std;

	TakenMealsTxt::TakenMealsTxt(int capacity)
	{
		fileName = "takenMeals.txt";
		count = 0;
		items = new takenMeals[capacity];
		ReadFromFile();
	}


	void TakenMealsTxt::ReadFromFile()
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
	void TakenMealsTxt::WriteToFile()
	{
		ofstream fout(fileName);

		for (int i = 0; i < count; i++)
		{
			fout<<endl
				<< items[i].GetPersonId() << " "
				<< items[i].GetMealId() << endl;
		}

		fout.close();
	}
	


	void TakenMealsTxt::Add(takenMeals takenMeals)
	{
		items[count] = takenMeals;
		count++;
	}
	takenMeals* TakenMealsTxt::GetAll()
	{
		return items;
	}
	int TakenMealsTxt::GetCount()
	{
		return count;
	}

	TakenMealsTxt::~TakenMealsTxt()
	{
		WriteToFile();
		delete[] items;
	}

