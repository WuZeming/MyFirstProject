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

// ������58������������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
// ��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��

#include <cstdio>

#include <string.h>
void Reverse(char* start, char* end)
{
	if (start == nullptr || end == nullptr)
		return;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}
char* LeftRotateString(char* pStr, int n)
{
	if (pStr == nullptr || n <= 0)
		return pStr;
	int length = strlen(pStr);
	Reverse(pStr, pStr + length - 1);
	Reverse(pStr, pStr + length - n -1);
	Reverse(pStr + length - n, pStr + length - 1);
	return pStr;
}

// ====================���Դ���====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	char* result = LeftRotateString(input, num);

	if ((input == nullptr && expectedResult == nullptr)
		|| (input != nullptr && strcmp(result, expectedResult) == 0))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// ���ܲ���
void Test1()
{
	char input[] = "abcdefg";
	char expected[] = "cdefgab";

	Test("Test1", input, 2, expected);
}

// �߽�ֵ����
void Test2()
{
	char input[] = "abcdefg";
	char expected[] = "bcdefga";

	Test("Test2", input, 1, expected);
}

// �߽�ֵ����
void Test3()
{
	char input[] = "abcdefg";
	char expected[] = "gabcdef";

	Test("Test3", input, 6, expected);
}

// ³���Բ���
void Test4()
{
	Test("Test4", nullptr, 6, nullptr);
}

// ³���Բ���
void Test5()
{
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test5", input, 0, expected);
}

// ³���Բ���
void Test6()
{
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test6", input, 7, expected);
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