#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "Stack.h"
#include "StackQueue.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

/**
 * @brief �������� �������� � ����.
 * @param stack ����.
*/
void StackPush(Stack<int>& stack)
{
	PrintValues("����:\n", stack);

	int value = SetValue<int>("������� �������� ��� ��������� � ����:");

	stack.Push(value);
	PrintValues("���� ����� ���������:\n", stack);
}

/**
 * @brief ��������� �������� �� �����.
 * @param stack ����.
*/
void StackPop(Stack<int>& stack)
{
	PrintValues("����:\n", stack);

	try
	{
		int value = stack.Pop();
		PrintValues("��������, ����������� �� �����:", value);

		PrintValues("���� ����� ����������:\n", stack);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief �������� �������� � ������� �� ������.
 * @param stackQueue ������� �� ������.
*/
void StackQueueEnqueue(StackQueue<int>& stackQueue)
{
	PrintValues("������� �� ������:\n", stackQueue);

	int value = SetValue<int>("������� �������� ��� ��������� � ������� �� ������:");

	stackQueue.Enqueue(value);
	PrintValues("������� �� ������ ����� ���������:\n", stackQueue);
}

/**
 * @brief ��������� �������� �� ������� �� ������.
 * @param stackQueue ������� �� ������.
*/
void StackQueueDequeue(StackQueue<int>& stackQueue)
{
	PrintValues("������� �� ������:\n", stackQueue);

	try
	{
		int value = stackQueue.Dequeue();
		PrintValues("��������, ����������� �� ������� �� ������:", value);

		PrintValues("������� �� ������ ����� ����������:\n", stackQueue);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief �������� �������� � ��������� �����.
 * @param ringBuffer ��������� �����.
*/
void RingBufferPush(RingBuffer<int>& ringBuffer)
{
	PrintValues("��������� �����:\n", ringBuffer);

	int value = SetValue<int>("������� �������� ��� ��������� � ��������� �����:");
	try
	{
		ringBuffer.Push(value);
		PrintValues("��������� ����� ����� ���������:\n", ringBuffer);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ��������� �������� �� ���������� ������.
 * @param ringBuffer ��������� �����.
*/
void RingBufferPop(RingBuffer<int>& ringBuffer)
{
	PrintValues("��������� �����:\n", ringBuffer);

	try
	{
		int value = ringBuffer.Pop();
		PrintValues("��������, ����������� �� ���������� ������:", value);

		PrintValues("��������� ����� ����� ����������:\n", ringBuffer);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief �������� �������� � ������� ��������� �����.
 * @param ringBufferQueue ������� ���������� ������.
*/
void RingBufferQueueEnqueue(RingBufferQueue<int>& ringBufferQueue)
{
	PrintValues("������� ���������� ������:\n", ringBufferQueue);

	int value = SetValue<int>("������� �������� ��� ��������� � ������� ���������� ������:");

	ringBufferQueue.Enqueue(value);
	PrintValues("������� ���������� ������ ����� ���������:\n", ringBufferQueue);
}

/**
 * @brief ��������� �������� �� ������� ���������� ������.
 * @param ringBufferQueue ������� ���������� ������.
*/
void RingBufferQueueDequeue(RingBufferQueue<int>& ringBufferQueue)
{
	PrintValues("������� ���������� ������:\n", ringBufferQueue);

	try
	{
		int value = ringBufferQueue.Dequeue();
		PrintValues("��������, ����������� �� ������� ���������� ������:", value);

		PrintValues("������� ���������� ������ ����� ����������:\n", ringBufferQueue);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief ������ ���� �����.
 * @param stack ����.
 * @param stackQueue ������� �� ������ (�� ������������!).
 * @param ringBuffer ��������� ����� (�� ������������!).
 * @param ringBufferQueue ������� ���������� ������ (�� ������������!).
*/
void CreateStackMenu(Stack<int>& stack, StackQueue<int>& stackQueue, RingBuffer<int>& ringBuffer, 
	RingBufferQueue<int>& ringBufferQueue)
{
	void (*functionArray[])(Stack<int>&) { StackPush, StackPop };
	StaticArray <void(*)(Stack<int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(Stack<int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[] { NameOf(StackPush), NameOf(StackPop) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, stack);
}

/**
 * @brief ������ ���� ������� �� ������.
 * @param stack ���� (�� ������������!).
 * @param stackQueue ������� �� ������.
 * @param ringBuffer ��������� ����� (�� ������������!).
 * @param ringBufferQueue ������� ���������� ������ (�� ������������!).
*/
void CreateStackQueueMenu(Stack<int>& stack, StackQueue<int>& stackQueue, RingBuffer<int>& 
	ringBuffer, RingBufferQueue<int>& ringBufferQueue)
{
	void (*functionArray[])(StackQueue<int>&) { StackQueueEnqueue, StackQueueDequeue };
	StaticArray <void(*)(StackQueue<int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(StackQueue<int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(StackQueueEnqueue), NameOf(StackQueueDequeue) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, stackQueue);
}

/**
 * @brief ������ ���� ���������� ������.
 * @param stack ���� (�� ������������!).
 * @param stackQueue ������� �� ������ (�� ������������!).
 * @param ringBuffer ��������� �����.
 * @param ringBufferQueue ������� ���������� ������ (�� ������������!).
*/
void CreateRingBufferMenu(Stack<int>& stack, StackQueue<int>& stackQueue, RingBuffer<int>& 
	ringBuffer, RingBufferQueue<int>& ringBufferQueue)
{
	void (*functionArray[])(RingBuffer<int>&) { RingBufferPush, RingBufferPop };
	StaticArray <void(*)(RingBuffer<int>&), sizeof(functionArray) / sizeof(functionArray[0])>
		functionStaticArray = StaticArray<void(*)(RingBuffer<int>&), sizeof(functionArray) /
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(RingBufferPush), NameOf(RingBufferPop) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, ringBuffer);
}

/**
 * @brief ������ ���� ������� ���������� ������.
 * @param stack ���� (�� ������������!).
 * @param stackQueue ������� �� ������ (�� ������������!).
 * @param ringBuffer ��������� ����� (�� ������������!).
 * @param ringBufferQueue ������� ���������� ������.
*/
void CreateRingBufferQueueMenu(Stack<int>& stack, StackQueue<int>& stackQueue, RingBuffer<int>& 
	ringBuffer, RingBufferQueue<int>& ringBufferQueue)
{
	void (*functionArray[])(RingBufferQueue<int>&) { RingBufferQueueEnqueue, 
		RingBufferQueueDequeue };
	StaticArray <void(*)(RingBufferQueue<int>&), sizeof(functionArray) / sizeof(functionArray[0])> 
		functionStaticArray = StaticArray<void(*)(RingBufferQueue<int>&), sizeof(functionArray) / 
		sizeof(functionArray[0])>(functionArray);

	const char* stringArray[]{ NameOf(RingBufferQueueEnqueue), NameOf(RingBufferQueueDequeue) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	CreateMenu(functionStaticArray, stringStaticArray, true, ringBufferQueue);
}

/**
 * @brief ������� ����� � ����������.
 * @return ��������� �� ���������� ���������.
*/
int main()
{
	setlocale(LC_ALL, "ru-RU");

	void (*functionArray[])(Stack<int>&, StackQueue<int>&, RingBuffer<int>&, RingBufferQueue<int>&)
	{ CreateStackMenu, CreateStackQueueMenu, CreateRingBufferMenu, CreateRingBufferQueueMenu };
	StaticArray <void(*)(Stack<int>&, StackQueue<int>&, RingBuffer<int>&, RingBufferQueue<int>&), 
		sizeof(functionArray) / sizeof(functionArray[0])> functionStaticArray = StaticArray<void(*)
		(Stack<int>&, StackQueue<int>&, RingBuffer<int>&, RingBufferQueue<int>&), 
		sizeof(functionArray) / sizeof(functionArray[0])> (functionArray);

	const char* stringArray[] { NameOf(CreateStackMenu), NameOf(CreateStackQueueMenu), 
		NameOf(CreateRingBufferMenu), NameOf(CreateRingBufferQueueMenu) };
	StaticArray <const char*, sizeof(stringArray) / sizeof(stringArray[0])> stringStaticArray =
		StaticArray<const char*, sizeof(stringArray) / sizeof(stringArray[0])>(stringArray);

	Stack<int> stack = Stack<int>();
	StackQueue<int> stackQueue = StackQueue<int>();
	RingBuffer<int> ringBuffer = RingBuffer<int>();
	RingBufferQueue<int> ringBufferQueue = RingBufferQueue<int>();

	CreateMenu(functionStaticArray, stringStaticArray, false, stack, stackQueue, ringBuffer, 
		ringBufferQueue);
}