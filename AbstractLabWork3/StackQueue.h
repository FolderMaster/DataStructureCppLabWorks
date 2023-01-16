#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "Stack.h"

/**
 * @brief ������� �� ������.
 * @tparam T ��� ������.
*/
template<class T>
class StackQueue
{
private:
	/**
	 * @brief ���� ���������.
	*/
	Stack<T> _pushStack;

	/**
	 * @brief ���� ����������.
	*/
	Stack<T> _popStack;
public:
	/**
	 * @brief ��������� �������� �� ����� ��������� �� �������.
	 * @param index ������.
	 * @return ��������.
	*/
	T& GetPushStackItem(int index)
	{
		return _pushStack[index];
	}

	/**
	 * @brief ��������� �������� �� ����� ���������� �� �������.
	 * @param index ������.
	 * @return ��������.
	*/
	T& GetPopStackItem(int index)
	{
		return _popStack[index];
	}

	/**
	 * @brief ��������� ������ ����� ���������.
	 * @return ������ ����� ���������.
	*/
	int GetPushStackSize()
	{
		return _pushStack.GetSize();
	}

	/**
	 * @brief ��������� ������ ����� ����������.
	 * @return ������ ����� ����������.
	*/
	int GetPopStackSize()
	{
		return _popStack.GetSize();
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	StackQueue()
	{
		_pushStack = Stack<T>();
		_popStack = Stack<T>();
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ������� �� ������.
	*/
	StackQueue(const StackQueue<T>& other)
	{
		_pushStack = other._pushStack;
		_popStack = other._popStack;
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~StackQueue()
	{
	}

	/**
	 * @brief ����������� ������ ������� �� ������ ���� ������� �� ������.
	 * @param other ������ ������� �� ������.
	 * @return ��� ������� �� ������ ����� ����������.
	*/
	StackQueue<T>& operator=(const StackQueue<T>& other)
	{
		if (this != &other)
		{
			_pushStack = other._pushStack;
			_popStack = other._popStack;
		}
		return *this;
	}

	/**
	 * @brief �������� �������� � ������� �� ������.
	 * @param item ��������.
	*/
	void Enqueue(T item)
	{
		_pushStack.Push(item);
	}

	/**
	 * @brief ����������� �������� �� ������� �� ������.
	 * @return ��������.
	*/
	T Dequeue()
	{
		if (_popStack.GetSize() == 0)
		{
			while (_pushStack.GetSize() > 0)
			{
				_popStack.Push(_pushStack.Pop());
			}
		}
		return _popStack.Pop();
	}
};

/**
 * @brief ������� ������� �� ������ � ����� ������.
 * @tparam T ��� ������.
 * @param stream ����� ������.
 * @param stackQueue ������� �� ������.
 * @return ����� � ������� ������� �� ������.
*/
template<class T>
ostream& operator<<(ostream& stream, StackQueue<T> stackQueue)
{
	const int pushStackSize = stackQueue.GetPushStackSize();
	const int popStackSize = stackQueue.GetPopStackSize();

	if (pushStackSize == 0)
	{
		stream << "\t->\t\t->\t\t->\t";
	}
	else
	{
		for (int n = 0; n < pushStackSize; ++n)
		{
			T item = stackQueue.GetPushStackItem(n);

			if (n == pushStackSize - 1)
			{
				stream << item << "\t->\t";
			}
			else
			{
				stream << "\t\t";
			}

			stream << item;

			if (n == pushStackSize - 1)
			{
				stream << "\t->\t" << item << "\t->\t";
			}
			else
			{
				stream << "\n";
			}
		}
	}

	if (popStackSize == 0)
	{
		stream << "\t->\t";
	}
	else
	{
		for (int n = popStackSize - 1; n >= 0; --n)
		{
			T item = stackQueue.GetPopStackItem(n);

			if (n != popStackSize - 1)
			{
				stream << "\t\t\t\t\t\t";
			}

			stream << item;

			if (n == popStackSize - 1)
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