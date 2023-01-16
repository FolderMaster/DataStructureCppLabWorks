#pragma once

/**
 * @brief —егмент дерева.
 * @tparam T “ип данных.
*/
template <class T>
class TreeSegment
{
private:
	/**
	 * @brief «начение.
	*/
	T _item;

	/**
	 * @brief ”казатель на правый дочерний сегмент.
	*/
	TreeSegment<T>* _right = nullptr;

	/**
	 * @brief ”казатель на левый дочерний сегмент.
	*/
	TreeSegment<T>* _left = nullptr;

	/**
	 * @brief ”казатель на родительский сегмент.
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
	 * @brief —оздаЄт экземпл€р класса.
	 * @param item «начение.
	*/
	TreeSegment(T item)
	{
		_item = item;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param item «начение.
	 * @param parent ”казатель на родительский сегмент.
	*/
	TreeSegment(T item, TreeSegment<T>* parent)
	{
		_item = item;
		_parent = parent;
	}

	/**
	 * @brief —оздаЄт экземпл€р класса.
	 * @param item «начение.
	 * @param left ”казатель на левый дочерний сегмент.
	 * @param right ”казатель на правый дочерний сегмент.
	*/
	TreeSegment(T item, TreeSegment<T>* left, TreeSegment<T>* right)
	{
		_item = item;
		_left = left;
		_right = right;
	}
};