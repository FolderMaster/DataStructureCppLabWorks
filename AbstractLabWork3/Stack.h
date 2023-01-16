#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/DynamicArray.h"

/**
 * @brief Стек.
 * @tparam T Тип данных.
*/
template <class T>
class Stack
{
private:
	/**
	 * @brief Исключение недоступного метода.
	*/
	const exception _invalidIndexException = exception("Индекс вышел за пределы массива.");

	/**
	 * @brief Исключение пустого стека.
	*/
	const exception _emptyStackException = exception("Пустой стек.");

	/**
	 * @brief Массив стека.
	*/
	DynamicArray<T> _stack;
public:
	int GetSize()
	{
		return _stack.GetSize();
	}

	/**
	 * @brief Создаёт зкземпляр класса по умолчанию.
	*/
	Stack()
	{
		_stack = DynamicArray<T>();
	}

	/**
	 * @brief Создаёт зкземпляр класса копированием.
	 * @param other Другой стек.
	*/
	Stack(const Stack<T>& other)
	{
		_stack = other._stack;
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~Stack()
	{
	}

	/**
	 * @brief Присваивает другой стек этому стек.
	 * @param other Другой стек.
	 * @return Этот стек после присвоения.
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
	 * @brief Извлекает значение из стека по индексу.
	 * @param index Индекс.
	 * @return Значение.
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
	 * @brief Помещает значение в стек.
	 * @param item Значение.
	*/
	void Push(T item)
	{
		_stack.AddEnd(item);
	}

	/**
	 * @brief Извлеченное значение из стека.
	 * @return Значение.
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
 * @brief Выводит стек в поток вывода.
 * @tparam T Тип данных.
 * @param stream Поток вывода.
 * @param stack Стек.
 * @return Поток с выводом стека.
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