#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "ListSegment.h"

/**
 * @brief Двухсторонный список.
 * @tparam T Тип данных.
*/
template<class T>
class List
{
private:
	/**
	 * @brief Исключение недоступного индекса.
	*/
	const exception _invalidIndexException = exception("Индекс недоступен.");

	/**
	 * @brief Указатель на первый сегмент списка.
	*/
	ListSegment<T>* _head = nullptr;

	/**
	 * @brief Указатель на последний сегмент списка.
	*/
	ListSegment<T>* _tail = nullptr;

	/**
	 * @brief Создаёт список.
	 * @param size Размер списка.
	 * @param item Значение для заполнения.
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
	 * @brief Создаёт список.
	 * @param pointer Указатель на первый сегмент списка.
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
	 * @brief Возращает размер списка.
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
	 * @brief Возвращает указатель на первый сегмент списка.
	 * @return Указатель на первый сегмент списка.
	*/
	ListSegment<T>* GetHead()
	{
		return _head;
	}

	/**
	 * @brief Возвращает указатель на последний сегмент списка.
	 * @return Указатель на последний сегмент списка.
	*/
	ListSegment<T>* GetTail()
	{
		return _tail;
	}

	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	List()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер списка.
	*/
	List(int size)
	{
		Create(size, T());
	}

	/**
	 * @brief Создаёт экземпляр класса.
	 * @param size Размер списка.
	 * @param item Значение для заполнения.
	*/
	List(int size, T item)
	{
		Create(size, item);
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другой список.
	*/
	List(const List<T>& other)
	{
		Create(other._head);
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~List()
	{
		Clear();
	}

	/**
	 * @brief Присваивает другой список этому списку.
	 * @param other Другой список.
	 * @return Этот список после присвоения.
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
	 * @brief Извлекает значение из списка по индексу.
	 * @param index Индекс значения списка.
	 * @return Значение списка по индексу.
	*/
	T& operator[](int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	/**
	 * @brief Получает указатель по индексу.
	 * @param index Индекс для получения указателя.
	 * @return Указатель по индексу.
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
	 * @brief Сортирует список по правилу.
	 * @param function Функция, предоставляющая правило сортировки.
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
	 * @brief Линейный поиск индекса значения списка.
	 * @param item Значение для поиска.
	 * @return Индекс значения списка.
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
	 * @brief Подсчитывает количество значений списка, удовлетворяющих условию.
	 * @param function Функция, предоставляющая условие для счёта.
	 * @return Количество значений, удовлетворяющих условию.
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
	 * @brief Добавляет значение перед сегментом по индексу списка.
	 * @param item Значение для добавления в список.
	 * @param index Индекс для добавления в список.
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
	 * @brief Добавляет значение после сегмента по индексу списка.
	 * @param item Значение для добавления в список.
	 * @param index Индекс для добавления в список.
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
	 * @brief Добавляет значение в конец списка.
	 * @param item Значение для добавления в список.
	*/
	void AddBegin(T item)
	{
		AddBefore(item, 0);
	}

	/**
	 * @brief Добавляет значение в начало списка.
	 * @param item Значение для добавления в список.
	*/
	void AddEnd(T item)
	{
		AddAfter(item, -1);
	}

	/**
	 * @brief Удаляет значение из списка по индексу.
	 * @param index Индекс для удаления из списка.
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
	 * @brief Удаляет значение из начала списка.
	*/
	void RemoveBegin()
	{
		Remove(0);
	}

	/**
	 * @brief Удаляет значение из конца списка.
	*/
	void RemoveEnd()
	{
		Remove(-1);
	}

	/**
	 * @brief Очищает список.
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
 * @brief Выводит список в поток вывода.
 * @tparam T Тип данных списка.
 * @param stream Поток вывода.
 * @param list Список.
 * @return Поток с выводом списка.
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