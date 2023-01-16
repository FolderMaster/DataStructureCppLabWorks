#pragma once

template <class T>
class ICollection
{
public:
	virtual int GetSize() = 0;

	virtual void Sort() = 0;
};