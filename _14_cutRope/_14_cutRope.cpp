// _14_cutRope.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<cmath>

// �ݹ�ⷨ��Ч�ʵ�
int f(int length)
{
	if (length ==1)
	{
		return 1;
	}
	if (length ==2)
	{
		return 2;
	}
	if (length ==3)
	{
		return 3;
	}
	int max = 0;
	for (int i = 1; i < length; i++)
	{
		int mutix = f(i)*f(length - i);
		if (max<mutix)
		{
			max = mutix;
		}
	}
	return max;
}


// ====================��̬�滮====================
int maxProductAfterCutting_solution1(int length)
{
	//�Ƿ�����
	if (length <2)
	{
		return 0;
	}
	// �߽�����,���ò�����
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	int* product = new int[length+1];

	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i/2; j++)
		{
			int productResult = product[j] * product[i - j];
			if (max<productResult)
			{
				max = productResult;
			}
		}
		product[i] = max;
	}
	max = product[length];
	delete[] product;
	return max;
}

// ====================̰���㷨====================
int maxProductAfterCutting_solution2(int length)
{
	if (length <2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length ==3)
	{
		return 2;
	}
	int times_of_3 = length / 3;
	int times_of_2 = 0;
	int remainder = length % 3;
	if (remainder ==1)
	{
		times_of_3--;
		times_of_2 = 2;
	}
	if (remainder ==2)
	{
		times_of_2 = 1;
	}
	return (int)pow(2,times_of_2) * (int)pow(3,times_of_3);
	
}





// ====================���Դ���====================
void test(const char* testName, int length, int expected)
{
	int result1 = maxProductAfterCutting_solution1(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = maxProductAfterCutting_solution2(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
	int length = 1;
	int expected = 0;
	test("test1", length, expected);
}

void test2()
{
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3()
{
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4()
{
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5()
{
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8()
{
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9()
{
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10()
{
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11()
{
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	getchar();
	return 0;
}

