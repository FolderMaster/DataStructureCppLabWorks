#pragma once

#include "Functions.h"

/**
 * @brief ����������� ������.
 * @tparam T ��� ������.
 * @tparam size ������ �������.
*/
template<class T, const int size = 0>
class StaticArray
{
private:
	/**
	 * @brief ���������� ������������ �������.
	*/
	const exception _invalidIndexException = exception("������ ����������.");

	/**
	 * @brief ������.
	*/
	T _array[size];
public:
	/**
	 * @brief ��������� ������ �������.
	 * @return ������ �������.
	*/
	int GetSize()
	{
		return size;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	StaticArray()
	{
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param array ����������� ������.
	*/
	StaticArray(T array[size])
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = array[n];
		}
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ����������� ������.
	*/
	StaticArray(const StaticArray<T, size>& other)
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = other._array[n];
		}
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~StaticArray()
	{
	}

	/**
	 * @brief ����������� ������ ������ ����� �������.
	 * @param other ������ ������.
	 * @return ���� ������ ����� ����������.
	*/
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

	/**
	 * @brief ��������� �������� �� ������� �� �������.
	 * @param index ������ �������� �������.
	 * @return �������� ������� �� �������.
	*/
	T& operator[](int index)
	{
		if (index >= size)
		{
			throw _invalidIndexException;
		}
		else
		{
			return _array[index];
		}
	}

	/**
	 * @brief ��������� ������.
	*/
	void Sort()
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

	/**
	 * @brief ������������ ���������� �������� �������, ��������������� �������.
	 * @param item �������� ��� �����.
	 * @param function �������, ��������������� ������� ��� �����.
	 * @return ���������� ��������, ��������������� �������.
	*/
	int FindCount(T& item, bool (*function)(T a, T b))
	{
		int result = 0;
		for (int n = 0; n < size; ++n)
		{
			if (function(_array[n], item))
			{
				++result;
			}
		}
		return result;
	}
};

/**
 * @brief ������� ������ � ����� ������.
 * @tparam T ��� ������.
 * @tparam size ������ �������.
 * @param stream ����� ������.
 * @param array ������.
 * @return ����� � ������� �������.
*/
template<class T, const int size>
ostream& operator<<(ostream& stream, StaticArray<T, size> array)
{
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << array[n] << " ";
	}
	return stream;
}