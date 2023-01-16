#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NameOf(name) #name

using namespace std;

template<class T>
bool IsEqualsOrMore(T a, T b)
{
	return a >= b;
}

bool IsLetter(char c)
{
	return c >= 'a' && c <= 'z';
}

template<class T>
void PrintValues(T value)
{
	cout << value << endl;
}

template<class T, class... Args>
void PrintValues(T& value, Args... values)
{
	cout << value;
	PrintValues(values...);
}

template <class T, class... Args>
void SetValue(T& value, Args... message)
{
	PrintValues(message...);
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Неверный формат!\n";
		cin >> value;
	}
	cin.ignore(cin.rdbuf()->in_avail());
}