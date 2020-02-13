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

// ������45���������ų���С����
// ��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
// �ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
// �����ųɵ���С����321323��

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



// ====================���Դ���====================
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

// ������ֻ��һ������
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
