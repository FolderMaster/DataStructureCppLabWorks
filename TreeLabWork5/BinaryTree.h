#pragma once

#include "../ArrayLabWork1/Functions.h"
#include "BinaryTreeSegment.h"

/**
 * @brief �������� ������.
 * @tparam T ��� ������.
*/
template<class T>
class BinaryTree
{
protected:
	/**
	 * @brief ���������� ������� ������.
	*/
	const exception _emptyTreeException = exception("������ ������.");

	/**
	 * @brief ���������� ������������ ������.
	*/
	const exception _notFindException = exception("�� ������� � ������.");

	/**
	 * @brief ������ ������.
	*/
	TreeSegment<T>* _root = nullptr;

	/**
	 * @brief ������ ������.
	 * @param root ������ ������� ������.
	*/
	void Create(TreeSegment<T>* root)
	{
		PreorderTraverseByPointer(root, [&](TreeSegment<T>* pointer) { Add(pointer->GetItem()); });
	}

	/**
	 * @brief ������� ������.
	*/
	void Clear()
	{
		PostorderTraverseByPointer(_root, [&](TreeSegment<T>* pointer) { delete pointer; });
		_root = nullptr;
	}
	
	/**
	 * @brief ������� �������.
	 * @param current ������� ��������� ��������.
	 * @param change ���������� ��������� ��������.
	*/
	void RemoveSegment(TreeSegment<T>* current, TreeSegment<T>* change)
	{
		TreeSegment<T>* parent = ReplaceSegment(current, change);
		delete current;
	}

	/**
	 * @brief �������� ������� � ������������ ��������.
	 * @param current ������� ��������� ��������.
	 * @param change ���������� ��������� ��������.
	 * @return ��������� ������������ �������.
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
	 * @brief ������� ��������� ������� ������������ ��������, ������� � ��������� ��������.
	 * @param pointer ��������� ��������.
	 * @return ��������� ��������� �������� � ����������� ��������.
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
	 * @brief ������� ��������� ������� �� ���������, ������� � ��������� ��������.
	 * @param item ��������.
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
	 * @brief ������������ ������ �����, ������� � ��������� �� �������, ������� ������� ���
	 * ������� ��������.
	 * @tparam F ��� �������.
	 * @param pointer ��������� �� �������.
	 * @param function �������.
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
	 * @brief ������������ �������� �����, ������� � ��������� �� �������, ������� ������� ���
	 * ������� ��������.
	 * @tparam F ��� �������.
	 * @param pointer ��������� �� �������.
	 * @param function �������.
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
	 * @brief ������������ ������������ �����, ������� � ��������� �� �������, ������� ������� ��� 
	 * ������� ��������.
	 * @tparam F ��� �������.
	 * @param pointer ��������� �� �������.
	 * @param function �������.
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
	 * @brief ������������ ������������ �����, ������� � ��������� �� �������, ������� ������� ���
	 * ������� �������� � ������ �����������.
	 * @tparam F ��� �������.
	 * @param pointer ��������� �� �������.
	 * @param function �������.
	 * @param level ������� �����������(���������� �������).
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
	 * @brief ������ ��������� ������ �� ���������.
	*/
	BinaryTree()
	{
	}

	/**
	 * @brief ������ ��������� ������ ������������.
	 * @param other ������ �������� ������.
	*/
	BinaryTree(const BinaryTree<T>& other)
	{
		Create(other._root);
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~BinaryTree()
	{
		Clear();
	}

	/**
	 * @brief ����������� ������ �������� ������ ����� ��������� ������.
	 * @param other ������ �������� ������.
	 * @return ��� �������� ������ ����� ����������.
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
	 * @brief ��������� �������� � �������� ������.
	 * @param item ��������.
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
	 * @brief ������� ������� �������� �� ��������� ������.
	 * @param item ��������.
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
	 * @brief ������� ������� �������� � �������� ������.
	 * @param item ��������.
	 * @return ���������� ��������� �� �������.
	*/
	T Find(T item)
	{
		return FindSegment(item)->GetItem();
	}

	/**
	 * @brief ������� ������������ �������� � �������� ������.
	 * @return ������������ ��������.
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
	 * @brief ������� ����������� �������� � �������� ������.
	 * @return ����������� ��������.
	*/
	T FindMin()
	{
		return FindMinSegment(_root)->GetItem();
	}

	/**
	 * @brief ������������ ����� ������ � ������, ������� ������� ��� ������� �������� � ������
	 * �����������.
	 * @tparam F ��� �������.
	 * @param function �������.
	*/
	template <class F>
	void PreorderTraverse(F function)
	{
		InorderTraverseByPointerWithIndex(_root, function, 0);
	}
};

/**
 * @brief ������� �������� ������ � ����� ������.
 * @tparam T ��� ������.
 * @param stream ����� ������.
 * @param binaryTree �������� ������.
 * @return ����� � ������� ��������� ������.
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