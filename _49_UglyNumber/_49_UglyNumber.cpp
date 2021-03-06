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

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <cstdio>

// ====================算法1的代码====================
bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1);
}

int GetUglyNumber_Solution1(int index)
{
	if (index <=0)
	{
		return 0;
	}
	int currNum = 1;
	int currUgly = 0;
	int theNum = 0;
	while (currUgly<index)
	{
		if (IsUgly(currNum))
		{
			currUgly++;
			theNum = currNum;
		}
		++currNum;
	}
	return theNum;
}

// ====================算法2的代码====================
int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
	if (index<=0)
	{
		return 0;
	}

	int* array = new int[index];
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	array[0] = 1;
	for (int i = 1; i < index; i++)
	{
		int number1 = array[index2] * 2;
		int number2 = array[index3] * 3;
		int number3 = array[index5] * 5;

		int min = Min(number1, number2, number3);
		if (min == number1)
		{
			++index2;
		}
		if (min == number2)
		{
			++index3;
		}
		if (min == number3)
		{
			++index5;
		}
		array[i] = min;
	}
	int theValue = array[index - 1];
	delete[] array;
	return theValue;
}

int Min(int number1, int number2, int number3)
{
	int min = number1 < number2 ? number1 : number2;
	return min < number3 ? min : number3;
}

// ====================测试代码====================
void Test(int index, int expected)
{
	if (GetUglyNumber_Solution1(index) == expected)
		printf("solution1 passed\n");
	else
		printf("solution1 failed\n");

	if (GetUglyNumber_Solution2(index) == expected)
		printf("solution2 passed\n");
	else
		printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);

	return 0;
}