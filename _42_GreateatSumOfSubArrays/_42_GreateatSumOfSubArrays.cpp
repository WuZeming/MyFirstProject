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

// ������42�����������������
// ��Ŀ������һ���������飬������������Ҳ�и�����������һ���������Ķ����
// �����һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��

#include <cstdio>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == nullptr || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	int currSum = 0;
	int maxSum =pData[0];// ���ﲻ�ܳ�ʼ��Ϊ0����Ϊ������Ԫ��Ϊ����ʱ��0�����κθ�������ʱ����Ϊ��һ����������Ϊ�㡣
	for (int i = 0; i < nLength; i++)
	{
		if (currSum<=0)
		{
			currSum = pData[i];
		}else
		{ 
			currSum += pData[i];
		}
		
		if (currSum>maxSum)
		{
			maxSum = currSum;
		}
	}

	return maxSum;
}

// ====================���Դ���====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
void Test4()
{
	Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}
