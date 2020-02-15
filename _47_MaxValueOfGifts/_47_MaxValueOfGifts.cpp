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

// ������47�����������ֵ
// ��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
// ����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�������
// �������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
// ����������õ����ټ�ֵ�����

#include <algorithm>
#include <iostream>

int getMaxValue_solution1(const int* values, int rows, int cols)
{
	if (values == nullptr || rows<=0 || cols<=0)
	{
		return 0;
	}

	int *maxVal = new int[rows*cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int up = 0;
			int left = 0;
			if (i>0)
			{
				up = maxVal[(i - 1)*cols + j];
			}
			if (j>0)
			{
				left = maxVal[i*cols + j - 1];
			}
			maxVal[i*cols + j] = std::max(up,left) + values[i*cols + j];
		}
	}
	int theMax = maxVal[rows*cols - 1];
	delete[] maxVal;
	return theMax;
}

int getMaxValue_solution2(const int* values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return 0;
	int * maxVal = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int up = 0;
			int left = 0;
			if (i > 0)
			{
				up = maxVal[j];
			}
			if (j>0)
			{
				left = maxVal[j - 1];
			}

			maxVal[j] = std::max(up, left) + values[i*cols + j];
		}
	}
	int theMax = maxVal[cols - 1];
	delete[] maxVal;
	return theMax;
}

// ====================���Դ���====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
	if (getMaxValue_solution1(values, rows, cols) == expected)
		std::cout << testName << ": solution1 passed." << std::endl;
	else
		std::cout << testName << ": solution1 FAILED." << std::endl;

	if (getMaxValue_solution2(values, rows, cols) == expected)
		std::cout << testName << ": solution2 passed." << std::endl;
	else
		std::cout << testName << ": solution2 FAILED." << std::endl;
}

void test1()
{
	// ��������
	int values[][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	int expected = 29;
	test("test1", (const int*)values, 3, 3, expected);
}

void test2()
{
	//��������
	int values[][4] = {
		{ 1, 10, 3, 8 },
		{ 12, 2, 9, 6 },
		{ 5, 7, 4, 11 },
		{ 3, 7, 16, 5 }
	};
	int expected = 53;
	test("test2", (const int*)values, 4, 4, expected);
}

void test3()
{
	// һ������
	int values[][4] = {
		{ 1, 10, 3, 8 }
	};
	int expected = 22;
	test("test3", (const int*)values, 1, 4, expected);
}

void test4()
{
	int values[4][1] = {
		{ 1 },
		{ 12 },
		{ 5 },
		{ 3 }
	};
	int expected = 21;
	test("test4", (const int*)values, 4, 1, expected);
}

void test5()
{
	// һ��һ��
	int values[][1] = {
		{ 3 }
	};
	int expected = 3;
	test("test5", (const int*)values, 1, 1, expected);
}

void test6()
{
	// ��ָ��
	int expected = 0;
	test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}