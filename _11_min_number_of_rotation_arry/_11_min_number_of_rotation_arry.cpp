// _11_min_number_of_rotation_arry.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <cstdio>
#include <exception>

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
	if (numbers == nullptr || length<=0)
	{
		throw new std::exception("Invalid input");
	}
	int index1 = 0;
	int index2 = length - 1;
	int middle = index1;
	while (numbers[index1]>=numbers[index2])
	{
		if (index2 - index1 == 1)
		{ 
			middle = index2;
			break;
		}
		middle = (index1 + index2) / 2;
		if (numbers[index1] == numbers[middle] && numbers[middle] ==numbers[index2])
		{
			return MinInOrder(numbers, index1, index2);
		}
		if (numbers[middle]>numbers[index1])
		{
			index1 = middle;
		}
		if (numbers[middle]<numbers[index2])
		{
			index2 = middle;
		}
			
	}
	return numbers[middle];
}

// 特殊情况顺序查找
int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int  i = index1 +1; i <=index2; i++)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}




// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(nullptr, 0, 0);
	getchar();
	return 0;
}