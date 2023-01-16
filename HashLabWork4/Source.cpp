#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "Dictionary.h"
#include "HashTable.h"

/**
 * @brief ��������� ���� ����-�������� � �������.
 * @param dictionary �������.
*/
void DictionaryAdd(Dictionary<string, string>& dictionary)
{
	PrintValues("�������:\n", dictionary);

	string key = SetValue<string>("������� ���� ��� ���������� � �������:");
	string value = SetValue<string>("������� �������� ��� ���������� � �������:");

	try
	{
		dictionary.Add(key, value);
		PrintValues("������� � �����������:\n", dictionary);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ���� ����-�������� �� �������.
 * @param dictionary �������.
*/
void DictionaryRemove(Dictionary<string, string>& dictionary)
{
	PrintValues("�������:\n", dictionary);

	string key = SetValue<string>("������� ���� ��� �������� �� �������:");

	try
	{
		dictionary.Remove(key);
		PrintValues("������� � ���������:\n", dictionary);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� �������� � ������� �� �����.
 * @param dictionary �������.
*/
void DictionaryFind(Dictionary<string, string>& dictionary)
{
	PrintValues("�������:\n", dictionary);

	string key = SetValue<string>("������� ���� ��� ������ � �������:");

	try
	{
		string value = dictionary.Find(key);
		PrintValues("��������, ��������� � �������:\n", value);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ��������� ���� ����-�������� � ���-�������.
 * @param hashTable ���-�������.
*/
void HashTableAdd(HashTable<string>& hashTable)
{
	PrintValues("���-�������:\n", hashTable);

	string key = SetValue<string>("������� ���� ��� ���������� � ���-�������:");
	string value = SetValue<string>("������� �������� ��� ���������� � ���-�������:");

	try
	{
		hashTable.Add(key, value);
		PrintValues("���-������� � �����������:\n", hashTable);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� ���� ����-�������� �� ���-�������.
 * @param hashTable ���-�������.
*/
void HashTableRemove(HashTable<string>& hashTable)
{
	PrintValues("���-�������:\n", hashTable);

	string key = SetValue<string>("������� ���� ��� �������� �� ���-�������:");

	try
	{
		hashTable.Remove(key);
		PrintValues("���-������� � ���������:\n", hashTable);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������� �������� � ���-������� �� �����.
 * @param hashTable ���-�������.
*/
void HashTableFind(HashTable<string>& hashTable)
{
	PrintValues("���-�������:\n", hashTable);

	string key = SetValue<string>("������� ���� ��� ������ � ���-�������:");

	try
	{
		DynamicArray<string> values = hashTable.Find(key);
		PrintValues("��������, ��������� � ���-�������:\n", values);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������ ���� �������.
 * @param dictionary �������.
 * @param hashTable ���-������� (�� ������������!).
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
 * @brief ������ ���� ���-�������.
 * @param dictionary ������� (�� ������������!).
 * @param hashTable ���-�������.
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
 * @brief ������� ����� � ����������.
 * @return ��������� �� ���������� ���������.
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