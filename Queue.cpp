#include "Queue.h"
#include <iostream>

Queue::Queue(int position)
{
	this->position = position;
}

void Queue::Wait()
{
	while (position != 0) {

		std::cout << "Your queue position is " << position << ". Please wait!\n";
		std::cin.get();
		position -= 1;
	}
}



