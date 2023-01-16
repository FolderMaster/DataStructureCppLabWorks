#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "BinaryTree.h"
#include "Treap.h"

/**
 * @brief Добавляет значение в бинарное дерево.
 * @param binaryTree Бинарное дерево.
*/
void BinaryTreeAdd(BinaryTree<int>& binaryTree)
{
	PrintValues("Бинарное дерево:\n", binaryTree);

	int value = SetValue<int>("Введите значение для добавления в бинарное дерево:");

	binaryTree.Add(value);
	PrintValues("Бинарное дерево с добавлением:\n", binaryTree);
}

/**
 * @brief Удаляет сегмент значения из бинарного дерева.
 * @param binaryTree Бинарное дерево.
*/
void BinaryTreeRemove(BinaryTree<int>& binaryTree)
{
	PrintValues("Бинарное дерево:\n", binaryTree);

	int value = SetValue<int>("Введите значение для удаления из бинарного дерева:");

	try
	{
		binaryTree.Remove(value);
		PrintValues("Бинарное дерево с удалением:\n", binaryTree);
	}
	catch(exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит сегмент значения бинарного дерева.
 * @param binaryTree Бинарное дерево.
*/
void BinaryTreeFind(BinaryTree<int>& binaryTree)
{
	PrintValues("Бинарное дерево:\n", binaryTree);

	int value = SetValue<int>("Введите значение для поиска в бинарном дереве:");

	try
	{
		int find = binaryTree.Find(value);
		PrintValues("Найденное значение:\n", find);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит сегмент минимального значения бинарного дерева.
 * @param binaryTree Бинарное дерево.
*/
void BinaryTreeFindMin(BinaryTree<int>& binaryTree)
{
	PrintValues("Бинарное дерево:\n", binaryTree);

	try
	{
		int value = binaryTree.FindMin();
		PrintValues("Найденное минимальное значение:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит сегмент максимального значения бинарного дерева.
 * @param binaryTree Бинарное дерево.
*/
void BinaryTreeFindMax(BinaryTree<int>& binaryTree)
{
	PrintValues("Бинарное дерево:\n", binaryTree);

	try
	{
		int value = binaryTree.FindMax();
		PrintValues("Найденное максимальное значение:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Добавляет значение в декартово дерево.
 * @param treap Декартово дерево.
*/
void TreapAdd(Treap<int, int>& treap)
{
	PrintValues("Декартово дерево:\n", treap);

	int key = SetValue<int>("Введите значение для добавления в декартово дерево:");

	treap.Add(key);
	PrintValues("Декартово дерево с добавлением:\n", treap);
}

/**
 * @brief Добавляет оптимально значение в декартово дерево.
 * @param treap Декартово дерево.
*/
void TreapOptimalAdd(Treap<int, int>& treap)
{
	PrintValues("Декартово дерево:\n", treap);

	int key = SetValue<int>("Введите значение для оптимального добавления в декартово дерево:");

	treap.OptimalAdd(key);
	PrintValues("Декартово дерево с оптимальным добавлением:\n", treap);
}

/**
 * @brief Удаляет сегмент значения из декартового дерева.
 * @param treap Декартово дерево.
*/
void TreapRemove(Treap<int, int>& treap)
{
	PrintValues("Декартово дерево:\n", treap);

	int key = SetValue<int>("Введите ключ для удаления в декартово дерево:");

	try
	{
		treap.Remove(key);
		PrintValues("Бинарное дерево с удалением:\n", treap);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет оптимально сегмент значения из бинарного дерева.
 * @param treap Декартово дерево.
*/
void TreapOptimalRemove(Treap<int, int>& treap)
{
	PrintValues("Декартово дерево:\n", treap);

	int key = SetValue<int>("Введите ключ для оптимального удаления в декартово дерево:");

	try
	{
		treap.OptimalRemove(key);
		PrintValues("Бинарное дерево с оптимальным удалением:\n", treap);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит сегмент значения декартового дерева.
 * @param treap Декартово дерево.
*/
void TreapFind(Treap<int, int>& treap)
{
	PrintValues("Декартово дерево:\n", treap);

	int key = SetValue<int>("Введите ключ для удаления в декартово дерево:");

	try
	{
		KeyValuePair<int, int> pair = treap.Find(key);
		PrintValues("Найденное значение (пара ключ-приоритет):\n", pair);

	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Создаёт меню бинарного дерева.
 * @param binaryTree Бинарное дерево.
 * @param treap Декартово дерево (не исопльзуется!).
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
 * @brief Создаёт меню декартова дерева.
 * @param binaryTree Бинарное дерево (не исопльзуется!).
 * @param treap Декартово дерево.
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
 * @brief Функция входа в приложение.
 * @return Правильно ли отработала программа.
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