#pragma once
#include <iostream>

#include "StaticArray.h"
#include "Functions.h"

using namespace std;

//1.1.2.1

void Task1121()
{
	int array[]{ 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };
	StaticArray<int, sizeof(array) / sizeof(array[0])> staticArray =
		StaticArray<int, sizeof(array) / sizeof(array[0])>(array);

	PrintValues("Массив:\n", staticArray);

	staticArray.Sort();

	PrintValues("Отсортированный массив:\n", staticArray);
}

//1.1.2.2

void Task1122()
{
	double array[]{ 11.5, -2.2, 8.6, 3.9, 1.9, -7.3, 5.5, 6.0, -4.5, 9.8, 0, 10.7 };
	StaticArray<double, sizeof(array) / sizeof(array[0])> staticArray =
		StaticArray<double, sizeof(array) / sizeof(array[0])>(array);

	PrintValues("Массив:\n", staticArray);

	double searchingItem;
	SetValue(searchingItem, "Введите искомый элемент:");

	PrintValues("Найдено ", staticArray.FindCount(searchingItem, IsEqualsOrMore),
		" элементов больше или равно ", searchingItem);
}

//1.1.2.3

void Task1123()
{
	const int size = 8;
	StaticArray<char, size> staticArray = StaticArray<char, size>();
	SetValue(staticArray, "Введите массив символов из ", size, " элементов:");

	PrintValues("Массив:\n", staticArray);

	cout << "Массив букв:" << endl;
	for (int n = 0; n < staticArray.GetSize(); ++n)
	{
		if (IsLetter(staticArray[n]))
		{
			cout << staticArray[n] << " ";
		}
	}
	cout << endl;
}