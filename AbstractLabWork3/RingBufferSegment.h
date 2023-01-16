#pragma once

/**
 * @brief ������� ���������� ������.
 * @tparam T ��� ������.
*/
template<class T>
struct RingBufferSegment
{
public:
	/**
	 * @brief ��������� �� ��������� �������.
	*/
	RingBufferSegment<T>* Next = nullptr;

	/**
	 * @brief ��������.
	*/
	T Item;

	/**
	 * @brief ������ ��������� ������.
	 * @param item ��������.
	*/
	RingBufferSegment<T>(T item)
	{
		Item = item;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param next ��������� �� ��������� �������.
	*/
	RingBufferSegment<T>(RingBufferSegment<T>* next)
	{
		Next = next;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param next ��������� �� ��������� �������.
	 * @param item ��������.
	*/
	RingBufferSegment<T>(RingBufferSegment<T>* next, T item)
	{
		Next = next;
		Item = item;
	}
};