#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "RingBufferSegment.h"

/**
 * @brief ��������� �����.
 * @tparam T ��� ������.
*/
template<class T>
class RingBuffer
{
private:
	/**
	 * @brief ���������� ���������� ������������ ��������.
	*/
	const exception _noFilledSegmentException = exception("��� ������� � ��������� ������.");

	/**
	 * @brief ���������� ������������ ������.
	*/
	const exception _filledBufferException = exception("����� ��������.");

	/**
	 * @brief ��������� �� ������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* _head = nullptr;

	/**
	 * @brief ��������� �� ������ ������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* _emptyPointer = nullptr;

	/**
	 * @brief ��������� �� ������ ������������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* _filledPointer = nullptr;

	/**
	 * @brief ������ ��������� �����.
	 * @param size ������ ���������� ������.
	*/
	void Create(int size)
	{
		if (size > 0)
		{
			_head = new RingBufferSegment<T>(T());
			RingBufferSegment<T>* pointer = _head;
			for (int n = 1; n < size; ++n, pointer = pointer->Next)
			{
				pointer->Next = new RingBufferSegment<T>(pointer, T());
			}
			pointer->Next = _head;
			_emptyPointer = _head;
		}
	}

	/**
	 * @brief ������ ��������� �����.
	 * @param head ��������� �� ������ ������� ���������� ������.
	 * @param emptyPointer ��������� �� ������ ������ ������� ���������� ������.
	 * @param filledPointer ��������� �� ������ ������������ ������� ���������� ������.
	*/
	void Create(RingBufferSegment<T>* head, RingBufferSegment<T>* emptyPointer,
		RingBufferSegment<T>* filledPointer)
	{
		_emptyPointer = nullptr;
		_filledPointer = nullptr;
		if (head != nullptr)
		{
			RingBufferSegment<T>* otherPointer = head;
			_head = new RingBufferSegment<T>(otherPointer->Item);
			RingBufferSegment<T>* thisPointer = _head;
			if (emptyPointer == otherPointer)
			{
				_emptyPointer = thisPointer;
			}
			if (filledPointer == otherPointer)
			{
				_filledPointer = thisPointer;
			}
			while (otherPointer->Next != head)
			{
				otherPointer = otherPointer->Next;
				thisPointer->Next = new RingBufferSegment<T>(thisPointer, otherPointer->Item);
				thisPointer = thisPointer->Next;
				if (emptyPointer == otherPointer)
				{
					_emptyPointer = thisPointer;
				}
				if (filledPointer == otherPointer)
				{
					_filledPointer = thisPointer;
				}
			}
			thisPointer->Next = _head;
		}
	}

	/**
	 * @brief ������� ��������� �����.
	*/
	void Clear()
	{
		if (_head != nullptr)
		{
			RingBufferSegment<T>* pointer = _head;
			while (pointer->Next != _head)
			{
				pointer = pointer->Next;
			}
			delete pointer;
			_head = nullptr;
		}
	}
public:
	/**
	 * @brief ��������� ��������� �� ������ ������� ���������� ������.
	 * @return ��������� �� ������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* GetHead()
	{
		return _head;
	}

	/**
	 * @brief ��������� ��������� �� ������ ������ ������� ���������� ������.
	 * @return ��������� �� ������ ������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* GetEmptyPointer()
	{
		return _emptyPointer;
	}

	/**
	 * @brief ��������� ��������� �� ������ ������������ ������� ���������� ������.
	 * @return ��������� �� ������ ������������ ������� ���������� ������.
	*/
	RingBufferSegment<T>* GetFilledPointer()
	{
		return _filledPointer;
	}

	/**
	 * @brief ��������� ������ ���������� ������.
	 * @return ������ ���������� ������.
	*/
	int GetSize()
	{
		int size = 0;
		if (_head != nullptr)
		{
			size = 1;
			for (RingBufferSegment<T>* pointer = _head; pointer->Next != _head; pointer =
				pointer->Next)
			{
				++size;
			}
		}
		return size;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	RingBuffer()
	{
		Create(8);
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ ������.
	*/
	RingBuffer(int size)
	{
		Create(size);
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ���������� ������.
	*/
	RingBuffer(const RingBuffer<T>& other)
	{
		Create(other._head, other._emptyPointer, other._filledPointer);
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~RingBuffer()
	{
		Clear();
	}

	/**
	 * @brief ����������� ������ ��������� ����� ����� ���������� ������.
	 * @param other ������ ��������� �����.
	 * @return ���� ��������� ����� ����� ����������.
	*/
	RingBuffer<T>& operator=(const RingBuffer<T>& other)
	{
		if (this != &other)
		{
			Clear();
			Create(other._head, other._emptyPointer, other._filledPointer);
		}
		return *this;
	}

	/**
	 * @brief �������� �������� � ��������� �����.
	 * @param item ��������.
	*/
	void Push(T& item)
	{
		if (_filledPointer == _emptyPointer)
		{
			throw _filledBufferException;
		}
		else
		{
			if (_filledPointer == nullptr)
			{
				_filledPointer = _emptyPointer;
			}
			_emptyPointer->Item = item;
			_emptyPointer = _emptyPointer->Next;
		}
	}

	/**
	 * @brief ����������� �������� �� ���������� ������.
	 * @return ��������.
	*/
	T Pop()
	{
		if (_filledPointer == nullptr)
		{
			throw _noFilledSegmentException;
		}
		else
		{
			T item = _filledPointer->Item;
			_filledPointer = _filledPointer->Next;
			if (_filledPointer == _emptyPointer)
			{
				_filledPointer = nullptr;
			}
			return item;
		}
	}
};

/**
 * @brief ������� ��������� ����� � ����� ������.
 * @tparam T ��� ������.
 * @param stream ����� ������.
 * @param ringBuffer ��������� �����.
 * @return ����� � ������� ���������� ������.
*/
template<class T>
ostream& operator<<(ostream& stream, RingBuffer<T> ringBuffer)
{
	for (int n = 0; n < ringBuffer.GetSize(); ++n)
	{
		stream << n << "\t";
	}
	stream << "\n";
	RingBufferSegment<T>* pointer = ringBuffer.GetHead();
	if (pointer != nullptr)
	{
		do
		{
			stream << pointer->Item << "\t";
			pointer = pointer->Next;
		} while (pointer != ringBuffer.GetHead());
		stream << "\n";
		do
		{
			if (pointer == ringBuffer.GetEmptyPointer() &&
				pointer != ringBuffer.GetFilledPointer())
			{
				stream << "^\t";
			}
			else if (pointer == ringBuffer.GetFilledPointer() &&
				pointer != ringBuffer.GetEmptyPointer())
			{
				stream << "<>\t";
			}
			else if (pointer == ringBuffer.GetEmptyPointer() &&
				pointer == ringBuffer.GetFilledPointer())
			{
				stream << "~\t";
			}
			else
			{
				stream << "\t";
			}
			pointer = pointer->Next;
		} while (pointer != ringBuffer.GetHead());
	}
	return stream;
}