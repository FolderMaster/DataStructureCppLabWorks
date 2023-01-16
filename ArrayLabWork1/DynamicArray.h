#pragma once

#include "Functions.h"

/**
 * @brief ������������ ������.
 * @tparam T ��� ������.
*/
template<class T>
class DynamicArray
{
private:
	/**
	 * @brief ��������, �����������, �� ������� ���������� ����� ��� �������������.
	*/
	const double _growthFactor = 2;

	/**
	 * @brief ���������� ������������ �������.
	*/
	const exception _invalidIndexException = exception("������ ����������.");

	/**
	 * @brief ���������� ������ ������� �� ������� �������.
	*/
	const exception _indexOutOfRangeException = exception("������ ����� �� ������� �������.");

	/**
	 * @brief ��������� �� ������.
	*/
	T* _array = nullptr;

	/**
	 * @brief ������ �������.
	*/
	int _size = 0;

	/**
	 * @brief ����� �������.
	*/
	int _capacity = 0;

	/**
	 * @brief �������� ����� �������.
	 * @param sizeChange ������ ���������.
	 * @return ��������� �� ������.
	*/
	T* Resize(int sizeChange)
	{
		if (_size + sizeChange > _capacity)
		{
			if (_capacity == 0)
			{
				_capacity = 1;
			}
			while (_capacity <= _size + sizeChange)
			{
				_capacity *= _growthFactor;
			}
			
			return new T[_capacity];
		}
		else if (_capacity * _growthFactor < (_size + sizeChange) && _capacity > 0)
		{
			while (_capacity > _size + sizeChange)
			{
				_capacity /= _growthFactor;
			}

			return new T[_capacity];
		}
		else
		{
			return _array;
		}
	}
public:
	/**
	 * @brief ��������� ������ �������.
	 * @return ������ �������.
	*/
	int GetSize()
	{
		return _size;
	}

	/**
	 * @brief ��������� ����� �������.
	 * @return ����� �������.
	*/
	int GetCapasity()
	{
		return _capacity;
	}

	/**
	 * @brief ������ ��������� ������ ��-���������.
	*/
	DynamicArray()
	{
		_array = Resize(0);
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ �������.
	*/
	DynamicArray(int size)
	{
		_array = Resize(size);
		_size = size;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ �������.
	 * @param item �������� ��� ����������.
	*/
	DynamicArray(int size, T item)
	{
		_array = Resize(size);
		for (int n = 0; n < size; ++n)
		{
			_array[n] = item;
		}
		_size = size;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ �������.
	 * @param pointer ��������� �� �������� ��� ����������.
	*/
	DynamicArray(int size, T* pointer)
	{
		_array = Resize(size);
		for (int n = 0; n < size; ++n)
		{
			_array[n] = pointer[n];
		}
		_size = size;
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ������.
	*/
	DynamicArray(const DynamicArray<T>& other)
	{
		_array = Resize(other._size);
		for (int n = 0; n < other._size; ++n)
		{
			_array[n] = other._array[n];
		}
		_size = other._size;
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~DynamicArray()
	{
		delete[] _array;
	}

	/**
	 * @brief ����������� ������ ������ ����� �������.
	 * @param other ������ ������.
	 * @return ���� ������ ����� ����������.
	*/
	DynamicArray<T>& operator=(const DynamicArray<T>& other)
	{
		if (this != &other)
		{
			delete[] _array;
			_array = Resize(other._size);
			for (int n = 0; n < other._size; ++n)
			{
				_array[n] = other._array[n];
			}
			_size = other._size;
		}
		return *this;
	}

	/**
	 * @brief ��������� �������� �� ������� �� �������.
	 * @param index ������ �������� �������.
	 * @return �������� ������� �� �������.
	*/
	T& operator[](int index)
	{
		if (index < 0 || index >= _size)
		{
			throw _indexOutOfRangeException;
		}
		else
		{
			return _array[index];
		}
	}

	/**
	 * @brief ��������� ������ �� �������.
	 * @param function �������, ��������������� ������� ����������.
	*/
	void Sort(bool (*function)(T a, T b))
	{
		for (int n = 0; n < _size; ++n)
		{
			for (int k = 0; k < _size - 1; ++k)
			{
				if (function(_array[k + 1], _array[k]))
				{
					T value = _array[k];
					_array[k] = _array[k + 1];
					_array[k + 1] = value;
				}
			}
		}
	}

	/**
	 * @brief �������� ����� ������� �������� �������.
	 * @param item �������� ��� ������.
	 * @return ������ �������� �������.
	*/
	int LinearFindIndex(T item)
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

	/**
	 * @brief �������� ����� ������� �������� ������� (��� ��������������!).
	 * @param item �������� ��� ������.
	 * @param function �������, ��������������� ������� �������������� �������.
	 * @return ������ �������� �������.
	*/
	int BinaryFindIndex(T item, bool (*function)(T a, T b))
	{
		for (int left = 0, right = _size - 1, mid = _size / 2; left <= right; mid = (left +
			right) / 2)
		{
			if (_array[mid] == item)
			{
				return mid;
			}
			else
			{
				if (function(_array[mid], item))
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return -1;
	}

	/**
	 * @brief ������������ ���������� �������� �������, ��������������� �������.
	 * @param function �������, ��������������� ������� ��� �����.
	 * @return ���������� ��������, ��������������� �������.
	*/
	int FindCount(bool (*function)(T a))
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

	/**
	 * @brief ��������� � ������ �������� �� �������.
	 * @param item �������� ��� ���������� � ������.
	 * @param index ������ ��� ���������� � ������.
	*/
	void Add(T item, int index)
	{
		if (index < 0 || index > _size)
		{
			throw _invalidIndexException;
		}
		else
		{
			T* newPointer = Resize(1);

			if (newPointer != _array)
			{
				for (int n = 0; n < index; ++n)
				{
					newPointer[n] = _array[n];
				}
			}
			for (int n = _size; n > index; --n)
			{
				newPointer[n] = _array[n - 1];
			}
			newPointer[index] = item;
			

			if (newPointer != _array)
			{
				delete[] _array;
				_array = newPointer;
			}
			++_size;
		}
	}

	/**
	 * @brief ��������� �������� � ����� �������.
	 * @param item �������� ��� ���������� � ������.
	*/
	void AddEnd(T item)
	{
		Add(item, _size);
	}

	/**
	 * @brief ��������� �������� � ������ �������.
	 * @param item �������� ��� ���������� � ������.
	*/
	void AddBegin(T item)
	{
		Add(item, 0);
	}

	/**
	 * @brief ��������� �������� � ������ �������� ����� �������� �������.
	 * @param item �������� ��� ���������� � ������.
	 * @param index ������ ��� ���������� � ������.
	*/
	void AddAfter(T item, int index)
	{
		Add(item, index + 1);
	}

	/**
	 * @brief ������� �������� �� ������� �� �������.
	 * @param index ������ ��� �������� �� �������.
	*/
	void Remove(int index)
	{
		if (index < 0 || index >= _size)
		{
			throw _indexOutOfRangeException;
		}
		else
		{
			T* newPointer = Resize(-1);
			if (newPointer != _array)
			{
				for (int n = 0; n < index; ++n)
				{
					newPointer[n] = _array[n];
				}
			}
			for (int n = index + 1; n < _size; ++n)
			{
				newPointer[n - 1] = _array[n];
			}

			if (newPointer != _array)
			{
				delete[] _array;
				_array = newPointer;
			}
			--_size;
		}
	}

	/**
	 * @brief ������� �������� �� ����� �������.
	*/
	void RemoveEnd()
	{
		Remove(_size - 1);
	}

	/**
	 * @brief ������� �������� �� ������ �������.
	*/
	void RemoveBegin()
	{
		Remove(0);
	}
};

/**
 * @brief ������� ������ � ����� ������.
 * @tparam T ��� ������ �������.
 * @param stream ����� ������.
 * @param array ������.
 * @return ����� � ������� �������.
*/
template<class T>
ostream& operator<<(ostream& stream, DynamicArray<T> array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << array[n] << " ";
	}
	return stream;
}