#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/DynamicArray.h"

/**
 * @brief ����.
 * @tparam T ��� ������.
*/
template <class T>
class Stack
{
private:
	/**
	 * @brief ���������� ������������ ������.
	*/
	const exception _invalidIndexException = exception("������ ����� �� ������� �������.");

	/**
	 * @brief ���������� ������� �����.
	*/
	const exception _emptyStackException = exception("������ ����.");

	/**
	 * @brief ������ �����.
	*/
	DynamicArray<T> _stack;
public:
	int GetSize()
	{
		return _stack.GetSize();
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	Stack()
	{
		_stack = DynamicArray<T>();
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ����.
	*/
	Stack(const Stack<T>& other)
	{
		_stack = other._stack;
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~Stack()
	{
	}

	/**
	 * @brief ����������� ������ ���� ����� ����.
	 * @param other ������ ����.
	 * @return ���� ���� ����� ����������.
	*/
	Stack<T>& operator=(const Stack<T>& other)
	{
		if (this != &other)
		{
			_stack = other._stack;
		}
		return *this;
	}

	/**
	 * @brief ��������� �������� �� ����� �� �������.
	 * @param index ������.
	 * @return ��������.
	*/
	T& operator[](int index)
	{
		if (index < 0 || index >= GetSize())
		{
			throw _invalidIndexException;
		}
		else
		{
			return _stack[index];
		}
	}

	/**
	 * @brief �������� �������� � ����.
	 * @param item ��������.
	*/
	void Push(T item)
	{
		_stack.AddEnd(item);
	}

	/**
	 * @brief ����������� �������� �� �����.
	 * @return ��������.
	*/
	T Pop()
	{
		if (GetSize() == 0)
		{
			throw _emptyStackException;
		}
		else
		{
			T result = operator[](GetSize() - 1);
			_stack.RemoveEnd();
			return result;
		}
	}
};

/**
 * @brief ������� ���� � ����� ������.
 * @tparam T ��� ������.
 * @param stream ����� ������.
 * @param stack ����.
 * @return ����� � ������� �����.
*/
template<class T>
ostream& operator<<(ostream& stream, Stack<T> stack)
{
	const int size = stack.GetSize();

	if (size == 0)
	{
		stream << "\t->\t\t->\t";
	}
	else
	{
		for (int n = 0; n < size; ++n)
		{
			T item = stack[n];

			if (n == size - 1)
			{
				stream << item << "\t->\t";
			}
			else
			{
				stream << "\t\t";
			}

			stream << item;

			if (n == size - 1)
			{
				stream << "\t->\t" << item << "\n";
			}
			else
			{
				stream << "\n";
			}
		}
	}
	return stream;
}