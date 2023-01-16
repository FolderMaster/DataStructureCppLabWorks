#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "Dictionary.h"
#include "HashTable.h"

/**
 * @brief Добавляет пару ключ-значение в словарь.
 * @param dictionary Словарь.
*/
void DictionaryAdd(Dictionary<string, string>& dictionary)
{
	PrintValues("Словарь:\n", dictionary);

	string key = SetValue<string>("Введите ключ для добавления в словарь:");
	string value = SetValue<string>("Введите значение для добавления в словарь:");

	try
	{
		dictionary.Add(key, value);
		PrintValues("Словарь с добавлением:\n", dictionary);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет пару ключ-значение из словаря.
 * @param dictionary Словарь.
*/
void DictionaryRemove(Dictionary<string, string>& dictionary)
{
	PrintValues("Словарь:\n", dictionary);

	string key = SetValue<string>("Введите ключ для удаления из словаря:");

	try
	{
		dictionary.Remove(key);
		PrintValues("Словарь с удалением:\n", dictionary);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит значение в словаре по ключу.
 * @param dictionary Словарь.
*/
void DictionaryFind(Dictionary<string, string>& dictionary)
{
	PrintValues("Словарь:\n", dictionary);

	string key = SetValue<string>("Введите ключ для поиска в словаре:");

	try
	{
		string value = dictionary.Find(key);
		PrintValues("Значение, найденное в словаре:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Добавляет пару ключ-значение в хеш-таблицу.
 * @param hashTable Хеш-таблица.
*/
void HashTableAdd(HashTable<string>& hashTable)
{
	PrintValues("Хеш-таблица:\n", hashTable);

	string key = SetValue<string>("Введите ключ для добавления в хеш-таблицу:");
	string value = SetValue<string>("Введите значение для добавления в хеш-таблицу:");

	try
	{
		hashTable.Add(key, value);
		PrintValues("Хеш-таблица с добавлением:\n", hashTable);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Удаляет пару ключ-значение из хеш-таблицы.
 * @param hashTable Хеш-таблица.
*/
void HashTableRemove(HashTable<string>& hashTable)
{
	PrintValues("Хеш-таблица:\n", hashTable);

	string key = SetValue<string>("Введите ключ для удаления из хеш-таблицы:");

	try
	{
		hashTable.Remove(key);
		PrintValues("Хеш-таблица с удалением:\n", hashTable);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Находит значение в хеш-таблице по ключу.
 * @param hashTable Хеш-таблица.
*/
void HashTableFind(HashTable<string>& hashTable)
{
	PrintValues("Хеш-таблица:\n", hashTable);

	string key = SetValue<string>("Введите ключ для поиска в хеш-таблице:");

	try
	{
		DynamicArray<string> values = hashTable.Find(key);
		PrintValues("Значения, найденные в хеш-таблице:\n", values);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Создаёт меню словаря.
 * @param dictionary Словарь.
 * @param hashTable Хеш-таблица (не используется!).
*/
void CreateDictionaryMenu(Dictionary<string, string>& dictionary, HashTable<string>& hashTable)
{
	void (*functionArray[])(Dictionary<string, string>&) { DictionaryAdd, DictionaryRemove, 
		DictionaryFind };
	StaticArray <void(*)(Dictionary<string, string>&), sizeof(functionArray) / 
		sizeof(functionArray[0])> functionStaticArray = StaticArray<void(*)(Dictionary<string, 
		string>&), sizeof(functionArray) / sizeof(functionArray[0])> (functionArray);

	const char* stringArray[]
	{ NameOf(DictionaryAdd), NameOf(DictionaryRemove), NameOf(DictionaryFind) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, dictionary);
}

/**
 * @brief Создаёт меню хеш-таблицы.
 * @param dictionary Словарь (не используется!).
 * @param hashTable Хеш-таблица.
*/
void CreateHashTableMenu(Dictionary<string, string>& dictionary, HashTable<string>& hashTable)
{
	void (*functionArray[])(HashTable<string>&) { HashTableAdd, HashTableRemove, HashTableFind };
	StaticArray <void(*)(HashTable<string>&), sizeof(functionArray) /
		sizeof(functionArray[0])> functionStaticArray = StaticArray<void(*)(HashTable<string>&), 
		sizeof(functionArray) / sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]
	{ NameOf(HashTableAdd), NameOf(HashTableRemove), NameOf(HashTableFind) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, hashTable);
}

/**
 * @brief Функция входа в приложение.
 * @return Правильно ли отработала программа.
*/
int main()
{
	setlocale(LC_ALL, "ru-RU");

	void (*functionArray[])(Dictionary<string, string>&, HashTable<string>&)
	{ CreateDictionaryMenu, CreateHashTableMenu };
	StaticArray <void(*)(Dictionary<string, string>&, HashTable<string>&), sizeof(functionArray) /
		sizeof(functionArray[0])> functionStaticArray = StaticArray<void(*)(Dictionary<string, 
		string>&, HashTable<string>&), sizeof(functionArray) / sizeof(functionArray[0])>
		(functionArray);

	const char* stringArray[] { NameOf(CreateDictionaryMenu), NameOf(CreateHashTableMenu) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	Dictionary<string, string> dictionary = Dictionary<string, string>();
	HashTable<string> hashTable = HashTable<string>();

	CreateMenu(functionStaticArray, stringStaticArray, false, dictionary, hashTable);
}