#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "List.h"

/**
 * @brief ��������� ������ �� �������� � �������� IsMore.
 * @param list ������.
*/
void SortWithIsMore(List<int>& list)
{
	PrintValues("������:\n", list);

	list.Sort(IsMore);

	PrintValues("��������������� �� �������� ������:\n", list);
}

/**
 * @brief ��������� ������ �� ����������� � �������� IsLess.
 * @param list ������.
*/
void SortWithIsLess(List<int>& list)
{
	PrintValues("������:\n", list);

	list.Sort(IsLess);

	PrintValues("��������������� �� ����������� ������:\n", list);
}

/**
 * @brief ��������� �������� � ������ ������.
 * @param list ������.
*/
void AddBegin(List<int>& list)
{
	PrintValues("������:\n", list);

	int value = SetValue<int>("������� �������� ��� ���������� � ������:");
	list.AddBegin(value);

	PrintValues("������ � ����������� � ������:\n", list);
}

/**
 * @brief ��������� �������� � ����� ������.
 * @param list ������.
*/
void AddEnd(List<int>& list)
{
	PrintValues("������:\n", list);

	int value = SetValue<int>("������� �������� ��� ���������� � �����:");
	list.AddEnd(value);

	PrintValues("������ � ����������� � �����:\n", list);
}

/**
 * @brief ��������� �������� ����� ��������� ��������� �� ������� ������.
 * @param list ������.
*/
void AddBefore(List<int>& list)
{
	PrintValues("������:\n", list);

	int value = SetValue<int>("������� �������� ��� ����������:");
	int index = SetValue<int>("������� ������ ��� ����������:");

	try
	{
		list.AddBefore(value, index);
		PrintValues("������ � ����������� �� �������� �������:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ��������� �������� ����� ���������� �������� �� ������� ������.
 * @param list ������.
*/
void AddAfter(List<int>& list)
{
	PrintValues("������:\n", list);

	int value = SetValue<int>("������� �������� ��� ����������:");
	int index = SetValue<int>("������� ������ ��� ����������:");

	try
	{
		list.AddAfter(value, index);
		PrintValues("������ � ����������� ��c�� �������� �������:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� �������� �� ������ ������.
 * @param list ������.
*/
void RemoveBegin(List<int>& list)
{
	PrintValues("������:\n", list);

	try
	{
		list.RemoveBegin();
		PrintValues("������ � ��������� � ������:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� �������� �� ����� ������.
 * @param list ������.
*/
void RemoveEnd(List<int>& list)
{
	PrintValues("������:\n", list);

	try
	{
		list.RemoveEnd();
		PrintValues("������ � ��������� � �����:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ��������� ������� �� ������� �� ������.
 * @param list ������.
*/
void Remove(List<int>& list)
{
	PrintValues("������:\n", list);

	int index = SetValue<int>("������� ������ ��� ��������:");

	try
	{
		list.Remove(index);
		PrintValues("������ � ��������� �� �������:\n", list);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief �������� �������� ����� ������� �������� ������ �� ��������.
 * @param list ������.
*/
void LinearFindIndex(List<int>& list)
{
	PrintValues("������:\n", list);

	int item = SetValue<int>("������� ������� ��� ��������� ������ �������:");

	int index = list.LinearFindIndex(item);
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
 * @brief ���������� ���������� ����� ������� � ����.
 * @tparam F ��� �������.
 * @param count ���������� ���������.
 * @param function �������.
 * @param filePath ���� � �����.
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
 * @brief �������� ����� ������� � ���������� ��� � �����.
 * @param list ������ (�� ������������).
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
 * @brief ������� ����� � ����������.
 * @return ��������� �� ���������� ���������.
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
				cout << "����������� �������� ����� (������� Enter ��� �����������)!" << endl;
			}
		}
		system("pause");
		system("cls");
	}
}