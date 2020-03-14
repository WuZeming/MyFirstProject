/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <cstdio>

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length<2)
	{
		return;
	}
	int resultOr = 0;
	for (int i = 0; i < length; i++)
	{
		resultOr ^= data[i];
	}
	unsigned int index = FindFirstBitIs1(resultOr);
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (IsBit1(data[i], index))
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

// 找到num从右边数起第一个是1的位
unsigned int FindFirstBitIs1(int num)
{
	unsigned int index = 0;
	while (((num&1) == 0) &&( index <sizeof(int)*8) )
	{
		num = num >> 1;
		index++;
	}
	return index;
}

// 判断数字num的第indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return num & 1;
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result1, result2;
	FindNumsAppearOnce(data, length, &result1, &result2);

	if ((expected1 == result1 && expected2 == result2) ||
		(expected2 == result1 && expected1 == result2))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

void Test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
	int data[] = { 4, 6 };
	Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
	int data[] = { 4, 6, 1, 1, 1, 1 };
	Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}
