#pragma once

#include "../ArrayLabWork1/Functions.h"

/**
 * @brief Пара ключ-значение.
 * @tparam TKey Тип данных ключа.
 * @tparam TValue Тип данных значения.
*/
template<class TKey, class TValue>
struct KeyValuePair
{
private:
	// TODO: Публичные поля!!1
	/**
	 * @brief Ключ.
	*/
	TKey _key;

	/**
	 * @brief Значение.
	*/
	TValue _value;

public:
	/**
	 * @brief Возращает ключ.
	 * @return Ключ.
	*/
	TKey GetKey()
	{
		return _key;
	}

	/**
	 * @brief Возращает значение.
	 * @return Значение.
	*/
	TValue GetValue()
	{
		return _value;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	KeyValuePair()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param key Ключ.
	*/
	KeyValuePair(TKey key)
	{
		_key = key;
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param key Ключ.
	 * @param value Значение.
	*/
	KeyValuePair(TKey key, TValue value)
	{
		_key = key;
		_value = value;
	}

	/**
	 * @brief Указывает больше ли эта пара ключ-значение, чем другая.
	 * @param other Другая пара ключ-значение.
	 * @return Логическое значение, указывающее больше ли эта пара ключ-значение, чем другая.
	*/
	bool operator>(KeyValuePair<TKey, TValue> other)
	{
		return _key > other._key;
	}

	/**
	 * @brief Указывает равна ли эта пара ключ-значение другой.
	 * @param other Другая пара ключ-значение.
	 * @return Логическое значение, указывающее равна ли эта пара ключ-значение другой.
	*/
	bool operator==(KeyValuePair<TKey, TValue> other)
	{
		return _key == other._key;
	}

	/**
	 * @brief Указывает меньше ли эта пара ключ-значение, чем другая.
	 * @param other Другая пара ключ-значение.
	 * @return Логическое значение, указывающее меньше ли эта пара ключ-значение, чем другая.
	*/
	bool operator<(KeyValuePair<TKey, TValue> other)
	{
		return _key < other._key;
	}
};

/**
 * @brief Вывод пару ключ-значение в поток вывода.
 * @tparam TKey Тип данных ключа.
 * @tparam TValue Тип данных значения.
 * @param stream Поток вывода.
 * @param keyValuePair Пара ключ-значение.
 * @return Поток с выводом пары ключ-значение.
*/
template<class TKey, class TValue>
ostream& operator<<(ostream& stream, KeyValuePair<TKey, TValue> keyValuePair)
{
	stream << keyValuePair.GetKey() << ":\t" << keyValuePair.GetValue();
	return stream;
}