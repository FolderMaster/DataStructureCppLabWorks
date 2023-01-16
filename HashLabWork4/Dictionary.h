#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/DynamicArray.h"
#include "KeyValuePair.h"

/**
 * @brief ������� � ������ ����-��������.
 * @tparam TValue ��� ������ ��������.
 * @tparam TKey ��� ������ �����.
*/
template <class TKey, class TValue>
class Dictionary
{
private:
	/**
	 * @brief ������� ����������.
	*/
	bool (*_sortFunction)(KeyValuePair<TKey, TValue> a, KeyValuePair<TKey, TValue> b) = IsLess;

	/**
	 * @brief ���������� �������� �����.
	*/
	const exception _occupiedKeyException = exception("���� �����.");

	/**
	 * @brief ���������� �� ���������� �����.
	*/
	const exception _keyNotFoundException = exception("���� �� ������.");

	/**
	 * @brief �������.
	*/
	DynamicArray<KeyValuePair<TKey, TValue>> _dictionary =
		DynamicArray<KeyValuePair<TKey, TValue>>();
public:
	/**
	 * @brief ���������� ������ �������.
	 * @return ������ � ������ ����-��������.
	*/
	DynamicArray<KeyValuePair<TKey, TValue>> GetArray()
	{
		return _dictionary;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	Dictionary()
	{
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ �������.
	*/
	Dictionary(const Dictionary<TKey, TValue>& other)
	{
		_dictionary = other._dictionary;
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~Dictionary()
	{
	}

	/**
	 * @brief ����������� ������ ������� ����� �������.
	 * @param other ������ �������.
	 * @return ���� ������� ����� ����������.
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
	 * @brief ��������� ���� ����-�������� � �������.
	 * @param key ����.
	 * @param value ��������.
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
	 * @brief ������� ���� ����-�������� �� �������.
	 * @param key ����.
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
	 * @brief ������� �������� � ������� �� �����.
	 * @param key ����.
	 * @return �������� �� ���� ����-��������.
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
 * @brief ����� ������� � ����� ������.
 * @tparam TKey ��� ������ �����.
 * @tparam TValue ��� ������ ��������.
 * @param stream ����� ������.
 * @param dictionary �������.
 * @return ����� � ������� �������.
*/
template<class TKey, class TValue>
ostream& operator<<(ostream& stream, Dictionary<TKey, TValue> dictionary)
{
	stream << "����:" << "\t" << "��������:" << "\n";
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