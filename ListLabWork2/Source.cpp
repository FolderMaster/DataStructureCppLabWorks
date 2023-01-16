#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "List.h"

/**
 * @brief Сортирует список по убыванию с функцией IsMore.
 * @param list Список.
*/
void SortWithIsMore(List<int>& list)
{
	PrintValues("Список:\n", list);

	list.Sort(IsMore);

	PrintValues("Отсортированный по убыванию список:\n", list);
}

/**
 * @brief Сортирует список по возрастанию с функцией IsLess.
 * @param list Список.
*/
void SortWithIsLess(List<int>& list)
{
	PrintValues("Список:\n", list);

	list.Sort(IsLess);

	PrintValues("Отсортированный по возрастанию список:\n", list);
}

/**
 * @brief Добавляет значение в начало списка.
 * @param list Список.
*/
void AddBegin(List<int>& list)
{
	PrintValues("Список:\n", list);

	int value = SetValue<int>("Введите значение для добавления в начало:");
	list.AddBegin(value);

	PrintValues("Список с добавлением в начале:\n", list);
}

/**
 * @brief Добавляет значение в конец списка.
 * @param list Список.
*/
void AddEnd(List<int>& list)
{
	PrintValues("Список:\n", list);

	int value = SetValue<int>("Введите значение для добавления в конец:");
	list.AddEnd(value);

	PrintValues("Список с добавлением в конце:\n", list);
}

/**
 * @brief Добавляет значение перед выбранным сегментом по индексу списка.
 * @param list Список.
*/
void AddBefore(List<int>& list)
{
	PrintValues("Список:\n", list);

	int value = SetValue<int>("Введите значение для добавления:");
	int index = SetValue<int>("Введите индекс для добавления:");

	try
	{
		list.AddBefore(value, index);
		PrintValues("Список с добавлением до элемента индекса:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Добавляет значение после выбранного сегмента по индексу списка.
 * @param list Список.
*/
void AddAfter(List<int>& list)
{
	PrintValues("Список:\n", list);

	int value = SetValue<int>("Введите значение для добавления:");
	int index = SetValue<int>("Введите индекс для добавления:");

	try
	{
		list.AddAfter(value, index);
		PrintValues("Список с добавлением поcле элемента индекса:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет значение из начала списка.
 * @param list Список.
*/
void RemoveBegin(List<int>& list)
{
	PrintValues("Список:\n", list);

	try
	{
		list.RemoveBegin();
		PrintValues("Список с удалением в начале:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет значение из конца списка.
 * @param list Список.
*/
void RemoveEnd(List<int>& list)
{
	PrintValues("Список:\n", list);

	try
	{
		list.RemoveEnd();
		PrintValues("Список с удалением в конце:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет выбранный сегмент по индексу из списка.
 * @param list Список.
*/
void Remove(List<int>& list)
{
	PrintValues("Список:\n", list);

	int index = SetValue<int>("Введите индекс для удаления:");

	try
	{
		list.Remove(index);
		PrintValues("Список с удалением по индексу:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Проводит линейный поиск индекса сегмента списка по значению.
 * @param list Список.
*/
void LinearFindIndex(List<int>& list)
{
	PrintValues("Список:\n", list);

	int item = SetValue<int>("Введите элемент для линейного поиска индекса:");

	int index = list.LinearFindIndex(item);
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
 * @brief Записывает измеряемое время функции в файл.
 * @tparam F Тип функций.
 * @param count Количество измерений.
 * @param function Функция.
 * @param filePath Путь к файлу.
*/
template<class F>
void WriteInFileTimeDimension(int count, int step, F function, string filePath)
{
	List<long long> timeList = List<long long>();
	for (int n = 0; n < count; ++n)
	{
		if (n % step == 0)
		{
			timeList.AddEnd(GetTime(function, n));
		}
		else
		{
			function(n);
		}
	}
	WriteInFile(timeList, filePath);
}

/**
 * @brief Измеряет время методов и записывает его в файлы.
 * @param list Список (не используется).
*/
void MeasureMethodTime(List<int>& list)
{
	const int count = 100000;
	const int step = 1000;
	List<int> testList = List<int>();

	WriteInFileTimeDimension(count, step, [&](int index) { testList.AddBegin(0); }, 
		"AddBegin.txt");

	WriteInFileTimeDimension(count, step, [&](int index) { testList.RemoveBegin(); }, 
		"RemoveBegin.txt");

	WriteInFileTimeDimension(count, step, [&](int index) { testList.AddEnd(0); }, "AddEnd.txt");

	WriteInFileTimeDimension(count, step, [&](int index) { testList.RemoveEnd(); }, 
		"RemoveEnd.txt");

	testList.AddBegin(-1);
	testList.AddEnd(-1);
	WriteInFileTimeDimension(count, step, [&](int index) { testList.AddAfter(0, index); },
		"AddAfter.txt");
	testList.Clear();

	testList.AddBegin(-1);
	testList.AddEnd(-1);
	WriteInFileTimeDimension(count, step, [&](int index) { testList.AddBefore(0, index + 1); },
		"AddBefore.txt");

	WriteInFileTimeDimension(count, step, [&](int index) { testList.Remove(count - index - 1); },
		"Remove.txt");
}

/**
 * @brief Функция входа в приложение.
 * @return Правильно ли отработала программа.
*/
int main()
{
	setlocale(LC_ALL, "ru-RU");

	void (*functionArray[])(List<int>&) {
		SortWithIsLess, SortWithIsMore, AddBegin, AddEnd, AddBefore,
			AddAfter, RemoveBegin, RemoveEnd, Remove, LinearFindIndex, MeasureMethodTime};
	StaticArray <void(*)(List<int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(List<int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(SortWithIsLess), NameOf(SortWithIsMore), NameOf(AddBegin),
		NameOf(AddEnd), NameOf(AddBefore), NameOf(AddAfter), NameOf(RemoveBegin), NameOf(RemoveEnd),
		NameOf(Remove), NameOf(LinearFindIndex), NameOf(MeasureMethodTime) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	List<int> list = List<int>();

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
			functionStaticArray[cursor](list);
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
		system("pause");
		system("cls");
	}
}