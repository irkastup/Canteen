#pragma once

#include "BaseTxtSerializer.h"

class TakenMealsTxtSerializer : public BaseTxtSerializer
{
public:
	BaseEntity* Read(ifstream& fin);
	void Write(ofstream& fout, BaseEntity* entity);
};

