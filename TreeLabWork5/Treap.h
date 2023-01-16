#pragma once

#include "BinaryTree.h"
#include "../HashLabWork4/KeyValuePair.h"

/**
 * @brief ��������� ������.
 * @tparam TKey ��� �����.
 * @tparam TPriority ��� ����������.
*/
template<class TKey, class TPriority>
class Treap : public BinaryTree<KeyValuePair<TKey, TPriority>>
{
private:
	/**
	 * @brief ������� ��������� ������.
	*/
	typedef TreeSegment<KeyValuePair<TKey, TPriority>> TreapSegment;

	/**
	 * @brief ��������� �� ����� �� ������ � ����� �����, ������� � ��������.
	 * @param pointer ��������� �� �������.
	 * @param key ����.
	 * @param left ��������� �� ����� �����.
	 * @param right ��������� �� ������ �����.
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
	 * @brief ������� ������ � ����� �����.
	 * @param left ��������� �� ����� �����.
	 * @param right ��������� �� ������ �����.
	 * @return ��������� �� ���������� ������.
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
	 * @brief �������� ���������� ���������� �������, ������� � ��������� �� �������.
	 * @param pointer ��������� �� �������.
	 * @param add ����������� �������.
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
	 * @brief ������� ���������� ���������� ������� �� �����, ������� � ��������� �� �������.
	 * @param pointer ��������� �� �������.
	 * @param key ����.
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
	 * @brief ������ ��������� ������ �� ���������.
	*/
	Treap()
	{
	}

	/**
	 * @brief ������ ��������� ������ �����������.
	 * @param other ������ ��������� ������.
	*/
	Treap(const Treap<TKey, TPriority>& other)
	{
		this->Create(other._root);
	}

	/**
	 * @brief ������� ��������� ������.
	*/
	~Treap()
	{
		this->Clear();
	}

	/**
	 * @brief ����������� ������ ��������� ������ ����� ��������� ������.
	 * @param other ������ ��������� ������.
	 * @return ��� ��������� ������ ����� ����������.
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
	 * @brief �������� ������� �� ���������.
	 * @param item ��������.
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
	 * @brief �������� ���������� ������� �� ���������.
	 * @param item ��������.
	*/
	void OptimalAdd(TKey key)
	{
		RecursivelyOptimalAdd(this->_root, new TreapSegment(KeyValuePair<TKey, TPriority>(key,
			rand())));
	}

	/**
	 * @brief ������� ������� �� �����.
	 * @param key ����.
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
	 * @brief ������� ���������� ������� �� �����.
	 * @param key ����.
	*/
	void OptimalRemove(TKey key)
	{
		RecursivelyOptimalRemove(this->_root, key);
	}

	/**
	 * @brief ������� �������� �� ����� � ���������� ������.
	 * @param key ����.
	 * @return ���� ����-���������.
	*/
	KeyValuePair<TKey, TPriority> Find(TKey key)
	{
		return this->FindSegment(KeyValuePair<TKey, TPriority>(key))->GetItem();
	}
};

/**
 * @brief ������� ��������� ������ � ����� ������.
 * @tparam TKey ��� �����.
 * @tparam TPriority ��� ����������.
 * @param stream ����� ������.
 * @param treap ��������� ������.
 * @return ����� � ������� ����������� ������.
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