#pragma once

#include "Person.h"

class Queue
{
	int position;

public:
	Queue(int position);
	void Wait();
};