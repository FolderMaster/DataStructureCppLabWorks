#pragma once

/**
 * @brief —егмент листа.
 * @tparam T “ип данных.
*/
template<class T>
struct ListSegment
{
public:
	/**
	 * @brief ”казатель на следующий сегмент.
	*/
	ListSegment<T>* Next = nullptr;

	/**
	 * @brief ”казатель на предыдущий сегмент.
	*/
	ListSegment<T>* Back = nullptr;

	/**
	 * @brief «начение.
	*/
	T Item;

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param item «начение.
	*/
	ListSegment<T>(T item)
	{
		Item = item;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param back ”казатель на предыдущий сегмент.
	*/
	ListSegment<T>(ListSegment<T>* back)
	{
		Back = back;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param back ”казатель на предыдущий сегмент.
	 * @param item «начение.
	*/
	ListSegment<T>(ListSegment<T>* back, T item)
	{
		Back = back;
		Item = item;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param back ”казатель на предыдущий сегмент.
	 * @param next ”казатель на следующий сегмент.
	*/
	ListSegment<T>(ListSegment<T>* back, ListSegment<T>* next)
	{
		Next = next;
		Back = back;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param back  ”казатель на предыдущий сегмент.
	 * @param next ”казатель на следующий сегмент.
	 * @param item «начение.
	*/
	ListSegment<T>(ListSegment<T>* back, ListSegment<T>* next, T item)
	{
		Next = next;
		Back = back;
		Item = item;
	}
};