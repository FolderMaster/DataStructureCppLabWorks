#pragma once

#include "ICollection.h"
#include "Functions.h"

template<class T>
class DynamicArray : public ICollection<T>
{
private:

	T* _array = nullptr;

	int _size = 0;

public:

	int GetSize() override
	{
		return _size;
	}

	DynamicArray()
	{
		_array = nullptr;
		_size = 0;
	}

	DynamicArray(int size)
	{
		_array = new T[size];
		_size = size;
	}

	DynamicArray(int size, T& item)
	{
		_array = new T[size];
		for (int n = 0; n < size; ++n)
		{
			_array[n] = item;
		}
		_size = size;
	}

	DynamicArray(int size, T* pointer)
	{
		_array = new T[size];
		for (int n = 0; n < size; ++n)
		{
			_array[n] = pointer[n];
		}
		_size = size;
	}

	DynamicArray(const DynamicArray<T>& other)
	{
		_size = other._size;
		_array = new T[_size];
		for (int n = 0; n < _size; ++n)
		{
			_array[n] = other._array[n];
		}
	}

	~DynamicArray()
	{
		delete[] _array;
	}

	DynamicArray<T>& operator=(const DynamicArray<T>& other)
	{
		if (this != &other)
		{
			_size = other._size;
			delete[] _array;
			_array = new T[_size];
			for (int n = 0; n < _size; ++n)
			{
				_array[n] = other._array[n];
			}
		}
		return *this;
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= _size)
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
		for (int n = 0; n < _size; ++n)
		{
			for (int k = 0; k < _size - 1; ++k)
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

	int FindIndex(T& item)
	{
		for (int n = 0; n < _size; ++n)
		{
			if (_array[n] == item)
			{
				return n;
			}
		}
		return -1;
	}

	int FindCount(bool (function)(T a))
	{
		int result = 0;
		for (int n = 0; n < _size; ++n)
		{
			if (function(_array[n]))
			{
				++result;
			}
		}
		return result;
	}
};

template<class T>
ostream& operator<<(ostream& stream, DynamicArray<T> array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << array[n] << " ";
	}
	return stream;
}

template<class T>
istream& operator>>(istream& stream, DynamicArray<T>& array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream >> array[n];
	}
	return stream;
}

template<class T>
DynamicArray<T> CreateRandomDynamicArray(int size)
{
	srand(time(0));
	DynamicArray<T> result = DynamicArray<T>(size);
	for (int n = 0; n < result.GetSize(); ++n)
	{
		result[n] = rand() % 100;
	}
	return result;
}

template<class T>
void PrintDynamicArrayWithFunctor(DynamicArray<T>& array, bool (*functor)(T a))
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		if (functor(array[n]))
		{
			cout << array[n] << " ";
		}
	}
	cout << endl;
}