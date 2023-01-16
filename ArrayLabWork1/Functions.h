#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

/*Возращает строку из того кода, что находится внутри.*/
#define NameOf(name) #name

/**
 * @brief Указывает больше ли значение a, чем значение b.
 * @tparam T Тип данных.
 * @param a Значение a.
 * @param b Значение b.
 * @return Логическое значение, указывающее больше ли значение a, чем значение b.
*/
template<class T>
bool IsMore(T a, T b)
{
	return a > b;
}

/**
 * @brief Указывает меньше ли значение a, чем значение b.
 * @tparam T Тип данных.
 * @param a Значение a.
 * @param b Значение b.
 * @return Логическое значение, указывающее меньше ли значение a, чем значение b.
*/
template<class T>
bool IsLess(T a, T b)
{
	return a < b;
}

/**
 * @brief Выводит значение.
 * @tparam T Тип данных.
 * @param value Значение для вывода.
*/
template<class T>
void PrintValues(T value)
{
	cout << value << endl;
}

/**
 * @brief Выводит значения.
 * @tparam T Тип данных для текущего вывода.
 * @tparam ...Args Типы данных для дальнейшего вывода.
 * @param value Значение для текущего вывода.
 * @param ...values Значения для дальнейшего вывода.
*/
template<class T, class... Args>
void PrintValues(T& value, Args... values)
{
	cout << value;
	PrintValues(values...);
}

/**
 * @brief Вводит значение.
 * @tparam T Тип данных.
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
			cout << "Неверный формат!\n";
			continue;
		}

		cin.ignore(cin.rdbuf()->in_avail());
		if (cin.gcount() > 1)
		{
			cout << "Неверный формат!\n";
			continue;
		}

		break;
	}
	return value;
}

/**
 * @brief Предоставляет вывод значений и ввод значения.
 * @tparam T Тип данных значений для ввода.
 * @tparam ...Args Типы данных для вывода.
 * @param ...message Значения для вывода.
*/
template <class T, class... Args>
T SetValue(Args... message)
{
	PrintValues(message...);
	return SetValue<T>();
}

/**
 * @brief Измеряет время на выполенение функции.
 * @tparam F Тип функции.
 * @tparam ...Args Типы аргументов.
 * @param function Функция.
 * @param ...args Аргументы.
 * @return Время в наносекундах.
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
 * @brief Записывает значение в файл.
 * @tparam T Тип данных.
 * @param value Значение для записи.
 * @param filePath Путь к файлу.
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
 * @brief Находит взаимно простое число.
 * @param number Число.
 * @return Взаимно простое число.
*/
int FindСoprime(int number)
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
 * @brief Создаёт меню с пунктами выборов.
 * @tparam ...Args Типы данных аргументов.
 * @tparam size Количество пунктов выборов.
 * @param functionArray Функции каждого пункта выбора.
 * @param stringArray Наименование каждого пункти выбора.
 * @param isWithPause Логическое значение, указывающее нужна ли пауза после выбора пункта.
 * @param ...args Аргументы функций.
*/
template<const int size, class... Args>
void CreateMenu(StaticArray<void(*)(Args&...), size> functionArray, StaticArray <const char*, size>
	stringArray, bool isWithPause, Args... args)
{
	while (true)
	{
		PrintValues("Введите одно из чисел, отвечающих за выбор (или -1 для выхода):");
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
				PrintValues("Неправильно введённое число (нажмите Enter для продолжения)!");
				system("pause");
			}
		}
		system("cls");
	}
}