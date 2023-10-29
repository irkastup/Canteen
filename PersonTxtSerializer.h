#pragma once
#include"BaseTxtSerializer.h"

class PersonTxtSerializer : public BaseTxtSerializer
{
public:
	BaseEntity* Read(ifstream& fin);
	void Write(ofstream& fout, BaseEntity* entity);
};
