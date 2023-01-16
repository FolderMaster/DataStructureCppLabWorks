#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

/*��������� ������ �� ���� ����, ��� ��������� ������.*/
#define NameOf(name) #name

/**
 * @brief ��������� ������ �� �������� a, ��� �������� b.
 * @tparam T ��� ������.
 * @param a �������� a.
 * @param b �������� b.
 * @return ���������� ��������, ����������� ������ �� �������� a, ��� �������� b.
*/
template<class T>
bool IsMore(T a, T b)
{
	return a > b;
}

/**
 * @brief ��������� ������ �� �������� a, ��� �������� b.
 * @tparam T ��� ������.
 * @param a �������� a.
 * @param b �������� b.
 * @return ���������� ��������, ����������� ������ �� �������� a, ��� �������� b.
*/
template<class T>
bool IsLess(T a, T b)
{
	return a < b;
}

/**
 * @brief ������� ��������.
 * @tparam T ��� ������.
 * @param value �������� ��� ������.
*/
template<class T>
void PrintValues(T value)
{
	cout << value << endl;
}

/**
 * @brief ������� ��������.
 * @tparam T ��� ������ ��� �������� ������.
 * @tparam ...Args ���� ������ ��� ����������� ������.
 * @param value �������� ��� �������� ������.
 * @param ...values �������� ��� ����������� ������.
*/
template<class T, class... Args>
void PrintValues(T& value, Args... values)
{
	cout << value;
	PrintValues(values...);
}

/**
 * @brief ������ ��������.
 * @tparam T ��� ������.
*/
template <class T>
T SetValue()
{
	T value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "�������� ������!\n";
			continue;
		}

		cin.ignore(cin.rdbuf()->in_avail());
		if (cin.gcount() > 1)
		{
			cout << "�������� ������!\n";
			continue;
		}

		break;
	}
	return value;
}

/**
 * @brief ������������� ����� �������� � ���� ��������.
 * @tparam T ��� ������ �������� ��� �����.
 * @tparam ...Args ���� ������ ��� ������.
 * @param ...message �������� ��� ������.
*/
template <class T, class... Args>
T SetValue(Args... message)
{
	PrintValues(message...);
	return SetValue<T>();
}

/**
 * @brief �������� ����� �� ����������� �������.
 * @tparam F ��� �������.
 * @tparam ...Args ���� ����������.
 * @param function �������.
 * @param ...args ���������.
 * @return ����� � ������������.
*/
template<class F, class... Args>
long long GetTime(F function, Args... args)
{
	steady_clock::time_point begin = steady_clock::now();
	function(args...);
	steady_clock::time_point end = steady_clock::now();
	return duration_cast<nanoseconds>(end - begin).count();
}

/**
 * @brief ���������� �������� � ����.
 * @tparam T ��� ������.
 * @param value �������� ��� ������.
 * @param filePath ���� � �����.
*/
template<class T>
void WriteInFile(T value, string filePath)
{
	ofstream writer = ofstream(filePath);
	if (writer.is_open())
	{
		writer << value;
	}
	writer.close();
}

/**
 * @brief ������� ������� ������� �����.
 * @param number �����.
 * @return ������� ������� �����.
*/
int Find�oprime(int number)
{
	for (int result = 2; true; ++result)
	{
		bool isCompire = true;
		for (int n = 2; n < result && n < number; ++n)
		{
			if (result % n == 0 && number % n == 0)
			{
				isCompire = false;
				break;
			}
		}
		if (isCompire)
		{
			return result;
		}
		++result;
	}
}

template<class T, const int size>
struct StaticArray;

/**
 * @brief ������ ���� � �������� �������.
 * @tparam ...Args ���� ������ ����������.
 * @tparam size ���������� ������� �������.
 * @param functionArray ������� ������� ������ ������.
 * @param stringArray ������������ ������� ������ ������.
 * @param isWithPause ���������� ��������, ����������� ����� �� ����� ����� ������ ������.
 * @param ...args ��������� �������.
*/
template<const int size, class... Args>
void CreateMenu(StaticArray<void(*)(Args&...), size> functionArray, StaticArray <const char*, size>
	stringArray, bool isWithPause, Args... args)
{
	while (true)
	{
		PrintValues("������� ���� �� �����, ���������� �� ����� (��� -1 ��� ������):");
		for (int n = 0; n < stringArray.GetSize(); ++n)
		{
			PrintValues(n, ")", stringArray[n]);
		}

		int cursor = SetValue<int>();

		if (cursor < functionArray.GetSize() && cursor >= 0)
		{
			system("cls");
			functionArray[cursor](args...);
			if (isWithPause)
			{
				system("pause");
			}
		}
		else
		{
			if (cursor == -1)
			{
				return void();
			}
			else
			{
				PrintValues("����������� �������� ����� (������� Enter ��� �����������)!");
				system("pause");
			}
		}
		system("cls");
	}
}