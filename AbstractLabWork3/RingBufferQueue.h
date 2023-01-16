#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "RingBuffer.h"

/**
 * @brief ������� ���������� ������.
 * @tparam T ��� ������.
*/
template <class T>
class RingBufferQueue
{
private:
	/**
	 * @brief ��������� �����.
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
	 * @brief ��������� ��������� �����.
	 * @return ��������� �����.
	*/
	RingBuffer<T> GetRingBuffer()
	{
		return _ringBuffer;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	RingBufferQueue()
	{
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ��������� �����.
	*/
	RingBufferQueue(const RingBufferQueue<T>& other)
	{
		_ringBuffer = other._ringBuffer;
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~RingBufferQueue()
	{
	}

	/**
	 * @brief ����������� ������ ������� ���������� ������ ���� ������� ���������� ������.
	 * @param other ������ ������� ���������� ������.
	 * @return ���� ���������� ����� ����� ����������.
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
	 * @brief �������� �������� � ������� ���������� ������.
	 * @param item ��������.
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
	 * @brief ����������� �������� �� ������� ���������� ������.
	 * @return ��������.
	*/
	T Dequeue()
	{
		return _ringBuffer.Pop();
	}
};

/**
 * @brief ������� ������� ���������� ������ � ����� ������.
 * @tparam T ��� ������.
 * @param stream ����� ������.
 * @param ringBufferQueue ������� ���������� ������.
 * @return ����� � ������� ���������� ������.
*/
template<class T>
ostream& operator<<(ostream& stream, RingBufferQueue<T> ringBufferQueue)
{
	stream << ringBufferQueue.GetRingBuffer();
	return stream;
}