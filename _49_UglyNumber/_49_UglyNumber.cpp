/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������49������
// ��Ŀ�����ǰ�ֻ��������2��3��5��������������Ugly Number�����󰴴�С��
// ���˳��ĵ�1500������������6��8���ǳ�������14���ǣ���Ϊ����������7��
// ϰ�������ǰ�1������һ��������

#include <cstdio>

// ====================�㷨1�Ĵ���====================
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

// ====================�㷨2�Ĵ���====================
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

// ====================���Դ���====================
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