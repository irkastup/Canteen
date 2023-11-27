#pragma once

template<class T>
class ARepository
{
public:
	virtual void Add(T entity) = 0;
	virtual int GetCount() = 0;
	virtual T GetAtIndex(int index) = 0;
};
