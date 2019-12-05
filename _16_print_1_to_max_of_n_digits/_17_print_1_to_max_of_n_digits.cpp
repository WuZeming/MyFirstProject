// _16_print_1_to_max_of_n_digits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void printNumber(char* number)
{
	bool isfirst0 = true;
	int i = 0;
	while (number[i]!='\0')
	{
		if (number[i]=='0'&&isfirst0)
		{
			++i;
			continue;
		}
		else 
		{
			isfirst0 = false;
		}
		printf("%c",number[i]);
		++i;
	}
	printf("\t");
}

bool increment(char* number,int n)
{
	int sum = 0;
	int takeover = 0;
	bool overflow = false;
	for (int i = n-1; i>=0; i--)
	{
		sum = number[i] - '0' + takeover;
		if (i == n - 1)
			sum++;
		if (sum >=10)
		{
			if (i == 0)
			{
				overflow = true;
			}
			else
			{
				sum -= 10;
				takeover = 1;
				number[i] = sum + '0';
			}
		}
		else
		{
			number[i] = sum + '0';
			break;
		}
	}
	return overflow;
}

void Print1ToMaxOfNDigits_1(int n)
{
	if (n<=0)
	{
		return;
	}
	char* number = new char[n+1];
	memset(number, '0', n + 1);
	number[n] = '\0';
	while (!increment(number,n))
	{
		printNumber(number);
	}
	delete[] number;
}


void printRecersive(char* number,int index, int len)
{
	if (index == len)
	{
		printNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index] = i + '0';
		printRecersive(number, index+1, len);
	}
}
void Print1ToMaxOfNDigits_2(int n)
{
	if (n<=0)
	{
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n + 1);
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		printRecersive(number, 0+1, n);
	}
	delete[] number;
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
	char* nu = "000101";
	printNumber(nu);
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}
