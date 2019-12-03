// _15_number_of_1_in_binary.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"



int NumberOf1_Solution1(int number)
{
	int count = 0;
	int i = 1;
	while (i)
	{
		if (number&i)
		{
			count++;
		}
		i = i << 1;
	}
	return count;
}

int NumberOf1_Solution2(int Number)
{
	int count = 0;
	while (Number)
	{
		Number = (Number - 1)&Number;
		count++;
	}
	return count;
}



// ====================���Դ���====================
void Test(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

int main(int argc, char* argv[])
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);
	getchar();
	return 0;
}