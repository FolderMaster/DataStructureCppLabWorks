#pragma once

/**
 * @brief ������� ������.
 * @tparam T ��� ������.
*/
template <class T>
class TreeSegment
{
private:
	/**
	 * @brief ��������.
	*/
	T _item;

	/**
	 * @brief ��������� �� ������ �������� �������.
	*/
	TreeSegment<T>* _right = nullptr;

	/**
	 * @brief ��������� �� ����� �������� �������.
	*/
	TreeSegment<T>* _left = nullptr;

	/**
	 * @brief ��������� �� ������������ �������.
	*/
	TreeSegment<T>* _parent = nullptr;
public:
	/**
	 * @brief 
	 * @param item 
	*/
	void SetItem(T item)
	{
		_item = item;
	}

	/**
	 * @brief 
	 * @return 
	*/
	T GetItem()
	{
		return _item;
	}

	/**
	 * @brief 
	 * @param right 
	*/
	void SetRight(TreeSegment<T>* right)
	{
		_right = right;
	}

	/**
	 * @brief 
	 * @return 
	*/
	TreeSegment<T>*& GetRight()
	{
		return _right;
	}

	/**
	 * @brief 
	 * @param left 
	*/
	void SetLeft(TreeSegment<T>* left)
	{
		_left = left;
	}

	/**
	 * @brief 
	 * @return 
	*/
	TreeSegment<T>*& GetLeft()
	{
		return _left;
	}

	/**
	 * @brief 
	 * @param parent 
	*/
	void SetParent(TreeSegment<T>* parent)
	{
		_parent = parent;
	}

	/**
	 * @brief 
	 * @return 
	*/
	TreeSegment<T>*& GetParent()
	{
		return _parent;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param item ��������.
	*/
	TreeSegment(T item)
	{
		_item = item;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param item ��������.
	 * @param parent ��������� �� ������������ �������.
	*/
	TreeSegment(T item, TreeSegment<T>* parent)
	{
		_item = item;
		_parent = parent;
	}

	/**
	 * @brief ������ ��������� ������.
	 * @param item ��������.
	 * @param left ��������� �� ����� �������� �������.
	 * @param right ��������� �� ������ �������� �������.
	*/
	TreeSegment(T item, TreeSegment<T>* left, TreeSegment<T>* right)
	{
		_item = item;
		_left = left;
		_right = right;
	}
};