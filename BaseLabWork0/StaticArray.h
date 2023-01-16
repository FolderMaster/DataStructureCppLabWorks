#pragma once

#include "Functions.h"
#include "ICollection.h"

template<class T, const int size = 0>
class StaticArray: public ICollection<T>
{
private:

	T _array[size];
public:

	int GetSize() override
	{
		return size;
	}

	StaticArray()
	{
	}

	StaticArray(T array[size])
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = array[n];
		}
	}

	StaticArray(const StaticArray<T, size>& other)
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = other._array[n];
		}
	}

	~StaticArray()
	{
	}

	StaticArray<T, size>& operator=(const StaticArray<T, size>& other)
	{
		if (this != *other)
		{
			for (int n = 0; n < size; ++n)
			{
				_array[n] = other._array[n];
			}
		}
		return *this;
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw new exception("Индекс вышел за пределы массива.");
		}
		else
		{
			return _array[index];
		}
	}

	void Sort() override
	{
		for (int n = 0; n < size; ++n)
		{
			for (int k = 0; k < size - 1; ++k)
			{
				if (_array[k + 1] > _array[k])
				{
					T value = _array[k];
					_array[k] = _array[k + 1];
					_array[k + 1] = value;
				}
			}
		}
	}

	template<class T>
	int FindCount(T& item, bool (*functor)(T a, T b))
	{
		int result = 0;
		for (int n = 0; n < size; ++n)
		{
			if (functor(_array[n], item))
			{
				++result;
			}
		}
		return result;
	}
};

template<class T, const int size>
ostream& operator<<(ostream& stream, StaticArray<T, size>& array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << array[n] << " ";
	}
	return stream;
}

template<class T, const int size>
istream& operator>>(istream& stream, StaticArray<T, size>& array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream >> array[n];
	}
	return stream;
}

template<class T, const int size>
void PrintStaticArrayWithFunctor(StaticArray<T, size>& array, bool (*functor)(T a))
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		if (functor(array[n]))
		{
			cout << array[n] << " ";
		}
	}
}