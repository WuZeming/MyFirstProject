// _40_KLeastNumbers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������40����С��k����
// ��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8
// ��8�����֣�����С��4��������1��2��3��4��

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

// ====================����1====================
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

// ====================����2====================
typedef multiset<int, std::greater<int> >            intSet;     // ʹ�����е�Ԫ�� �ɴ�С����
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

// ====================���Դ���====================
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

// kС������ĳ���
void Test1()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4 };
	Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k��������ĳ���
void Test2()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k��������ĳ���
void Test3()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k����1
void Test4()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1 };
	Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k����0
void Test5()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// ����������ͬ������
void Test6()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
	int expected[] = { 1, 2 };
	Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// �����ָ��
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