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

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <cstdio>

#include <string>
void Reverse(char* begin, char*end)
{
	if (begin == nullptr || end == nullptr)
	{
		return;
	}
	while (begin<end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
char* ReverseSentence(char *pData)
{
	if (pData == nullptr)
	{
		return nullptr;
	}
	unsigned int length = strlen(pData);
	Reverse(pData, pData + length-1);
	char* start = pData;
	char* end = pData;
	while (*start != '\0')
	{
		if (*start == ' ')
		{
			++start;
			++end;
		}
		else if (*end == ' '|| *end == '\0')
		{
			Reverse(start, end-1);
			start = end;

		}
		else {
			++end;
		}
		
	}
	return pData;
}

// ====================���Դ���====================
void Test(const char* testName, char* input, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReverseSentence(input);

	if ((input == nullptr && expectedResult == nullptr)
		|| (input != nullptr && strcmp(input, expectedResult) == 0))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
	char input[] = "I am a student.";
	char expected[] = "student. a am I";

	Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
	char input[] = "Wonderful";
	char expected[] = "Wonderful";

	Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
	Test("Test3", nullptr, nullptr);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
	Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
	char input[] = "   ";
	char expected[] = "   ";
	Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}