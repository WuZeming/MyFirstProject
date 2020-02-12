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

// ������44������������ĳһλ������
// ��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
// �������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
// ������������λ��Ӧ�����֡�

#include <iostream>
#include <algorithm>

using namespace std;

int countOfIntegers(int digit)
{
	if (digit == 1)
		return 10;
	return 9 * pow(10, digit - 1);
}

int beginNumber(int digit)
{
	if (digit == 1)
	{
		return 0;
	}
	return pow(10, digit - 1);
}

int digitAttheIndex(int index, int digit)
{
	int begin = beginNumber(digit);
	int theNumber = begin + index / digit;
	int theIndexFromRight =digit- index%digit;
	for (int i = 1; i < theIndexFromRight; i++)
		theNumber /= 10;
	return theNumber % 10;

}

int digitAtIndex(int index)
{
	if (index < 0)
		return -1;
	int digit = 1;
	while (true)
	{
		int numbers = countOfIntegers(digit);

		if (numbers*digit > index)
			return digitAttheIndex(index, digit);
		index = index - digit*numbers;
		digit++;
	}
	return -1;
}


// ====================���Դ���====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // ����99�����һλ��9
	test("Test6", 190, 1);  // ����100�ĵ�һλ��1
	test("Test7", 1000, 3); // ����370�ĵ�һλ��3
	test("Test8", 1001, 7); // ����370�ĵڶ�λ��7
	test("Test9", 1002, 0); // ����370�ĵ���λ��0
	return 0;
}