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


	void takenMealsTxt::ReadFromFile()
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

	takenMealsTxt::~takenMealsTxt()
	{
		WriteToFile();
		delete[] items;
	}

