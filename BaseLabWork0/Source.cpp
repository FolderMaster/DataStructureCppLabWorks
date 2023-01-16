#include "Functions.h"
#include "StaticArray.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru-RU");

	void (*functionArray[])() {Task1121, Task1122, Task1123, Task113123, Task1134,
		Task1141, Task1142, Task1143, Task1144, Task1145, Task1146, Task1148, Task1151, Task1152,
		Task1153, Task1154, Task1155, Task1156, Task1157, Task1158};
	StaticArray <void(*)(), sizeof(functionArray) / sizeof(functionArray[0])> functionStaticArray =
		StaticArray<void(*)(), sizeof(functionArray) / sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{NameOf(Task1121), NameOf(Task1122), NameOf(Task1123),
		NameOf(Task113123), NameOf(Task1134), NameOf(Task1141), NameOf(Task1142), NameOf(Task1143),
		NameOf(Task1144), NameOf(Task1145), NameOf(Task1146), NameOf(Task1148), NameOf(Task1151),
		NameOf(Task1152), NameOf(Task1153), NameOf(Task1154), NameOf(Task1155), NameOf(Task1156),
		NameOf(Task1157), NameOf(Task1158)};
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	int cursor = 0;
	while (true)
	{
		cout << "Введите одну из чисел, отвечающих за исполнения заданий (или -1 для выхода):"
			<< endl;
		for (int n = 0; n < stringStaticArray.GetSize(); ++n)
		{
			cout << n << ")" << stringStaticArray[n] << endl;
		}

		cin >> cursor;

		system("cls");
		if (cursor < functionStaticArray.GetSize() && cursor >= 0)
		{
			functionStaticArray[cursor]();
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