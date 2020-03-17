/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include <cstdio>
#include <math.h>

int g_maxValue = 6;

// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);




void PrintProbability_Solution1(int number)
{
	if (number < 1)
		return;
	int size = g_maxValue*number - number + 1;
	int * pProbabilities = new int[size];
	for (int i = 0; i < size; i++)
	{
		pProbabilities[i] = 0;
	}
	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);

	for (int i = 0; i < size; i++)
	{
		double ratio = (double)pProbabilities[i] / total;
		printf("%d : %e\n",i+number,ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; i++)
	{
		Probability(number, number, i,pProbabilities);
	}
}

void Probability(int original, int current, int sum,
	int* pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else {
		for (int i = 1; i <= g_maxValue; i++)
		{
			Probability(original, current-1, i + sum, pProbabilities);
		}
	}
}

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
	if (number < 1)
		return;
	int* probabilities[2];
	probabilities[0] = new int[g_maxValue*number + 1];
	probabilities[1] = new int[g_maxValue*number + 1];

	for (int i = 0; i < g_maxValue*number+1; i++)  //初始化为0
	{
		probabilities[0][i] = 0;
		probabilities[1][i] = 0;
	}

	int flag = 0;

	for (int i = 1; i <= g_maxValue; i++) // 第一个骰子
	{
		probabilities[flag][i] = 1;
	}

	for (int i = 2; i <= number ; i++)
	{
		for (int k = 0; k < i; k++)
		{
			probabilities[1 - flag][k] = 0; // 当骰子数为n时，n-1将不可能出现
		}
		for (int j = i; j <= g_maxValue*i; j++)
		{
			probabilities[1 - flag][j] = 0;
			for (int m = 1; m < g_maxValue && m<=j; m++)
			{
				probabilities[1 - flag][j] += probabilities[flag][j - m];
			}
		}
		flag = 1 - flag;
	}

	double total = pow(g_maxValue, number);
	for ( int i = number; i <= g_maxValue*number; i++)
	{
		double ratio = probabilities[flag][i] / total;
		printf("%d : %e\n", i, ratio);
	}

	delete probabilities[0];
	delete probabilities[1];
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	printf("Test for solution1\n");
	PrintProbability_Solution1(n);

	printf("Test for solution2\n");
	PrintProbability_Solution2(n);

	printf("\n");
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(4);
	Test(11);
	Test(0);

	return 0;
}