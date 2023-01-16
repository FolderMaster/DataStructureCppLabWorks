#pragma once

#include "Functions.h"

/**
 * @brief Динамический массив.
 * @tparam T Тип данных.
*/
template<class T>
class DynamicArray
{
private:
	/**
	 * @brief Значение, указывающее, на сколько возрастает объём при необходимости.
	*/
	const double _growthFactor = 2;

	/**
	 * @brief Исключение недоступного индекса.
	*/
	const exception _invalidIndexException = exception("Индекс недоступен.");

	/**
	 * @brief Исключение выхода индекса за пределы массива.
	*/
	const exception _indexOutOfRangeException = exception("Индекс вышел за пределы массива.");

	/**
	 * @brief Указатель на массив.
	*/
	T* _array = nullptr;

	/**
	 * @brief Размер массива.
	*/
	int _size = 0;

	/**
	 * @brief Объём массива.
	*/
	int _capacity = 0;

	/**
	 * @brief Изменяет объём массива.
	 * @param sizeChange Размер изменения.
	 * @return Указатель на массив.
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
	 * @brief Возращает размер массива.
	 * @return Размер массива.
	*/
	int GetSize()
	{
		return _size;
	}

	/**
	 * @brief Возращает объём массива.
	 * @return Объём массива.
	*/
	int GetCapasity()
	{
		return _capacity;
	}

	/**
	 * @brief Создаёт экземпляр класса по-умолчанию.
	*/
	DynamicArray()
	{
		_array = Resize(0);
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер массива.
	*/
	DynamicArray(int size)
	{
		_array = Resize(size);
		_size = size;
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер массива.
	 * @param item Значение для заполнения.
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
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер массива.
	 * @param pointer Указатель на значения для заполнения.
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
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой массив.
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
	 * @brief Удаляет экземпляр класса.
	*/
	~DynamicArray()
	{
		delete[] _array;
	}

	/**
	 * @brief Присваивает другой массив этому массиву.
	 * @param other Другой массив.
	 * @return Этот массив после присваения.
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
	 * @brief Извлекает значение из массива по индексу.
	 * @param index Индекс значения массива.
	 * @return Значение массива по индексу.
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
	 * @brief Сортирует массив по правилу.
	 * @param function Функция, предоставляющая правило сортировки.
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
	 * @brief Линейный поиск индекса значения массива.
	 * @param item Значение для поиска.
	 * @return Индекс значения массива.
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
	 * @brief Бинарный поиск индекса значения массива (для сортированного!).
	 * @param item Значение для поиска.
	 * @param function Функция, предоставляющая правило сортированного массива.
	 * @return Индекс значения массива.
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
	 * @brief Подсчитывает количество значений массива, удовлетворяющих условию.
	 * @param function Функция, предоставляющая условие для счёта.
	 * @return Количество значений, удовлетворяющих условию.
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
	 * @brief Добавляет в массив значение по индексу.
	 * @param item Значение для добавления в массив.
	 * @param index Индекс для добавления в массив.
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
	 * @brief Добавляет значение в конец массива.
	 * @param item Значение для добавления в массив.
	*/
	void AddEnd(T item)
	{
		Add(item, _size);
	}

	/**
	 * @brief Добавляет значение в начало массива.
	 * @param item Значение для добавления в массив.
	*/
	void AddBegin(T item)
	{
		Add(item, 0);
	}

	/**
	 * @brief Добавляет значение в массив значение после элемента индекса.
	 * @param item Значение для добавления в массив.
	 * @param index Индекс для добавления в массив.
	*/
	void AddAfter(T item, int index)
	{
		Add(item, index + 1);
	}

	/**
	 * @brief Удаляет значение из массива по индексу.
	 * @param index Индекс для удаления из массива.
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
	 * @brief Удаляет значение из конца массива.
	*/
	void RemoveEnd()
	{
		Remove(_size - 1);
	}

	/**
	 * @brief Удаляет значение из начала массива.
	*/
	void RemoveBegin()
	{
		Remove(0);
	}
};

/**
 * @brief Выводит массив в поток вывода.
 * @tparam T Тип данных массива.
 * @param stream Поток вывода.
 * @param array Массив.
 * @return Поток с выводом массива.
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