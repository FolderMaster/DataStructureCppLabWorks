#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "RingBuffer.h"

/**
 * @brief Очередь кольцевого буфера.
 * @tparam T Тип данных.
*/
template <class T>
class RingBufferQueue
{
private:
	/**
	 * @brief Кольцевой буфер.
	*/
	RingBuffer<T> _ringBuffer = RingBuffer<T>();

	/**
	 * @brief 
	*/
	void Resize()
	{
		RingBufferSegment<T>* emptyPointer = _ringBuffer.GetEmptyPointer();
		emptyPointer->Next = new RingBufferSegment<T>(emptyPointer->Next, T());
	}
public:
	/**
	 * @brief Возращает кольцевой буфер.
	 * @return Кольцевой буфер.
	*/
	RingBuffer<T> GetRingBuffer()
	{
		return _ringBuffer;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	RingBufferQueue()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой кольцевой буфер.
	*/
	RingBufferQueue(const RingBufferQueue<T>& other)
	{
		_ringBuffer = other._ringBuffer;
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~RingBufferQueue()
	{
	}

	/**
	 * @brief Присваивает другой очереди кольцевого буфера этой очереди кольцевого буфера.
	 * @param other Другая очередь кольцевого буфера.
	 * @return Этот кольцеевой буфер после присваения.
	*/
	RingBufferQueue<T>& operator=(const RingBufferQueue<T>& other)
	{
		if (this != &other)
		{
			_ringBuffer = other._ringBuffer;
		}
		return *this;
	}

	/**
	 * @brief Помещает значение в очередь кольцевого буфера.
	 * @param item Значение.
	*/
	void Enqueue(T& item)
	{
		_ringBuffer.Push(item);
		if (_ringBuffer.GetEmptyPointer()->Next == _ringBuffer.GetFilledPointer())
		{
			Resize();
		}
	}

	/**
	 * @brief Извлеченное значение из очереди кольцевого буфера.
	 * @return Значение.
	*/
	T Dequeue()
	{
		return _ringBuffer.Pop();
	}
};

/**
 * @brief Выводит очередь кольцевого буфера в поток вывода.
 * @tparam T Тип данных.
 * @param stream Поток вывода.
 * @param ringBufferQueue Очередь кольцевого буфера.
 * @return Поток с выводом кольцевого буфера.
*/
template<class T>
ostream& operator<<(ostream& stream, RingBufferQueue<T> ringBufferQueue)
{
	stream << ringBufferQueue.GetRingBuffer();
	return stream;
}