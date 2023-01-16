#pragma once

/**
 * @brief ������� �����.
 * @tparam T ��� ������.
*/
template<class T>
struct ListSegment
{
public:
	/**
	 * @brief ��������� �� ��������� �������.
	*/
	ListSegment<T>* Next = nullptr;

	/**
	 * @brief ��������� �� ���������� �������.
	*/
	ListSegment<T>* Back = nullptr;

	/**
	 * @brief ��������.
	*/
	T Item;

	/**
	 * @brief ������ ��������� ������.
	 * @param item ��������.
	*/
	ListSegment<T>(T item)
	{
		Item = item;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param back ��������� �� ���������� �������.
	*/
	ListSegment<T>(ListSegment<T>* back)
	{
		Back = back;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param back ��������� �� ���������� �������.
	 * @param item ��������.
	*/
	ListSegment<T>(ListSegment<T>* back, T item)
	{
		Back = back;
		Item = item;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param back ��������� �� ���������� �������.
	 * @param next ��������� �� ��������� �������.
	*/
	ListSegment<T>(ListSegment<T>* back, ListSegment<T>* next)
	{
		Next = next;
		Back = back;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param back  ��������� �� ���������� �������.
	 * @param next ��������� �� ��������� �������.
	 * @param item ��������.
	*/
	ListSegment<T>(ListSegment<T>* back, ListSegment<T>* next, T item)
	{
		Next = next;
		Back = back;
		Item = item;
	}
};