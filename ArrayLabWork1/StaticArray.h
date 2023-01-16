#pragma once

#include "Functions.h"

/**
 * @brief Статический массив.
 * @tparam T Тип данных.
 * @tparam size Размер массива.
*/
template<class T, const int size = 0>
class StaticArray
{
private:
	/**
	 * @brief Исключение недоступного индекса.
	*/
	const exception _invalidIndexException = exception("Индекс недоступен.");

	/**
	 * @brief Массив.
	*/
	T _array[size];
public:
	/**
	 * @brief Возращает размер массива.
	 * @return размер массива.
	*/
	int GetSize()
	{
		return size;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	StaticArray()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param array Статический массив.
	*/
	StaticArray(T array[size])
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = array[n];
		}
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой статический массив.
	*/
	StaticArray(const StaticArray<T, size>& other)
	{
		for (int n = 0; n < size; ++n)
		{
			_array[n] = other._array[n];
		}
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~StaticArray()
	{
	}

	/**
	 * @brief Присваивает другой массив этому массиву.
	 * @param other Другой массив.
	 * @return Этот массив после присвоения.
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
	 * @brief Извлекает значение из массива по индексу.
	 * @param index Индекс значения массива.
	 * @return Значение массива по индексу.
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
	 * @brief Сортирует массив.
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
	 * @brief Подсчитывает количество значений массива, удовлетворяющих условию.
	 * @param item Значение для счёта.
	 * @param function Функция, предоставляющая условие для счёта.
	 * @return Количество значений, удовлетворяющих условию.
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
 * @brief Выводит массив в поток вывода.
 * @tparam T Тип данных.
 * @tparam size Размер массива.
 * @param stream Поток вывода.
 * @param array Массив.
 * @return Поток с выводом массива.
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