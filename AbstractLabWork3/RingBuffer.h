#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "RingBufferSegment.h"

/**
 * @brief Кольцевой буфер.
 * @tparam T Тип данных.
*/
template<class T>
class RingBuffer
{
private:
	/**
	 * @brief Исключение отсутствия заполненного сегмента.
	*/
	const exception _noFilledSegmentException = exception("Нет записей в кольцевом буфере.");

	/**
	 * @brief Исключение заполненного буфера.
	*/
	const exception _filledBufferException = exception("Буфер заполнен.");

	/**
	 * @brief Указатель на первый сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* _head = nullptr;

	/**
	 * @brief Указатель на первый пустой сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* _emptyPointer = nullptr;

	/**
	 * @brief Указатель на первый заполненного сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* _filledPointer = nullptr;

	/**
	 * @brief Создаёт кольцевой буфер.
	 * @param size Размер кольцевого буфера.
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
	 * @brief Создаёт кольцевой буфер.
	 * @param head Указатель на первый сегмент кольцевого буфера.
	 * @param emptyPointer Указатель на первый пустой сегмент кольцевого буфера.
	 * @param filledPointer Указатель на первый заполненного сегмент кольцевого буфера.
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
	 * @brief Очищает кольцевой буфер.
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
	 * @brief Возращает указатель на первый сегмент кольцевого буфера.
	 * @return Указатель на первый сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* GetHead()
	{
		return _head;
	}

	/**
	 * @brief Возращает указатель на первый пустой сегмент кольцевого буфера.
	 * @return Указатель на первый пустой сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* GetEmptyPointer()
	{
		return _emptyPointer;
	}

	/**
	 * @brief Возращает указатель на первый заполненного сегмент кольцевого буфера.
	 * @return Указатель на первый заполненного сегмент кольцевого буфера.
	*/
	RingBufferSegment<T>* GetFilledPointer()
	{
		return _filledPointer;
	}

	/**
	 * @brief Возращает размер кольцевого буфера.
	 * @return Размер кольцевого буфера.
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
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	RingBuffer()
	{
		Create(8);
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер списка.
	*/
	RingBuffer(int size)
	{
		Create(size);
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой кольцевого буфера.
	*/
	RingBuffer(const RingBuffer<T>& other)
	{
		Create(other._head, other._emptyPointer, other._filledPointer);
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~RingBuffer()
	{
		Clear();
	}

	/**
	 * @brief Присваивает другой кольцевой буфер этому кольцевому буферу.
	 * @param other Другой кольцевой буфер.
	 * @return Этот кольцевой буфер после присвоения.
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
	 * @brief Помещает значение в кольцевой буфер.
	 * @param item Значение.
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
	 * @brief Извлеченное значение из кольцевого буфера.
	 * @return Значение.
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
 * @brief Выводит кольцевой буфер в поток вывода.
 * @tparam T Тип данных.
 * @param stream Поток вывода.
 * @param ringBuffer Кольцевой буфер.
 * @return Поток с выводом кольцевого буфера.
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