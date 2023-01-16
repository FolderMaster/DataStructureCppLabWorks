#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "Stack.h"

/**
 * @brief Очередь из стеков.
 * @tparam T Тип данных.
*/
template<class T>
class StackQueue
{
private:
	/**
	 * @brief Стек помещения.
	*/
	Stack<T> _pushStack;

	/**
	 * @brief Стек извлечения.
	*/
	Stack<T> _popStack;
public:
	/**
	 * @brief Извлекает значение из стека помещения по индексу.
	 * @param index Индекс.
	 * @return Значение.
	*/
	T& GetPushStackItem(int index)
	{
		return _pushStack[index];
	}

	/**
	 * @brief Извлекает значение из стека извлечения по индексу.
	 * @param index Индекс.
	 * @return Значение.
	*/
	T& GetPopStackItem(int index)
	{
		return _popStack[index];
	}

	/**
	 * @brief Возращает размер стека помещения.
	 * @return Размер стека помещения.
	*/
	int GetPushStackSize()
	{
		return _pushStack.GetSize();
	}

	/**
	 * @brief Возращает размер стека извлечения.
	 * @return Размер стека извлечения.
	*/
	int GetPopStackSize()
	{
		return _popStack.GetSize();
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	StackQueue()
	{
		_pushStack = Stack<T>();
		_popStack = Stack<T>();
	}

	/**
	 * @brief Создаёт зкземпляр класса копированием.
	 * @param other Другая очередь из стеков.
	*/
	StackQueue(const StackQueue<T>& other)
	{
		_pushStack = other._pushStack;
		_popStack = other._popStack;
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~StackQueue()
	{
	}

	/**
	 * @brief Присваивает другую очередь из стеков этой очереди из стеков.
	 * @param other Другая очередь из стеков.
	 * @return Эта очередь из стеков после присвоения.
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
	 * @brief Помещает значение в очередь из стеков.
	 * @param item Значение.
	*/
	void Enqueue(T item)
	{
		_pushStack.Push(item);
	}

	/**
	 * @brief Извлеченное значение из очереди из стеков.
	 * @return Значение.
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
 * @brief Выводит очередь из стеков в поток вывода.
 * @tparam T Тип данных.
 * @param stream Поток вывода.
 * @param stackQueue Очередь из стеков.
 * @return Поток с выводом очереди из стеков.
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