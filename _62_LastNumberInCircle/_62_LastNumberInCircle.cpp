// _62_LastNumberInCircle.cpp : 定义控制台应用程序的入口点。
//
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

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <cstdio>
#include <list>

using namespace std;

// ====================方法1====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
	if (n<1 || m<1)
	{
		return -1;
	}
	list<int> numbers;
	for (int i = 0; i < n; i++)
	{
		numbers.push_back(i);
	}
	auto Curr = numbers.begin();
	while (numbers.size()>1)
	{
		for (int i = 1; i < m; i++) // 第一个数字是自身
		{
			Curr++;
			if (Curr == numbers.end())
			{
				Curr = numbers.begin();
			}
		}
		auto next = ++Curr;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}
		Curr--;
		numbers.erase(Curr);
		Curr = next;
	}
	return *Curr;
}

// ====================方法2====================
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;

	return last;
}

// ====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	if (LastRemaining_Solution1(n, m) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	if (LastRemaining_Solution2(n, m) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.\n");

	printf("\n");
}

void Test1()
{
	Test("Test1", 5, 3, 3);
}

void Test2()
{
	Test("Test2", 5, 2, 2);
}

void Test3()
{
	Test("Test3", 6, 7, 4);
}

void Test4()
{
	Test("Test4", 6, 6, 3);
}

void Test5()
{
	Test("Test5", 0, 0, -1);
}

void Test6()
{
	Test("Test6", 4000, 997, 1027);
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