#include "../ArrayLabWork1/Functions.h"
#include "../ArrayLabWork1/StaticArray.h"
#include "Stack.h"
#include "StackQueue.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"

/**
 * @brief Помещает значение в стек.
 * @param stack Стек.
*/
void StackPush(Stack<int>& stack)
{
	PrintValues("Стек:\n", stack);

	int value = SetValue<int>("Введите значение для помещение в стек:");

	stack.Push(value);
	PrintValues("Стек после помещения:\n", stack);
}

/**
 * @brief Извлекает значение из стека.
 * @param stack Стек.
*/
void StackPop(Stack<int>& stack)
{
	PrintValues("Стек:\n", stack);

	try
	{
		int value = stack.Pop();
		PrintValues("Значение, извлеченное из стека:", value);

		PrintValues("Стек после извлечения:\n", stack);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Помещает значение в очередь из стеков.
 * @param stackQueue Очередь из стеков.
*/
void StackQueueEnqueue(StackQueue<int>& stackQueue)
{
	PrintValues("Очередь из стеков:\n", stackQueue);

	int value = SetValue<int>("Введите значение для помещение в очередь из стеков:");

	stackQueue.Enqueue(value);
	PrintValues("Очередь из стеков после помещения:\n", stackQueue);
}

/**
 * @brief Извлекает значение из очереди из стеков.
 * @param stackQueue Очередь из стеков.
*/
void StackQueueDequeue(StackQueue<int>& stackQueue)
{
	PrintValues("Очередь из стеков:\n", stackQueue);

	try
	{
		int value = stackQueue.Dequeue();
		PrintValues("Значение, извлеченное из очереди из стеков:", value);

		PrintValues("Очередь из стеков после извлечения:\n", stackQueue);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Помещает значение в кольцевой буфер.
 * @param ringBuffer Кольцевой буфер.
*/
void RingBufferPush(RingBuffer<int>& ringBuffer)
{
	PrintValues("Кольцевой буфер:\n", ringBuffer);

	int value = SetValue<int>("Введите значение для помещение в кольцевой буфер:");
	try
	{
		ringBuffer.Push(value);
		PrintValues("Кольцевой буфер после помещения:\n", ringBuffer);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Извлекает значение из кольцевого буфера.
 * @param ringBuffer Кольцевой буфер.
*/
void RingBufferPop(RingBuffer<int>& ringBuffer)
{
	PrintValues("Кольцевой буфер:\n", ringBuffer);

	try
	{
		int value = ringBuffer.Pop();
		PrintValues("Значение, извлеченное из кольцевого буфера:", value);

		PrintValues("Кольцевой буфер после извлечения:\n", ringBuffer);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Помещает значение в очередь кольцевой буфер.
 * @param ringBufferQueue Очередь кольцевого буфера.
*/
void RingBufferQueueEnqueue(RingBufferQueue<int>& ringBufferQueue)
{
	PrintValues("Очередь кольцевого буфера:\n", ringBufferQueue);

	int value = SetValue<int>("Введите значение для помещение в очередь кольцевого буфера:");

	ringBufferQueue.Enqueue(value);
	PrintValues("Очередь кольцевого буфера после помещения:\n", ringBufferQueue);
}

/**
 * @brief Извлекает значение из очереди кольцевого буфера.
 * @param ringBufferQueue Очередь кольцевого буфера.
*/
void RingBufferQueueDequeue(RingBufferQueue<int>& ringBufferQueue)
{
	PrintValues("Очередь кольцевого буфера:\n", ringBufferQueue);

	try
	{
		int value = ringBufferQueue.Dequeue();
		PrintValues("Значение, извлеченное из очереди кольцевого буфера:", value);

		PrintValues("Очередь кольцевого буфера после извлечения:\n", ringBufferQueue);
	}
	catch (exception ex)
	{
		PrintValues(ex.what());
	}
}

/**
 * @brief Создаёт меню стека.
 * @param stack Стек.
 * @param stackQueue Очередь из стеков (не используется!).
 * @param ringBuffer Кольцевой буфер (не используется!).
 * @param ringBufferQueue Очередь кольцевого буфера (не используется!).
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
 * @brief Создаёт меню очереди из стеков.
 * @param stack Стек (не используется!).
 * @param stackQueue Очередь из стеков.
 * @param ringBuffer Кольцевой буфер (не используется!).
 * @param ringBufferQueue Очередь кольцевого буфера (не используется!).
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
 * @brief Создаёт меню кольцевого буфера.
 * @param stack Стек (не используется!).
 * @param stackQueue Очередь из стеков (не используется!).
 * @param ringBuffer Кольцевой буфер.
 * @param ringBufferQueue Очередь кольцевого буфера (не используется!).
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
 * @brief Создаёт меню очереди кольцевого буфера.
 * @param stack Стек (не используется!).
 * @param stackQueue Очередь из стеков (не используется!).
 * @param ringBuffer Кольцевой буфер (не используется!).
 * @param ringBufferQueue Очередь кольцевого буфера.
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
 * @brief Функция входа в приложение.
 * @return Правильно ли отработала программа.
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