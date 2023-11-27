#pragma once
#include"BaseEntity.h"
#include<fstream>
using namespace std;

class BaseTxtSerializer
{
public:
	virtual BaseEntity* Read(ifstream& fin);
	virtual void Write(ofstream& fout, BaseEntity* entity);
};



//virtual function read additional info