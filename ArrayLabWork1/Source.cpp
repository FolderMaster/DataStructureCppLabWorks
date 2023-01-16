#include "DynamicArray.h"
#include "StaticArray.h"
#include "Functions.h"

/**
 * @brief Сортирует массив по убыванию с функцией IsMore.
 * @param array Массив.
*/
void SortWithIsMore(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	array.Sort(IsMore);

	PrintValues("Отсортированный по убыванию массив:\n", array);
}

/**
 * @brief Сортирует массив по возрастанию с функцией IsLess.
 * @param array Массив.
*/
void SortWithIsLess(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	array.Sort(IsLess);

	PrintValues("Отсортированный по возрастанию массив:\n", array);
}

/**
 * @brief Добавляет значение в конец массива.
 * @param array Массив.
*/
void AddEnd(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int value = SetValue<int>("Введите значение для добавления в конец:");
	array.AddEnd(value);

	PrintValues("Массив с добавлением в конце:\n", array);
}

/**
 * @brief Добавляет значение в начало массива.
 * @param array Массив.
*/
void AddBegin(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int value = SetValue<int>("Введите значение для добавления в начале:");
	array.AddBegin(value);

	PrintValues("Массив с добавлением в начале:\n", array);
}

/**
 * @brief Добавлет значение в массив по индексу.
 * @param array Массив.
*/
void Add(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int value = SetValue<int>("Введите значение для добавления:");
	int index = SetValue<int>("Введите индекс для добавления:");

	try
	{
		array.Add(value, index);
		PrintValues("Массив с добавлением по индексу:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Добалвет значение в массив после элемента по индексу.
 * @param array Массив.
*/
void AddAfter(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int value = SetValue<int>("Введите значение для добавления:");
	int index = SetValue<int>("Введите индекс для добавления:");

	try
	{
		array.AddAfter(value, index);
		PrintValues("Массив с добавлением после индексу:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет элемент из начала массива.
 * @param array Массив.
*/
void RemoveBegin(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	try
	{
		array.RemoveBegin();
		PrintValues("Массив с удалением в начале:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет элемент из конца массива.
 * @param array Массив.
*/
void RemoveEnd(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	try
	{
		array.RemoveEnd();
		PrintValues("Массив с удалением в конце:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет элемент из массива по индексу.
 * @param array Массив.
*/
void Remove(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int index = SetValue<int>("Введите индекс для удаления:");

	try
	{
		array.Remove(index);
		PrintValues("Массив с удалением:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Осуществляет линейный поиск индекса значения массива.
 * @param array Массив.
*/
void LinearFindIndex(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int item = SetValue<int>("Введите элемент для линейного поиска индекса:");

	int index = array.LinearFindIndex(item);
	if (index == -1)
	{
		PrintValues("Элемент ", item, " НЕ найден");
	}
	else
	{
		PrintValues("Элемент ", item, " найден под индексом ", index);
	}
}

/**
 * @brief Осуществляет бинарный поиск индекса значения массива с функцией IsMore.
 * @param array Массив.
*/
void BinaryFindIndexWithIsMore(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int item = SetValue<int>("Введите элемент для бинарного поиска индекса для убывающего массива:");

	int index = array.BinaryFindIndex(item, IsMore);
	if (index == -1)
	{
		PrintValues("Элемент ", item, " НЕ найден");
	}
	else
	{
		PrintValues("Элемент ", item, " найден под индексом ", index);
	}
}

/**
 * @brief Осуществляет бинарный поиск индекса значения массива с функцией IsLess.
 * @param array Массив.
*/
void BinaryFindIndexWithIsLess(DynamicArray<int>& array)
{
	PrintValues("Массив:\n", array);

	int item = SetValue<int>("Введите элемент для бинарного поиска индекса для возрастающего массива:");

	int index = array.BinaryFindIndex(item, IsLess);
	if (index == -1)
	{
		PrintValues("Элемент ", item, " НЕ найден");
	}
	else
	{
		PrintValues("Элемент ", item, " найден под индексом ", index);
	}
}

/**
 * @brief Функция входа в приложение.
 * @return Правильно ли отработала программа.
*/
int main()
{
	setlocale(LC_ALL, "ru-RU");

	void (*functionArray[])(DynamicArray<int>&) {
		SortWithIsLess, SortWithIsMore, AddBegin, AddEnd, Add,
			AddAfter, RemoveBegin, RemoveEnd, Remove, LinearFindIndex, BinaryFindIndexWithIsLess,
			BinaryFindIndexWithIsMore
	};
	StaticArray <void(*)(DynamicArray<int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(DynamicArray<int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(SortWithIsLess), NameOf(SortWithIsMore), NameOf(AddBegin),
		NameOf(AddEnd), NameOf(Add), NameOf(AddAfter), NameOf(RemoveBegin), NameOf(RemoveEnd),
		NameOf(Remove), NameOf(LinearFindIndex), NameOf(BinaryFindIndexWithIsLess),
		NameOf(BinaryFindIndexWithIsMore) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	DynamicArray<int> array = DynamicArray<int>();

	while (true)
	{
		cout << "Введите одну из чисел, отвечающих за исполнения заданий (или -1 для выхода):" <<
			endl;
		for (int n = 0; n < stringStaticArray.GetSize(); ++n)
		{
			cout << n << ")" << stringStaticArray[n] << endl;
		}

		int cursor = SetValue<int>();
		
		if (cursor < functionStaticArray.GetSize() && cursor >= 0)
		{
			system("cls");
			functionStaticArray[cursor](array);
			system("pause");
			system("cls");
		}
		else
		{
			if (cursor == -1)
			{
				return 0;
			}
			else
			{
				cout << "Неправильно введённое число (нажмите Enter для продолжения)!" << endl;
			}
		}
	}
}