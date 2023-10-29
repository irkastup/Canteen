#include "Person.h"

#include <string>
#include <iostream>

Person::Person(int id, char sex, int age, float weight, float height)
{
	this->id = id;
	this->sex = sex;
	this->age = age;
	this->height = height;
	this->weight = weight;
}

char Person::GetSex() const
{
	return sex;
}
int Person::GetAge() const
{
	return age;
}
float Person::GetWeight() const
{
	return weight;
}
float Person::GetHeight() const
{
	return height;
}



void Person::Input() {

	std::cout << "Enter your sex (f/m): ";
	std::cin >> sex;

	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cout << "Enter your height: ";
	std::cin >> height;

	std::cout << "Enter your weight: ";
	std::cin >> weight;

}

void Person::CalculateNutrition()
{
	int kkal;

	try
	{
		if (sex != 'f' && sex != 'm')
		{
			throw 1;
		}
		else if (sex == 'f')
		{
			kkal = floor((10 * weight) + (6.25f * height) - (5 * age) - 161);
		}
		else if (sex == 'm')
		{
			kkal = floor((10 * weight) + (6.25f * height) - (5 * age) + 5);
		}
		std::cout << "We recommend you to eat " << kkal << " kkal worth of food, " << weight * 1.1 << "g of protein, " << weight << "g of fat and " << weight * 3 << "g of carbs!\n\n";

		
	}
	catch(int e)
	{
		if(e == 1)
		{
		std::cout << "You can choose only f or m\n";
		}
	}
}

std::string Person::ToString()
{
	std::string person;

	person = std::to_string(id) + ": " + sex + " " + std::to_string(age) + " " + std::to_string(weight) + " " + std::to_string(height);
	return person;
}