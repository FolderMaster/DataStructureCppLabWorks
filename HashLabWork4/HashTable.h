#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/DynamicArray.h"
#include "../ListLabWork2/List.h"
#include "KeyValuePair.h"

/**
 * @brief Хеш-таблица.
 * @tparam TValue Тип данных.
*/
template <class TValue>
class HashTable
{
private:
	//ToDo: сделать возможным добавение некскольких пар с одинаковыми ключами.
	/**
	 * @brief Фактор роста для рехеширования.
	*/
	const double _growFactor = 1.5;

	/**
	 * @brief Коэффициент, при достижении которого коэффициентом эаполнения нужно осуществить
	 * перехеширование.
	*/
	const double _resizeCoefficient = 1;

	/**
	 * @brief Исключение не найденного ключа.
	*/
	const exception _keyNotFoundException = exception("Ключ не найден.");

	//TODO: RSDN
	/**
	 * @brief Взаимо-простое число для рассчёта хеш-функции.
	*/
	int _coprime;

	/**
	 * @brief Хеш-таблица.
	*/
	DynamicArray<List<KeyValuePair<string, TValue>>> _hashTable = 
		DynamicArray<List<KeyValuePair<string, TValue>>>();

	/**
	 * @brief Хеширует ключ.
	 * @param key Ключ.
	 * @return Хеш.
	*/
	int Hash(string key)
	{
		//TODO: RSDN
		int result = 0;
		int compire = 1;
		for (int n = 0; n < key.size(); ++n, compire *= _coprime)
		{
			result += key[n] * compire;
		}
		return result % _hashTable.GetSize();
	}

	/**
	 * @brief Рехеширование хеш-таблицы.
	*/
	void Rehash()
	{
		int size = _hashTable.GetSize();
		List<KeyValuePair<string, TValue>> pairList = List<KeyValuePair<string, TValue>>();
		for (int n = 0; n < size; ++n)
		{
			for (int h = 0; h < _hashTable[n].GetSize(); ++h)
			{
				pairList.AddEnd(_hashTable[n][h]);
			}
			_hashTable[n].Clear();
		}

		int newSize = round(size * _growFactor);
		for (int n = size; n < newSize; ++n)
		{
			_hashTable.AddEnd(List<KeyValuePair<string, TValue>>());
		}
		_coprime = FindСoprime(newSize);

		for (int n = 0; n < pairList.GetSize(); ++n)
		{
			int arrayIndex = Hash(pairList[n].GetKey());
			_hashTable[arrayIndex].AddEnd(pairList[n]);
		}
	}

	/**
	 * @brief Проверяет, нужно ли делать рехеширование хеш-таблицы.
	 * @return Логическое значение, обозначающиее, нужно ли делать рехеширование.
	*/
	bool IsNeedRehash()
	{
		int arraySize = _hashTable.GetSize();
		int listSize = 0;
		for (int n = 0; n < arraySize; ++n)
		{
			listSize += _hashTable[n].GetSize();
		}
		return listSize / (double)arraySize >= _resizeCoefficient;
	}
public:
	/**
	 * @brief Возращает массив хеш-таблицы.
	 * @return Массив списков пар ключ-значение.
	*/
	DynamicArray<List<KeyValuePair<string, TValue>>> GetArray()
	{
		return _hashTable;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	HashTable()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другая хеш-таблица.
	*/
	HashTable(const HashTable<TValue>& other)
	{
		_coprime = other._coprime;
		_hashTable = other._hashTable;
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~HashTable()
	{
	}

	/**
	 * @brief Присваивает другую хеш-таблицу этой хеш-таблице.
	 * @param other Другая хеш-таблица.
	 * @return Эта хеш-таблица после присовоения.
	*/
	HashTable<TValue>& operator=(const HashTable<TValue>& other)
	{
		if (this != &other)
		{
			_coprime = other._coprime;
			_hashTable = other._hashTable;
		}
		return *this;
	}

	/**
	 * @brief Добавляет пару ключ-значение в хеш-таблицу.
	 * @param key Ключ.
	 * @param value Значение.
	*/
	void Add(string key, TValue value)
	{
		if (_hashTable.GetSize() == 0)
		{
			List<KeyValuePair<string, TValue>> list = List<KeyValuePair<string, TValue>>();
			list.AddBegin(KeyValuePair<string, TValue>(key, value));
			_hashTable.AddBegin(list);
			Rehash();
		}
		else
		{
			KeyValuePair<string, TValue> pair = KeyValuePair<string, TValue>(key);
			int arrayIndex = Hash(key);
			_hashTable[arrayIndex].AddEnd(KeyValuePair<string, TValue>(key, value));
			if (IsNeedRehash())
			{
				Rehash();
			}
		}
	}

	/**
	 * @brief Удаляет пару ключ-значение из словаря.
	 * @param key Ключ.
	*/
	void Remove(string key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw _keyNotFoundException;
		}
		else
		{
			KeyValuePair<string, TValue> pair = KeyValuePair<string, TValue>(key);
			int arrayIndex = Hash(key);
			int listIndex = _hashTable[arrayIndex].LinearFindIndex(pair);
			if (listIndex == -1)
			{
				throw _keyNotFoundException;
			}
			else
			{
				while (listIndex != -1)
				{
					_hashTable[arrayIndex].Remove(listIndex);
					listIndex = _hashTable[arrayIndex].LinearFindIndex(pair);
				}
				
				if (IsNeedRehash())
				{
					Rehash();
				}
			}
		}
	}

	/**
	 * @brief Находит значение в хеш-таблице по ключу.
	 * @param key Ключ.
	 * @return Значение из пары ключ-значение.
	*/
	DynamicArray<TValue> Find(string key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw _keyNotFoundException;
		}
		else
		{
			KeyValuePair<string, TValue> pair = KeyValuePair<string, TValue>(key);
			int arrayIndex = Hash(key);
			List<KeyValuePair<string, TValue>> list = _hashTable[arrayIndex];
			int listIndex = list.LinearFindIndex(pair);
			if (listIndex == -1)
			{
				throw _keyNotFoundException;
			}
			else
			{
				DynamicArray<TValue> result = DynamicArray<TValue>();
				for (ListSegment<KeyValuePair<string, TValue>>* pointer = 
					list.GetPointerOfIndex(listIndex); 
					pointer != nullptr; 
					pointer = pointer->Next)
				{
					KeyValuePair<string, TValue> item = pointer->Item;
					if (item == pair)
					{
						result.AddEnd(item.GetValue());
					}
				}
				return result;
			}
		}
	}
};

/**
 * @brief Вывод хеш-таблицы в поток вывода.
 * @tparam TValue Тип значения.
 * @param stream Поток вывода.
 * @param hashTable Хеш-таблица.
 * @return Поток вывода с выводом словаря.
*/
template<class TValue>
ostream& operator<<(ostream& stream, HashTable<TValue> hashTable)
{
	stream << "Индекс:" << "\t" << "Цепочки:" << "\n";
	DynamicArray <List<KeyValuePair<string, TValue>>> array = hashTable.GetArray();
	for (int n = 0; n < array.GetSize(); ++n)
	{
		stream << n << "\t";
		for (int j = 0; j < array[n].GetSize(); ++j)
		{
			stream << array[n][j] << "\t\t";
		}
		if (n != array.GetSize() - 1)
		{
			stream << "\n";
		}
	}
	return stream;
}