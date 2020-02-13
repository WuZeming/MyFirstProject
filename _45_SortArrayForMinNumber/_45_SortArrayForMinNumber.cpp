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

// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include "cstdio"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(const string& left, const string& right)
{
	return (left + right) < (right + left);
}

void PrintMinNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	vector<string> Numbers;
	for (int i = 0; i < length; ++i)
	{
		string number = to_string(numbers[i]);
		Numbers.push_back(number);
	}

	sort(Numbers.begin(), Numbers.end(),compare);

	string result = "";
	for (auto index = Numbers.begin(); index != Numbers.end(); ++index)
	{
		result += *index;
	}
	cout << result << endl;
}



// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	if (expectedResult != nullptr)
		printf("Expected result is: \t%s\n", expectedResult);

	printf("Actual result is: \t");
	PrintMinNumber(numbers, length);

	printf("\n");
}

void Test1()
{
	int numbers[] = { 3, 5, 1, 4, 2 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2()
{
	int numbers[] = { 3, 32, 321 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3()
{
	int numbers[] = { 3, 323, 32123 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test4()
{
	int numbers[] = { 1, 11, 111 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
	int numbers[] = { 321 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6()
{
	Test("Test6", nullptr, 0, "Don't print anything.");
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
