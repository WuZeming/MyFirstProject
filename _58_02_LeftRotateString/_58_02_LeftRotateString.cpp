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

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

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

// ====================测试代码====================
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

// 功能测试
void Test1()
{
	char input[] = "abcdefg";
	char expected[] = "cdefgab";

	Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
	char input[] = "abcdefg";
	char expected[] = "bcdefga";

	Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
	char input[] = "abcdefg";
	char expected[] = "gabcdef";

	Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
	Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test5", input, 0, expected);
}

// 鲁棒性测试
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