#pragma once
#include"BaseEntity.h"
#include <string>

class Person : public BaseEntity {


	int id;
	char sex;
	int age;
	float weight;
	float height;
public:
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