// _21_reorder_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
void ReorderOddEven_1(int* numbers, int len)
{
	if (numbers ==nullptr|| len<=0)
	{
		return;
	}
	int index1 = 0;
	int index2 = len - 1;
	while (index1 < index2)
	{
		while ((numbers[index1] & 0x01)==1) //奇数
			index1++;

		while ((numbers[index2]& 0x01) ==0)//偶
		{
			index2--;
		}
		if (index1<index2)
		{
			swap(numbers[index1],numbers[index2]);
		}
		
	}

}
bool isEven(int n)
{
	return (n & 0x01) == 0;
}
void reOrder(int* numbers, int len, bool(*fun)(int))
{
	int index1 = 0;
	int index2 = len - 1;
	while (index1<index2)
	{
		while (!fun(numbers[index1]))
			index1++;
		while (fun(numbers[index2]))
			index2--;
		if (index1 < index2)
			swap(numbers[index1],numbers[index2]);
	}
}
void ReorderOddEven_2(int* numbers, int len)
{
	if (numbers ==nullptr || len<=0)
	{
		return;
	}
	reOrder(numbers, len, isEven);
	
}
// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	ReorderOddEven_1(numbers, length);
	PrintArray(numbers, length);

	printf("Test for solution 2:\n");
	PrintArray(copy, length);
	ReorderOddEven_2(copy, length);
	PrintArray(copy, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}