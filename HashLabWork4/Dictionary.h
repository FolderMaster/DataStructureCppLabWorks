#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/DynamicArray.h"
#include "KeyValuePair.h"

/**
 * @brief Словарь с парами ключ-значение.
 * @tparam TValue Тип данных значения.
 * @tparam TKey Тип данных ключа.
*/
template <class TKey, class TValue>
class Dictionary
{
private:
	/**
	 * @brief Функция сортировки.
	*/
	bool (*_sortFunction)(KeyValuePair<TKey, TValue> a, KeyValuePair<TKey, TValue> b) = IsLess;

	/**
	 * @brief Исключение занятого ключа.
	*/
	const exception _occupiedKeyException = exception("Ключ занят.");

	/**
	 * @brief Исключение не найденного ключа.
	*/
	const exception _keyNotFoundException = exception("Ключ не найден.");

	/**
	 * @brief Словарь.
	*/
	DynamicArray<KeyValuePair<TKey, TValue>> _dictionary =
		DynamicArray<KeyValuePair<TKey, TValue>>();
public:
	/**
	 * @brief Возвращает массив словаря.
	 * @return Массив с парами ключ-значение.
	*/
	DynamicArray<KeyValuePair<TKey, TValue>> GetArray()
	{
		return _dictionary;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	Dictionary()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой словарь.
	*/
	Dictionary(const Dictionary<TKey, TValue>& other)
	{
		_dictionary = other._dictionary;
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~Dictionary()
	{
	}

	/**
	 * @brief Присваивает другой словарь этому словарю.
	 * @param other Другой словарь.
	 * @return Этот словарь после присвоения.
	*/
	Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue>& other)
	{
		if (this != &other)
		{
			_dictionary = other._dictionary;
		}
		return *this;
	}

	/**
	 * @brief Добавляет пару ключ-значение в словарь.
	 * @param key Ключ.
	 * @param value Значение.
	*/
	void Add(TKey key, TValue value)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key, value);
		int index = _dictionary.BinaryFindIndex(pair, _sortFunction);
		if (index != -1)
		{
			throw _occupiedKeyException;
		}
		else
		{
			_dictionary.AddEnd(pair);
			_dictionary.Sort(_sortFunction);
		}
	}

	/**
	 * @brief Удаляет пару ключ-значение из словаря.
	 * @param key Ключ.
	*/
	void Remove(TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		int index = _dictionary.BinaryFindIndex(pair, _sortFunction);
		if (index == -1)
		{
			throw _keyNotFoundException;
		}
		else
		{
			_dictionary.Remove(index);
			_dictionary.Sort(_sortFunction);
		}
	}

	/**
	 * @brief Находит значение в словаре по ключу.
	 * @param key Ключ.
	 * @return Значение из пары ключ-значение.
	*/
	TValue Find(TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		int index = _dictionary.BinaryFindIndex(pair, _sortFunction);
		if (index == -1)
		{
			throw _keyNotFoundException;
		}
		else
		{
			return _dictionary[index].GetValue();
		}
	}
};

/**
 * @brief Вывод словарь в поток вывода.
 * @tparam TKey Тип данных ключа.
 * @tparam TValue Тип данных значения.
 * @param stream Поток вывода.
 * @param dictionary Словарь.
 * @return Поток с выводом словаря.
*/
template<class TKey, class TValue>
ostream& operator<<(ostream& stream, Dictionary<TKey, TValue> dictionary)
{
	stream << "Ключ:" << "\t" << "Значение:" << "\n";
	DynamicArray<KeyValuePair<TKey, TValue>> array = dictionary.GetArray();
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << array[n];
		if (n != array.GetSize() - 1)
		{
			stream << "\n";
		}
	}
	return stream;
}