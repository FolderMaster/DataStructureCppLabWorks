#pragma once
#include <iostream>

using namespace std;

//1.1.4.1

void Task1141()
{
	int a = 5;
	int b = 4;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	double c = 13.5;
	cout << "Address of c: " << &c << endl;
	bool d = true;
	cout << "Address of d: " << &d << endl;
}

//1.1.4.2

void Task1142()
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	cout << "Size of int type: " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of a[" << i << "]: " << &a[i] << endl;
	}
	cout << endl;
	cout << "Size of double type: " << sizeof(double) << endl;
	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2
	};
	for (int i = 0; i < 10; i++)
	{
		cout << "Address of b[" << i << "]: " << &b[i] << endl;
	}
}

//1.1.4.3

void Task1143()
{
	int a = 5;
	int& b = a;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	cout << endl;
	b = 7;
	cout << "Value of a: " << a << endl;
}

//1.1.4.4

void Foo1(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task1144()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	Foo1(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

//1.1.4.5

void Foo2(double& a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task1145()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	Foo2(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

//1.1.4.6

void Task1146()
{
	int a = 5;
	int* pointer = &a;
	cout << "Address of a: " << &a << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Address of pointer: " << &pointer << endl;
	cout << endl;
	*pointer = 7;
	cout << "Value in a: " << a << endl;
	cout << "Value by pointer address: " << *pointer << endl;
}

/*1.1.4.7 Единственный операнд после символа звёздочки означает то, что это операция
разыменовывания, в отличие от опреции умножения, где стоят между двумя операндами
стоит этот символ.*/

//1.1.4.8

void Foo3(double* a)
{
	cout << "Address in pointer: " << a << endl;
	cout << "Address of pointer: " << &a << endl;
	cout << "Value in pointer address: " << *a << endl;
	*a = 15.0;
	cout << "New value in pointer address: " << *a << endl;
}

void Task1148()
{
	double value = 5.0;
	double* pointer = &value;
	cout << "Address of value in main(): " << &value << endl;
	cout << "Address in pointer in main(): " << pointer << endl;
	cout << "Address of pointer in main(): " << &pointer << endl;
	cout << "Value of a in main(): " << value << endl;
	cout << endl;
	Foo3(pointer);
	cout << endl;
	cout << "Value of a in main(): " << value << endl;
}