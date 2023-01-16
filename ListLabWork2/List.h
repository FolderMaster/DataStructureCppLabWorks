#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "ListSegment.h"

/**
 * @brief ������������� ������.
 * @tparam T ��� ������.
*/
template<class T>
class List
{
private:
	/**
	 * @brief ���������� ������������ �������.
	*/
	const exception _invalidIndexException = exception("������ ����������.");

	/**
	 * @brief ��������� �� ������ ������� ������.
	*/
	ListSegment<T>* _head = nullptr;

	/**
	 * @brief ��������� �� ��������� ������� ������.
	*/
	ListSegment<T>* _tail = nullptr;

	/**
	 * @brief ������ ������.
	 * @param size ������ ������.
	 * @param item �������� ��� ����������.
	*/
	void Create(int size, T item)
	{
		if (size > 0)
		{
			_head = new ListSegment<T>(item);
			ListSegment<T>* pointer = _head;
			for (int n = 1; n < size; ++n, pointer = pointer->Next)
			{
				pointer->Next = new ListSegment<T>(pointer, item);
				pointer->Next->Back = pointer;
			}
			_tail = pointer;
		}
	}

	/**
	 * @brief ������ ������.
	 * @param pointer ��������� �� ������ ������� ������.
	*/
	void Create(ListSegment<T>* pointer)
	{
		if (pointer != nullptr)
		{
			ListSegment<T>* otherPointer = pointer;
			_head = new ListSegment<T>(otherPointer->Item);
			ListSegment<T>* pointer = _head;
			while (otherPointer->Next != nullptr)
			{
				otherPointer = otherPointer->Next;
				pointer->Next = new ListSegment<T>(pointer, otherPointer->Item);
				pointer->Next->Back = pointer;
				pointer = pointer->Next;
			}
			_tail = pointer;
		}
	}
public:

	/**
	 * @brief ��������� ������ ������.
	 * @return 
	*/
	int GetSize()
	{
		int size = 0;
		for (ListSegment<T>* pointer = _head;
			pointer != nullptr;
			pointer = pointer->Next)
		{
			++size;
		}
		return size;
	}

	/**
	 * @brief ���������� ��������� �� ������ ������� ������.
	 * @return ��������� �� ������ ������� ������.
	*/
	ListSegment<T>* GetHead()
	{
		return _head;
	}

	/**
	 * @brief ���������� ��������� �� ��������� ������� ������.
	 * @return ��������� �� ��������� ������� ������.
	*/
	ListSegment<T>* GetTail()
	{
		return _tail;
	}

	/**
	 * @brief ������ ��������� ������ �� ���������.
	*/
	List()
	{
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ ������.
	*/
	List(int size)
	{
		Create(size, T());
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param size ������ ������.
	 * @param item �������� ��� ����������.
	*/
	List(int size, T item)
	{
		Create(size, item);
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ ������.
	*/
	List(const List<T>& other)
	{
		Create(other._head);
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~List()
	{
		Clear();
	}

	/**
	 * @brief ����������� ������ ������ ����� ������.
	 * @param other ������ ������.
	 * @return ���� ������ ����� ����������.
	*/
	List<T>& operator=(const List<T>& other)
	{
		if (this != &other)
		{
			Clear();
			Create(other._head);
		}
		return *this;
	}

	/**
	 * @brief ��������� �������� �� ������ �� �������.
	 * @param index ������ �������� ������.
	 * @return �������� ������ �� �������.
	*/
	T& operator[](int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	/**
	 * @brief �������� ��������� �� �������.
	 * @param index ������ ��� ��������� ���������.
	 * @return ��������� �� �������.
	*/
	ListSegment<T>* GetPointerOfIndex(int index)
	{
		ListSegment<T>* result;
		if (index >= 0)
		{
			result = _head;
			for (int n = 0; n < index; ++n, result = result->Next)
			{
				if (result == nullptr)
				{
					throw _invalidIndexException;
				}
			}
		}
		else
		{
			result = _tail;
			for (int n = -1; n > index; --n, result = result->Back)
			{
				if (result == nullptr)
				{
					throw _invalidIndexException;
				}
			}
		}
		return result;
	}

	/**
	 * @brief ��������� ������ �� �������.
	 * @param function �������, ��������������� ������� ����������.
	*/
	void Sort(bool (*function)(T a, T b))
	{
		if (_head != nullptr)
		{
			for (ListSegment<T>* pointer1 = _head; 
				pointer1->Next != nullptr; 
				pointer1 =	pointer1->Next)
			{
				for (ListSegment<T>* pointer2 = _head;
					pointer2->Next != nullptr;
					pointer2 = pointer2->Next)
				{
					T& item1 = pointer2->Item;
					T& item2 = pointer2->Next->Item;
					if (function(item2, item1))
					{
						T value = item1;
						item1 = item2;
						item2 = value;
					}
				}
			}
		}
	}

	/**
	 * @brief �������� ����� ������� �������� ������.
	 * @param item �������� ��� ������.
	 * @return ������ �������� ������.
	*/
	int LinearFindIndex(T item)
	{
		int index = 0;
		for (ListSegment<T>* pointer = _head;
			pointer != nullptr;
			pointer = pointer->Next)
		{
			if (pointer->Item == item)
			{
				return index;
			}
			++index;
		}
		return -1;
	}

	/**
	 * @brief ������������ ���������� �������� ������, ��������������� �������.
	 * @param function �������, ��������������� ������� ��� �����.
	 * @return ���������� ��������, ��������������� �������.
	*/
	int FindCount(bool (*function)(T a))
	{
		if (_head != nullptr)
		{
			int result = 0;
			for (ListSegment<T>* pointer = _head;
				pointer->Next != nullptr;
				pointer = pointer->Next)
			{
				if (function(pointer->Item))
				{
					++result;
				}
			}
			return result;
		}
		else
		{
			return 0;
		}
	}

	/**
	 * @brief ��������� �������� ����� ��������� �� ������� ������.
	 * @param item �������� ��� ���������� � ������.
	 * @param index ������ ��� ���������� � ������.
	*/
	void AddBefore(T item, int index)
	{
		ListSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			_head = new ListSegment<T>(item);
			_tail = _head;
		}
		else
		{
			pointer->Back = new ListSegment<T>(pointer->Back, pointer, item);
			if (_head == pointer)
			{
				_head = pointer->Back;
			}
			else
			{
				pointer->Back->Back->Next = pointer->Back;
			}
		}
	}

	/**
	 * @brief ��������� �������� ����� �������� �� ������� ������.
	 * @param item �������� ��� ���������� � ������.
	 * @param index ������ ��� ���������� � ������.
	*/
	void AddAfter(T item, int index)
	{
		ListSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			_head = new ListSegment<T>(item);
			_tail = _head;
		}
		else
		{
			pointer->Next = new ListSegment<T>(pointer, pointer->Next, item);
			if (pointer == _tail)
			{
				_tail = pointer->Next;
			}
			else
			{
				pointer->Next->Next->Back = pointer->Next;
			}
		}
	}

	/**
	 * @brief ��������� �������� � ����� ������.
	 * @param item �������� ��� ���������� � ������.
	*/
	void AddBegin(T item)
	{
		AddBefore(item, 0);
	}

	/**
	 * @brief ��������� �������� � ������ ������.
	 * @param item �������� ��� ���������� � ������.
	*/
	void AddEnd(T item)
	{
		AddAfter(item, -1);
	}

	/**
	 * @brief ������� �������� �� ������ �� �������.
	 * @param index ������ ��� �������� �� ������.
	*/
	void Remove(int index)
	{
		ListSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			throw _invalidIndexException;
		}
		else
		{
			if (pointer == _head)
			{
				_head = pointer->Next;
			}
			if (pointer == _tail)
			{
				_tail = pointer->Back;
			}
			if (pointer->Back != nullptr)
			{
				pointer->Back->Next = pointer->Next;
			}
			if (pointer->Next != nullptr)
			{
				pointer->Next->Back = pointer->Back;
			}
			delete pointer;
		}
	}

	/**
	 * @brief ������� �������� �� ������ ������.
	*/
	void RemoveBegin()
	{
		Remove(0);
	}

	/**
	 * @brief ������� �������� �� ����� ������.
	*/
	void RemoveEnd()
	{
		Remove(-1);
	}

	/**
	 * @brief ������� ������.
	*/
	void Clear()
	{
		if (_head != nullptr)
		{
			ListSegment<T>* pointer = _head;
			while (pointer->Next != nullptr)
			{
				pointer = pointer->Next;
				delete pointer->Back;
			}
			delete pointer;
			_head = nullptr;
			_tail = nullptr;
		}
	}
};

/**
 * @brief ������� ������ � ����� ������.
 * @tparam T ��� ������ ������.
 * @param stream ����� ������.
 * @param list ������.
 * @return ����� � ������� ������.
*/
template<class T>
ostream& operator<<(ostream& stream, List<T> list)
{
	for (ListSegment<T>* pointer = list.GetHead();
		pointer != nullptr;
		pointer = pointer->Next)
	{
		stream << pointer->Item << " ";
	}
	return stream;
}