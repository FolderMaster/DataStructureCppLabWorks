#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "BinaryTree.h"
#include "Treap.h"

/**
 * @brief ��������� �������� � �������� ������.
 * @param binaryTree �������� ������.
*/
void BinaryTreeAdd(BinaryTree<int>& binaryTree)
{
	PrintValues("�������� ������:\n", binaryTree);

	int value = SetValue<int>("������� �������� ��� ���������� � �������� ������:");

	binaryTree.Add(value);
	PrintValues("�������� ������ � �����������:\n", binaryTree);
}

/**
 * @brief ������� ������� �������� �� ��������� ������.
 * @param binaryTree �������� ������.
*/
void BinaryTreeRemove(BinaryTree<int>& binaryTree)
{
	PrintValues("�������� ������:\n", binaryTree);

	int value = SetValue<int>("������� �������� ��� �������� �� ��������� ������:");

	try
	{
		binaryTree.Remove(value);
		PrintValues("�������� ������ � ���������:\n", binaryTree);
	}
	catch(exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� �������� ��������� ������.
 * @param binaryTree �������� ������.
*/
void BinaryTreeFind(BinaryTree<int>& binaryTree)
{
	PrintValues("�������� ������:\n", binaryTree);

	int value = SetValue<int>("������� �������� ��� ������ � �������� ������:");

	try
	{
		int find = binaryTree.Find(value);
		PrintValues("��������� ��������:\n", find);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� ������������ �������� ��������� ������.
 * @param binaryTree �������� ������.
*/
void BinaryTreeFindMin(BinaryTree<int>& binaryTree)
{
	PrintValues("�������� ������:\n", binaryTree);

	try
	{
		int value = binaryTree.FindMin();
		PrintValues("��������� ����������� ��������:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� ������������� �������� ��������� ������.
 * @param binaryTree �������� ������.
*/
void BinaryTreeFindMax(BinaryTree<int>& binaryTree)
{
	PrintValues("�������� ������:\n", binaryTree);

	try
	{
		int value = binaryTree.FindMax();
		PrintValues("��������� ������������ ��������:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ��������� �������� � ��������� ������.
 * @param treap ��������� ������.
*/
void TreapAdd(Treap<int, int>& treap)
{
	PrintValues("��������� ������:\n", treap);

	int key = SetValue<int>("������� �������� ��� ���������� � ��������� ������:");

	treap.Add(key);
	PrintValues("��������� ������ � �����������:\n", treap);
}

/**
 * @brief ��������� ���������� �������� � ��������� ������.
 * @param treap ��������� ������.
*/
void TreapOptimalAdd(Treap<int, int>& treap)
{
	PrintValues("��������� ������:\n", treap);

	int key = SetValue<int>("������� �������� ��� ������������ ���������� � ��������� ������:");

	treap.OptimalAdd(key);
	PrintValues("��������� ������ � ����������� �����������:\n", treap);
}

/**
 * @brief ������� ������� �������� �� ����������� ������.
 * @param treap ��������� ������.
*/
void TreapRemove(Treap<int, int>& treap)
{
	PrintValues("��������� ������:\n", treap);

	int key = SetValue<int>("������� ���� ��� �������� � ��������� ������:");

	try
	{
		treap.Remove(key);
		PrintValues("�������� ������ � ���������:\n", treap);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ���������� ������� �������� �� ��������� ������.
 * @param treap ��������� ������.
*/
void TreapOptimalRemove(Treap<int, int>& treap)
{
	PrintValues("��������� ������:\n", treap);

	int key = SetValue<int>("������� ���� ��� ������������ �������� � ��������� ������:");

	try
	{
		treap.OptimalRemove(key);
		PrintValues("�������� ������ � ����������� ���������:\n", treap);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� �������� ����������� ������.
 * @param treap ��������� ������.
*/
void TreapFind(Treap<int, int>& treap)
{
	PrintValues("��������� ������:\n", treap);

	int key = SetValue<int>("������� ���� ��� �������� � ��������� ������:");

	try
	{
		KeyValuePair<int, int> pair = treap.Find(key);
		PrintValues("��������� �������� (���� ����-���������):\n", pair);

	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������ ���� ��������� ������.
 * @param binaryTree �������� ������.
 * @param treap ��������� ������ (�� ������������!).
*/
void BinaryTreeMenu(BinaryTree<int>& binaryTree, Treap<int, int>& treap)
{
	void (*functionArray[])(BinaryTree<int>&) { BinaryTreeAdd, BinaryTreeRemove, BinaryTreeFind,
		BinaryTreeFindMin, BinaryTreeFindMax };
	StaticArray <void(*)(BinaryTree<int>&), sizeof(functionArray) / sizeof(functionArray[0])> 
		functionStaticArray = StaticArray<void(*)(BinaryTree<int>&), sizeof(functionArray) / 
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[] { NameOf(BinaryTreeAdd), NameOf(BinaryTreeRemove),
		NameOf(BinaryTreeFind), NameOf(BinaryTreeFindMin), NameOf(BinaryTreeFindMax) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, binaryTree);
}

/**
 * @brief ������ ���� ��������� ������.
 * @param binaryTree �������� ������ (�� ������������!).
 * @param treap ��������� ������.
*/
void TreapMenu(BinaryTree<int>& binaryTree, Treap<int, int>& treap)
{
	void (*functionArray[])(Treap<int, int>&) { TreapAdd, TreapOptimalAdd, TreapRemove, 
		TreapOptimalRemove, TreapFind };
	StaticArray <void(*)(Treap<int, int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(Treap<int, int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(TreapAdd), NameOf(TreapOptimalAdd), NameOf(TreapRemove), 
		NameOf(TreapOptimalRemove), NameOf(TreapFind) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, treap);
}

/**
 * @brief ������� ����� � ����������.
 * @return ��������� �� ���������� ���������.
*/
int main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(0));

	void (*functionArray[])(BinaryTree<int>&, Treap<int, int>&)
	{ BinaryTreeMenu, TreapMenu };
	StaticArray <void(*)(BinaryTree<int>&, Treap<int, int>&), sizeof(functionArray) /
		sizeof(functionArray[0])> functionStaticArray = StaticArray<void(*)(BinaryTree<int>&, 
		Treap<int, int>&), sizeof(functionArray) / sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(BinaryTreeMenu), NameOf(TreapMenu) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	BinaryTree<int> binaryTree = BinaryTree<int>();
	Treap<int, int> treap = Treap<int, int>();

	CreateMenu(functionStaticArray, stringStaticArray, false, binaryTree, treap);
}