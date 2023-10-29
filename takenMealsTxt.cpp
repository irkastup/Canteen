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
		int personId, carId;

		while (!fin.eof())
		{
			fin >> personId >> carId;
			items[count++] = takenMeals(personId, carId);
		}

		fin.close();
	}
	void TakenMealsTxt::WriteToFile()
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

