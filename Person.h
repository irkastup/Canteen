#pragma once

#include <string>

class Person {

public:
	int id;
	char sex;
	int age;
	float weight;
	float height;

	Person(int id = 0, char sex = 'm', int age = 0, float weight = 0, float height = 0);

	int GetId() const;
	char GetSex() const;
	int GetAge() const;
	float GetWeight() const;
	float GetHeight() const;

	std::string ToString();

	void Input();
	void CalculateNutrition();
};