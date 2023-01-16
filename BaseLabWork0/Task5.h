#pragma once
#include <iostream>

#include "Functions.h"
#include "DynamicArray.h"

using namespace std;

//1.1.5.1

void Task1151()
{
	int size = 8;
	double* pointer = new double[size] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5};
	DynamicArray<double> dynamicArray = DynamicArray<double>(size, pointer);
	delete[] pointer;

	PrintValues("������ �� double:\n", dynamicArray);
}

//1.1.5.2

void Task1152()
{
	int size = 8;
	bool* pointer = new bool[size] {true, false, true, true, false, true, false, false};
	DynamicArray<bool> dynamicArray = DynamicArray<bool>(size, pointer);
	delete[] pointer;

	PrintValues("������ �� bool:\n", dynamicArray);
}

//1.1.5.3

void Task1153()
{
	int size;
	SetValue(size, "������� ���������� ��������� � �������:");

	DynamicArray<char> dynamicArray = DynamicArray<char>(size);
	SetValue(dynamicArray, "������� �������� �������:");

	PrintValues("������:\n", dynamicArray);

	PrintValues("������ ����:");
	PrintDynamicArrayWithFunctor(dynamicArray, IsLetter);
}

//1.1.5.4

void Task1154()
{
	int size = 10;
	double* pointer = new double[size] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5};
	DynamicArray<double> dynamicArray = DynamicArray<double>(size, pointer);
	delete[] pointer;

	PrintValues("������:\n", dynamicArray);

	dynamicArray.Sort();

	PrintValues("��������������� ������:\n", dynamicArray);
}

//1.1.5.5

void Task1155()
{
	int size = 10;
	int* pointer = new int[size] {1, 15, -8, -3, 12, 38, 0, 4, 16, 4};
	DynamicArray<int> dynamicArray = DynamicArray<int>(size, pointer);
	delete[] pointer;

	PrintValues("������:\n", dynamicArray);

	int searchingItem;
	SetValue(searchingItem, "������� ������� �������:");

	int searchingItemIndex = dynamicArray.FindIndex(searchingItem);
	if (searchingItemIndex == -1)
	{
		PrintValues("�� ������� ��������, ������� ", searchingItem);
	}
	else
	{
		PrintValues("������ ������� ��� �������� ", searchingItemIndex, ", ������ ",
			searchingItem);
	}
}

//1.1.5.6

void Task1156()
{
	int size = 15;
	char* pointer = new char[size]
	{'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k'};
	DynamicArray<char> dynamicArray = DynamicArray<char>(size, pointer);
	delete[] pointer;

	PrintValues("������:\n", dynamicArray);

	PrintValues("����� ���� � ������� - ", dynamicArray.FindCount(IsLetter), ":");
	PrintDynamicArrayWithFunctor(dynamicArray, IsLetter);
}

//1.1.5.7

void Task1157()
{
	int size = 5;
	DynamicArray<int> dynamicArray = CreateRandomDynamicArray<int>(size);

	PrintValues("������:\n", dynamicArray);

	system("pause");

	size = 8;
	dynamicArray = CreateRandomDynamicArray<int>(size);

	PrintValues("������:\n", dynamicArray);

	system("pause");

	size = 13;
	dynamicArray = CreateRandomDynamicArray<int>(size);

	PrintValues("������:\n", dynamicArray);
}

//1.1.5.8

int* ReadArray(int count)
{
	int* values = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> values[i];
	}
	return values;
}
int CountPositiveValues(int* values, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}
	return result;
}

void Task1158()
{
	int count = 15;
	int* values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;
	//���������� ������ ������ ��� ���� ������� ����:
	delete[] values;

	count = 20;
	values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;
	delete[] values;
}