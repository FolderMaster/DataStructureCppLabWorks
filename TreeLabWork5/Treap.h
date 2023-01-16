#pragma once

#include "BinaryTree.h"
#include "../HashLabWork4/KeyValuePair.h"

/**
 * @brief Декартово дерево.
 * @tparam TKey Тип ключа.
 * @tparam TPriority Тип приоритета.
*/
template<class TKey, class TPriority>
class Treap : public BinaryTree<KeyValuePair<TKey, TPriority>>
{
private:
	/**
	 * @brief Сегмент бинарного дерева.
	*/
	typedef TreeSegment<KeyValuePair<TKey, TPriority>> TreapSegment;

	/**
	 * @brief Разрезает по ключу на правую и левую часть, начиная с сегмента.
	 * @param pointer Указатель на сегмент.
	 * @param key Ключ.
	 * @param left Указатель на левую часть.
	 * @param right Указатель на правую часть.
	*/
	void Split(TreapSegment* pointer, TKey key, TreapSegment*& left, TreapSegment*& right)
	{
		if (pointer == nullptr)
		{
			left = right = nullptr;
		}
		else if (pointer->GetItem().GetKey() < key)
		{
			Split(pointer->GetRight(), key, pointer->GetRight(), right);
			left = pointer;
		}
		else
		{
			Split(pointer->GetLeft(), key, left, pointer->GetLeft());
			right = pointer;
		}
	}

	/**
	 * @brief Сливает правую и левую часть.
	 * @param left Указатель на левую чатсь.
	 * @param right Указатель на правую часть.
	 * @return Указатель на соединение частей.
	*/
	TreapSegment* Merge(TreapSegment*& left, TreapSegment*& right)
	{
		if (left == nullptr)
		{
			return right;
		}
		else if (right == nullptr)
		{
			return left;
		}
		else if (left->GetItem().GetValue() > right->GetItem().GetValue())
		{
			TreapSegment* newRight = Merge(left->GetRight(), right);
			return new TreapSegment(KeyValuePair<TKey, TPriority>(left->GetItem().GetKey(),
				left->GetItem().GetValue()), left->GetLeft(), newRight);
		}
		else
		{
			TreapSegment* newLeft = Merge(left, right->GetLeft());
			return new TreapSegment(KeyValuePair<TKey, TPriority>(right->GetItem().GetKey(),
				right->GetItem().GetValue()), newLeft, right->GetRight());
		}
	}

	/**
	 * @brief Добавить оптимально рекурсивно сегмент, начиная с указателя на сегмент.
	 * @param pointer Указатель на элемент.
	 * @param add Добавляемый сегмент.
	*/
	void RecursivelyOptimalAdd(TreapSegment*& pointer, TreapSegment* add)
	{
		if (!pointer)
		{
			pointer = add;
		}
		else if (add->GetItem().GetValue() > pointer->GetItem().GetValue())
		{
			Split(pointer, add->GetItem().GetKey(), add->GetLeft(), add->GetRight());
			pointer = add;
		}
		else
		{
			if (pointer->GetItem().GetKey() < add->GetItem().GetKey())
			{
				RecursivelyOptimalAdd(pointer->GetRight(), add);
			}
			else
			{
				RecursivelyOptimalAdd(pointer->GetLeft(), add);
			}
		}
	}

	/**
	 * @brief Удалить рекурсивно оптимально сегмент по ключу, начиная с указателя на элемент.
	 * @param pointer Указатель на элемент.
	 * @param key Ключ.
	*/
	void RecursivelyOptimalRemove(TreapSegment*& pointer, TKey key)
	{
		if (!pointer)
		{
			return void();
		}
		if (pointer->GetItem().GetKey() == key)
		{
			TreapSegment* tmp = pointer;
			pointer = Merge(pointer->GetLeft(), pointer->GetRight());
			delete tmp;
		}
		else
		{
			if (pointer->GetItem().GetKey() < key)
			{
				RecursivelyOptimalRemove(pointer->GetRight(), key);
			}
			else
			{
				RecursivelyOptimalRemove(pointer->GetLeft(), key);
			}
		}
	}
public:
	/**
	 * @brief Создаёт экземпляр класса по умолчанию.
	*/
	Treap()
	{
	}

	/**
	 * @brief Создаёт экземпляр класса копированию.
	 * @param other Другое декартово дерево.
	*/
	Treap(const Treap<TKey, TPriority>& other)
	{
		this->Create(other._root);
	}

	/**
	 * @brief Удаляет экземпляр класса.
	*/
	~Treap()
	{
		this->Clear();
	}

	/**
	 * @brief Присваивает другое декартово дерево этому декартову дереву.
	 * @param other Другое декартово дерево.
	 * @return Это декартово дерево после присваения.
	*/
	Treap<TKey, TPriority>& operator=(const Treap<TKey, TPriority>& other)
	{
		if (this != &other)
		{
			this->Clear();
			this->Create(other._root);
		}
		return *this;
	}

	/**
	 * @brief Добавить сегмент со значением.
	 * @param item Значение.
	*/
	void Add(TKey key)
	{
		TreapSegment* left = nullptr;
		TreapSegment* right = nullptr;
		Split(this->_root, key, left, right);
		TreapSegment* add = new TreapSegment(KeyValuePair<TKey, TPriority>(key, rand()));
		TreapSegment* newLeft = Merge(left, add);
		this->_root = Merge(newLeft, right);
	}

	/**
	 * @brief Добавить оптимально сегмент со значением.
	 * @param item Значение.
	*/
	void OptimalAdd(TKey key)
	{
		RecursivelyOptimalAdd(this->_root, new TreapSegment(KeyValuePair<TKey, TPriority>(key,
			rand())));
	}

	/**
	 * @brief Удалить сегмент по ключу.
	 * @param key Ключ.
	*/
	void Remove(TKey key)
	{
		TreapSegment* left = nullptr;
		TreapSegment* right = nullptr;
		TreapSegment* mid = nullptr;
		Split(this->_root, key, left, right);
		TreapSegment* newRight = nullptr;
		Split(right, key + 1, mid, newRight);
		delete mid;
		this->_root = Merge(left, newRight);
	}

	/**
	 * @brief Удалить оптимально сегмент по ключу.
	 * @param key Ключ.
	*/
	void OptimalRemove(TKey key)
	{
		RecursivelyOptimalRemove(this->_root, key);
	}

	/**
	 * @brief Находит значение по ключу в декартовом дереве.
	 * @param key Ключ.
	 * @return Пара ключ-приоритет.
	*/
	KeyValuePair<TKey, TPriority> Find(TKey key)
	{
		return this->FindSegment(KeyValuePair<TKey, TPriority>(key))->GetItem();
	}
};

/**
 * @brief Выводит декартово дерево в поток вывода.
 * @tparam TKey Тип ключа.
 * @tparam TPriority Тип приоритета.
 * @param stream Поток вывода.
 * @param treap Декартово дерево.
 * @return Поток с выводом декартового дерева.
*/
template<class TKey, class TPriority>
ostream& operator<<(ostream& stream, Treap<TKey, TPriority> treap)
{
	treap.PreorderTraverse([&](TreeSegment<KeyValuePair<TKey, TPriority>>* pointer, int level)
		{
			for(int n = 0; n < level; ++n)
			{
				stream << "\t";
			}
			stream << "(" << pointer->GetItem().GetKey() << " " << pointer->GetItem().GetValue()
				<< ")\n";
		});
	return stream;
}