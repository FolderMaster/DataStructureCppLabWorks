#pragma once
#include <iostream>

using namespace std;

/*1.1.1.1 sum =
1)0
2)1.1000000000000001
3)3.5200000000000005
4)7.5130000000000017
5)13.369400000000004
6)21.421950000000010
7)32.051316000000014
8)45.692335700000022
9)62.841046180000035
10)84.062575399000053*/

void Breakpoints1()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += add * i;
		add *= 1.1;
	}
	cout << "Total sum is " << sum << endl;
}

//1.1.1.2 sum = 3.2624579394327844

void Breakpoints2()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; // Поставьте условную точку останова здесь
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}