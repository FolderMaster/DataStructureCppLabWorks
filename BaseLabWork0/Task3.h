#pragma once
#include <iostream>

using namespace std;

//1.1.3

double GetPower(double base, int exponent)
{
	double result = 1;
	if (exponent > 0)
	{
		for (int n = 0; n < exponent; ++n)
		{
			result *= base;
		}
	}
	else
	{
		for (int n = 0; n > exponent; --n)
		{
			result /= base;
		}
	}
	return result;
}

//1.1.3.2 & 1.1.3.3

void DemoGetPower(double base, int exponent)
{
	cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void Task113123()
{
	DemoGetPower(2, 5);
	DemoGetPower(-4, 8);
	DemoGetPower(-7, 3);
	DemoGetPower(10, 0);
	DemoGetPower(-1, 0);
	DemoGetPower(6, -5);
	DemoGetPower(-1, -4);
	DemoGetPower(-3, -9);
}

//1.1.3.4

void RoundToTens(int& value)
{
	int remainder = value % 10;
	if (remainder < 5)
	{
		value -= remainder;
	}
	else
	{
		value += (10 - remainder);
	}
}

void DemoRoundToTens(int value)
{
	cout << "Для " << value << " округлённое значение - это ";
	RoundToTens(value);
	cout << value << endl;
}

void Task1134()
{
	DemoRoundToTens(14);
	DemoRoundToTens(191);
	DemoRoundToTens(27);
}