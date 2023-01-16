#include "DynamicArray.h"
#include "StaticArray.h"
#include "Functions.h"

/**
 * @brief ��������� ������ �� �������� � �������� IsMore.
 * @param array ������.
*/
void SortWithIsMore(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	array.Sort(IsMore);

	PrintValues("��������������� �� �������� ������:\n", array);
}

/**
 * @brief ��������� ������ �� ����������� � �������� IsLess.
 * @param array ������.
*/
void SortWithIsLess(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	array.Sort(IsLess);

	PrintValues("��������������� �� ����������� ������:\n", array);
}

/**
 * @brief ��������� �������� � ����� �������.
 * @param array ������.
*/
void AddEnd(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int value = SetValue<int>("������� �������� ��� ���������� � �����:");
	array.AddEnd(value);

	PrintValues("������ � ����������� � �����:\n", array);
}

/**
 * @brief ��������� �������� � ������ �������.
 * @param array ������.
*/
void AddBegin(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int value = SetValue<int>("������� �������� ��� ���������� � ������:");
	array.AddBegin(value);

	PrintValues("������ � ����������� � ������:\n", array);
}

/**
 * @brief �������� �������� � ������ �� �������.
 * @param array ������.
*/
void Add(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int value = SetValue<int>("������� �������� ��� ����������:");
	int index = SetValue<int>("������� ������ ��� ����������:");

	try
	{
		array.Add(value, index);
		PrintValues("������ � ����������� �� �������:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief �������� �������� � ������ ����� �������� �� �������.
 * @param array ������.
*/
void AddAfter(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int value = SetValue<int>("������� �������� ��� ����������:");
	int index = SetValue<int>("������� ������ ��� ����������:");

	try
	{
		array.AddAfter(value, index);
		PrintValues("������ � ����������� ����� �������:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� �� ������ �������.
 * @param array ������.
*/
void RemoveBegin(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	try
	{
		array.RemoveBegin();
		PrintValues("������ � ��������� � ������:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� �� ����� �������.
 * @param array ������.
*/
void RemoveEnd(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	try
	{
		array.RemoveEnd();
		PrintValues("������ � ��������� � �����:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ������� �� ������� �� �������.
 * @param array ������.
*/
void Remove(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int index = SetValue<int>("������� ������ ��� ��������:");

	try
	{
		array.Remove(index);
		PrintValues("������ � ���������:\n", array);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������������ �������� ����� ������� �������� �������.
 * @param array ������.
*/
void LinearFindIndex(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int item = SetValue<int>("������� ������� ��� ��������� ������ �������:");

	int index = array.LinearFindIndex(item);
	if (index == -1)
	{
		PrintValues("������� ", item, " �� ������");
	}
	else
	{
		PrintValues("������� ", item, " ������ ��� �������� ", index);
	}
}

/**
 * @brief ������������ �������� ����� ������� �������� ������� � �������� IsMore.
 * @param array ������.
*/
void BinaryFindIndexWithIsMore(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int item = SetValue<int>("������� ������� ��� ��������� ������ ������� ��� ���������� �������:");

	int index = array.BinaryFindIndex(item, IsMore);
	if (index == -1)
	{
		PrintValues("������� ", item, " �� ������");
	}
	else
	{
		PrintValues("������� ", item, " ������ ��� �������� ", index);
	}
}

/**
 * @brief ������������ �������� ����� ������� �������� ������� � �������� IsLess.
 * @param array ������.
*/
void BinaryFindIndexWithIsLess(DynamicArray<int>& array)
{
	PrintValues("������:\n", array);

	int item = SetValue<int>("������� ������� ��� ��������� ������ ������� ��� ������������� �������:");

	int index = array.BinaryFindIndex(item, IsLess);
	if (index == -1)
	{
		PrintValues("������� ", item, " �� ������");
	}
	else
	{
		PrintValues("������� ", item, " ������ ��� �������� ", index);
	}
}

/**
 * @brief ������� ����� � ����������.
 * @return ��������� �� ���������� ���������.
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
		cout << "������� ���� �� �����, ���������� �� ���������� ������� (��� -1 ��� ������):" <<
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
				cout << "����������� �������� ����� (������� Enter ��� �����������)!" << endl;
			}
		}
	}
}