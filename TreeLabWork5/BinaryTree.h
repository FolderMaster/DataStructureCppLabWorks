#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "BinaryTreeSegment.h"

/**
 * @brief Бинарное дерево.
 * @tparam T Тип данных.
*/
template<class T>
class BinaryTree
{
protected:
	/**
	 * @brief Исключение пустого дерева.
	*/
	const exception _emptyTreeException = exception("Пустое дерево.");

	/**
	 * @brief Исключение ненайденного дерева.
	*/
	const exception _notFindException = exception("Не найдено в дереве.");

	/**
	 * @brief Корень дерева.
	*/
	TreeSegment<T>* _root = nullptr;

	/**
	 * @brief Создаёт дерево.
	 * @param root Корень другого дерева.
	*/
	void Create(TreeSegment<T>* root)
	{
		PreorderTraverseByPointer(root, [&](TreeSegment<T>* pointer) { Add(pointer->GetItem()); });
	}

	/**
	 * @brief Очищает дерево.
	*/
	void Clear()
	{
		PostorderTraverseByPointer(_root, [&](TreeSegment<T>* pointer) { delete pointer; });
		_root = nullptr;
	}
	
	/**
	 * @brief Удаляет сегмент.
	 * @param current Теукщий указатель сегмента.
	 * @param change Заменяющий указатель сегмента.
	*/
	void RemoveSegment(TreeSegment<T>* current, TreeSegment<T>* change)
	{
		TreeSegment<T>* parent = ReplaceSegment(current, change);
		delete current;
	}

	/**
	 * @brief Заменяет сегмент в родительском сегменте.
	 * @param current Текущий указатель сегмента.
	 * @param change Заменяющий указатель сегмента.
	 * @return Возращает родительский сегмент.
	*/
	TreeSegment<T>* ReplaceSegment(TreeSegment<T>* current, TreeSegment<T>* 
		change)
	{
		TreeSegment<T>* parent = current->GetParent();
		if (parent != nullptr)
		{
			if (parent->GetRight() == current)
			{
				parent->SetRight(change);
			}
			else
			{
				parent->SetLeft(change);
			}
		}
		else
		{
			if (change != nullptr)
			{
				change->SetParent(nullptr);
			}
			_root = change;
		}

		return parent;
	}

	/**
	 * @brief Находит указатель сегмент минимального значения, начиная с указателя сегмента.
	 * @param pointer Указатель сегмента.
	 * @return Возращает указатель сегмента м минимаьного значения.
	*/
	TreeSegment<T>* FindMinSegment(TreeSegment<T>* pointer)
	{
		if (pointer == nullptr)
		{
			throw _emptyTreeException;
		}
		else
		{
			TreeSegment<T>* findPointer = pointer;
			while (findPointer->GetLeft() != nullptr)
			{
				findPointer = findPointer->GetLeft();
			}
			return findPointer;
		}
	}

	/**
	 * @brief Находит указатель сегмент со значением, начиная с указателя сегмента.
	 * @param item Значение.
	 * @return 
	*/
	TreeSegment<T>* FindSegment(T item)
	{
		TreeSegment<T>* pointer = _root;
		while (pointer != nullptr)
		{
			if (pointer->GetItem() == item)
			{
				return pointer;
			}
			else
			{
				if (pointer->GetItem() < item)
				{
					pointer = pointer->GetRight();
				}
				else
				{
					pointer = pointer->GetLeft();
				}
			}
		}
		throw _notFindException;
	}

	/**
	 * @brief Осуществляет прямой обход, начиная с указателя на сегмент, вызывая функцию для
	 * каждого элемента.
	 * @tparam F Тип функции.
	 * @param pointer Указатель на сегмент.
	 * @param function Функции.
	*/
	template <class F>
	void PreorderTraverseByPointer(TreeSegment<T>* pointer, F function)
	{
		if (pointer == nullptr)
		{
			return;
		}
		function(pointer);
		PreorderTraverseByPointer(pointer->GetLeft(), function);
		PreorderTraverseByPointer(pointer->GetRight(), function);
	}

	/**
	 * @brief Осуществляет обратный обход, начиная с указателя на сегмент, вызывая функцию для
	 * каждого элемента.
	 * @tparam F Тип функции.
	 * @param pointer Указатель на сегмент.
	 * @param function Функции.
	*/
	template <class F>
	void PostorderTraverseByPointer(TreeSegment<T>* pointer, F function)
	{
		if (pointer == nullptr)
		{
			return;
		}
		PostorderTraverseByPointer(pointer->GetLeft(), function);
		PostorderTraverseByPointer(pointer->GetRight(), function);
		function(pointer);
	}

	/**
	 * @brief Осуществляет симметричный обход, начиная с указателя на сегмент, вызывая функцию для 
	 * каждого элемента.
	 * @tparam F Тип функции.
	 * @param pointer Указатель на сегмент.
	 * @param function Функции.
	*/
	template <class F>
	void InorderTraverseByPointer(TreeSegment<T>* pointer, F function)
	{
		if (pointer == nullptr)
		{
			return;
		}
		InorderTraverseByPointer(pointer->GetLeft(), function);
		function(pointer);
		InorderTraverseByPointer(pointer->GetRight(), function);
	}

	/**
	 * @brief Осуществляет симметричный обход, начиная с указателя на сегмент, вызывая функцию для
	 * каждого элемента и уровня вложенности.
	 * @tparam F Тип функции.
	 * @param pointer Указатель на сегмент.
	 * @param function Функция.
	 * @param level Уровень вложенности(количество предков).
	*/
	template <class F>
	void InorderTraverseByPointerWithIndex(TreeSegment<T>* pointer, F function, int level)
	{
		if (pointer == nullptr)
		{
			return void();
		}
		InorderTraverseByPointerWithIndex(pointer->GetLeft(), function, level + 1);
		function(pointer, level);
		InorderTraverseByPointerWithIndex(pointer->GetRight(), function, level + 1);
	}
public:
	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	BinaryTree()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса копированием.
	 * @param other Другое бинарное дерево.
	*/
	BinaryTree(const BinaryTree<T>& other)
	{
		Create(other._root);
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~BinaryTree()
	{
		Clear();
	}

	/**
	 * @brief Присваивает другое бинарное дерево этому бинарному дереву.
	 * @param other Другое бинарное дерево.
	 * @return Это бинарное дерево после присваения.
	*/
	BinaryTree<T>& operator=(const BinaryTree<T>& other)
	{
		if (this != &other)
		{
			Clear();
			Create(other._root);
		}
		return *this;
	}

	/**
	 * @brief Добавляет значение в бинарное дерево.
	 * @param item Значение.
	*/
	void Add(T item)
	{
		if (_root == nullptr)
		{
			_root = new TreeSegment<T>(item);
		}
		else
		{
			TreeSegment<T>* pointer = _root;
			while (true)
			{
				if (pointer->GetItem() < item)
				{
					if (pointer->GetRight() == nullptr)
					{
						pointer->SetRight(new TreeSegment<T>(item, pointer));
						break;
					}
					else
					{
						pointer = pointer->GetRight();
					}
				}
				else
				{
					if (pointer->GetLeft() == nullptr)
					{
						pointer->SetLeft(new TreeSegment<T>(item, pointer));
						break;
					}
					else
					{
						pointer = pointer->GetLeft();
					}
				}
			}
		}
	}

	/**
	 * @brief Удаляет сегмент значения из бинарного дерева.
	 * @param item Значение.
	*/
	void Remove(T item)
	{
		TreeSegment<T>* pointer = FindSegment(item);
		if (pointer->GetRight() == nullptr && pointer->GetLeft() == nullptr)
		{
			RemoveSegment(pointer, nullptr);
		}
		else if (pointer->GetRight() != nullptr && pointer->GetLeft() == nullptr)
		{
			pointer->GetRight()->SetParent(pointer->GetParent());
			RemoveSegment(pointer, pointer->GetRight());
		}
		else if (pointer->GetLeft() != nullptr && pointer->GetRight() == nullptr)
		{
			pointer->GetLeft()->SetParent(pointer->GetParent());
			RemoveSegment(pointer, pointer->GetLeft());
		}
		else
		{
			TreeSegment<T>* minPointer = FindMinSegment(pointer->GetRight());
			T item = minPointer->GetItem();
			if (minPointer->GetRight() != nullptr)
			{
				minPointer->GetRight()->SetParent(minPointer->GetParent());
			}
			RemoveSegment(minPointer, minPointer->GetRight());
			pointer->SetItem(item);
		}
	}

	/**
	 * @brief Находит сегмент значения в бинарном дереве.
	 * @param item Значение.
	 * @return Возвращает указатель на сегмент.
	*/
	T Find(T item)
	{
		return FindSegment(item)->GetItem();
	}

	/**
	 * @brief Находит максимальное значение в бинарном дереве.
	 * @return Максимальное значение.
	*/
	T FindMax()
	{
		if (_root == nullptr)
		{
			throw _emptyTreeException;
		}
		else
		{
			TreeSegment<T>* pointer = _root;
			while (pointer->GetRight() != nullptr)
			{
				pointer = pointer->GetRight();
			}
			return pointer->GetItem();
		}
	}

	/**
	 * @brief Находит минимальное значение в бинарном дереве.
	 * @return Минимальное значение.
	*/
	T FindMin()
	{
		return FindMinSegment(_root)->GetItem();
	}

	/**
	 * @brief Осуществляет обход дерева в ширину, вызывая функцию для каждого элемента и уровня
	 * вложенности.
	 * @tparam F Тип функции.
	 * @param function Функция.
	*/
	template <class F>
	void PreorderTraverse(F function)
	{
		InorderTraverseByPointerWithIndex(_root, function, 0);
	}
};

/**
 * @brief Выводит бинарное дерево в поток вывода.
 * @tparam T Тип данных.
 * @param stream Поток вывода.
 * @param binaryTree Бинарное дерево.
 * @return Поток с выводом бинарного дерева.
*/
template<class T>
ostream& operator<<(ostream& stream, BinaryTree<T> binaryTree)
{
	binaryTree.PreorderTraverse([&](TreeSegment<T>* pointer, int level)
		{
			for(int n = 0; n < level; ++n)
			{
				stream << "\t";
			}
			stream << pointer->GetItem() << "\n";
		});
	return stream;
}