#pragma once

/**
 * @brief —егмент кольцевого буфера.
 * @tparam T “ип данных.
*/
template<class T>
struct RingBufferSegment
{
public:
	/**
	 * @brief ”казатель на следующий сегмент.
	*/
	RingBufferSegment<T>* Next = nullptr;

	/**
	 * @brief «начение.
	*/
	T Item;

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param item «начение.
	*/
	RingBufferSegment<T>(T item)
	{
		Item = item;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param next ”казатель на следующий сегмент.
	*/
	RingBufferSegment<T>(RingBufferSegment<T>* next)
	{
		Next = next;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param next ”казатель на следующий сегмент.
	 * @param item «начение.
	*/
	RingBufferSegment<T>(RingBufferSegment<T>* next, T item)
	{
		Next = next;
		Item = item;
	}
};