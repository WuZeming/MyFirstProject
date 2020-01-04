// _40_KLeastNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <cstdio>
#include<exception>

#include <set>
#include <vector>
#include <iostream>
#include <functional>
#
using namespace std;

int RandomInRange(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
int Partition(int numbers[], int length, int start, int end)
{
	if (numbers == nullptr || length <= 0 || start<0 || end>=length)
	{
		throw exception("Invalid Input");
	}

	int index = RandomInRange(start, end);
	int small = start - 1;

	Swap(numbers[index], numbers[end]);

	for ( index = start; index <= end; index++)
	{
		if (numbers[index] < numbers[end])
		{
			++small;
			if (small!= index)
			{
				Swap(numbers[small], numbers[index]);
			}

		}
	}
	++small;
	Swap(numbers[small], numbers[end]);
	return small;

}

// ====================方法1====================
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
	if (input == nullptr || n<=0 || output == nullptr || k<=0 || k>n)
	{
		return;
	}

	int index = Partition(input, n, 0, n - 1);
	int start = 0;
	int end = n - 1;
	while (index!= k-1)
	{
		if (index > k-1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		if (index < k-1)
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}

// ====================方法2====================
typedef multiset<int, std::greater<int> >            intSet;     // 使集合中的元素 由大到小排序。
typedef multiset<int, std::greater<int> >::iterator  setIterator;

void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();
	if (data.size() <k || k<=0)
	{
		return;
	}

	for (auto index = data.begin(); index!= data.end(); ++index)
	{
		if (leastNumbers.size()<k)
		{
			leastNumbers.insert(*index);
		}
		else 
		{
			auto bigest = leastNumbers.begin();
			if (*index<*bigest)
			{
				leastNumbers.erase(bigest);
				leastNumbers.insert(*index);
			}
		}
	}

}

// ====================测试代码====================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	vector<int> vectorData;
	for (int i = 0; i < n; ++i)
		vectorData.push_back(data[i]);

	if (expectedResult == nullptr)
		printf("The input is invalid, we don't expect any result.\n");
	else
	{
		printf("Expected result: \n");
		for (int i = 0; i < k; ++i)
			printf("%d\t", expectedResult[i]);
		printf("\n");
	}

	printf("Result for solution1:\n");
	int* output = new int[k];
	GetLeastNumbers_Solution1(data, n, output, k);
	if (expectedResult != nullptr)
	{
		for (int i = 0; i < k; ++i)
			printf("%d\t", output[i]);
		printf("\n");
	}

	delete[] output;

	printf("Result for solution2:\n");
	intSet leastNumbers;
	GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
	printf("The actual output numbers are:\n");
	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
		printf("%d\t", *iter);
	printf("\n\n");
}

// k小于数组的长度
void Test1()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4 };
	Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1 };
	Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
	int expected[] = { 1, 2 };
	Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
	int* expected = nullptr;
	Test("Test7", nullptr, 0, expected, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}