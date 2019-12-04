// _16_integer_power_of_integer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
bool g_InvalidInput = false;
bool equal(double number1, double number2)
{
	if ((number1-number2>-0.00000001)&& (number1-number2)<0.00000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double powerCore(double base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}
	double result = powerCore(base, exponent>>1);
	if (exponent & 0x01)
	{
		return result*result*base;
	}
	else
	{
		return result*result;
	}

}
double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base,0.0)&& exponent<0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	if (exponent ==0)
	{
		return 1.0;
	}
	if (exponent>0)
	{
		return powerCore(base, exponent);
	}
	if (exponent<0)
	{
		exponent = -exponent;
		double result = powerCore(base, exponent);
		return 1 / result;
	}
	
}


// ====================���Դ���====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
	// ������ָ����Ϊ����
	Test("Test1", 2, 3, 8, false);

	// ����Ϊ������ָ��Ϊ����
	Test("Test2", -2, 3, -8, false);

	// ָ��Ϊ����
	Test("Test3", 2, -3, 0.125, false);

	// ָ��Ϊ0
	Test("Test4", 2, 0, 1, false);

	// ������ָ����Ϊ0
	Test("Test5", 0, 0, 1, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test6", 0, 4, 0, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test7", 0, -4, 0, true);
	getchar();
	return 0;
}