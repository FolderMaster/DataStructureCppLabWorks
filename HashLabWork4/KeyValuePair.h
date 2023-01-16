#pragma once

#include "../ArrayLabWork1/Functions.h"

/**
 * @brief ���� ����-��������.
 * @tparam TKey ��� ������ �����.
 * @tparam TValue ��� ������ ��������.
*/
template<class TKey, class TValue>
struct KeyValuePair
{
private:
	// TODO: ��������� ����!!1
	/**
	 * @brief ����.
	*/
	TKey _key;

	/**
	 * @brief ��������.
	*/
	TValue _value;

public:
	/**
	 * @brief ��������� ����.
	 * @return ����.
	*/
	TKey GetKey()
	{
		return _key;
	}

	/**
	 * @brief ��������� ��������.
	 * @return ��������.
	*/
	TValue GetValue()
	{
		return _value;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	KeyValuePair()
	{
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param key ����.
	*/
	KeyValuePair(TKey key)
	{
		_key = key;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param key ����.
	 * @param value ��������.
	*/
	KeyValuePair(TKey key, TValue value)
	{
		_key = key;
		_value = value;
	}

	/**
	 * @brief ��������� ������ �� ��� ���� ����-��������, ��� ������.
	 * @param other ������ ���� ����-��������.
	 * @return ���������� ��������, ����������� ������ �� ��� ���� ����-��������, ��� ������.
	*/
	bool operator>(KeyValuePair<TKey, TValue> other)
	{
		return _key > other._key;
	}

	/**
	 * @brief ��������� ����� �� ��� ���� ����-�������� ������.
	 * @param other ������ ���� ����-��������.
	 * @return ���������� ��������, ����������� ����� �� ��� ���� ����-�������� ������.
	*/
	bool operator==(KeyValuePair<TKey, TValue> other)
	{
		return _key == other._key;
	}

	/**
	 * @brief ��������� ������ �� ��� ���� ����-��������, ��� ������.
	 * @param other ������ ���� ����-��������.
	 * @return ���������� ��������, ����������� ������ �� ��� ���� ����-��������, ��� ������.
	*/
	bool operator<(KeyValuePair<TKey, TValue> other)
	{
		return _key < other._key;
	}
};

/**
 * @brief ����� ���� ����-�������� � ����� ������.
 * @tparam TKey ��� ������ �����.
 * @tparam TValue ��� ������ ��������.
 * @param stream ����� ������.
 * @param keyValuePair ���� ����-��������.
 * @return ����� � ������� ���� ����-��������.
*/
template<class TKey, class TValue>
ostream& operator<<(ostream& stream, KeyValuePair<TKey, TValue> keyValuePair)
{
	stream << keyValuePair.GetKey() << ":\t" << keyValuePair.GetValue();
	return stream;
}