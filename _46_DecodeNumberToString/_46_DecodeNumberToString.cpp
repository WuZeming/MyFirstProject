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

// ������46�������ַ�����ַ���
// ��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
// ���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣��
// ��12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
// "mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����

#include <string>
#include <iostream>

using namespace std;

int GetTranslationCount(const int& number)
{
	if (number < 0)
		return 0;

	string StrNum = to_string(number);

	int len = StrNum.length();

	int* counts = new int[len];    //ֻ������Ϊ��̬���飬��������Ĵ�СӦΪ����

	for (int i = len - 1; i >= 0; --i)
	{
		if (i == len-1)
		{
			counts[i] = 1;
			continue;
		}

		string substr = StrNum.substr(i, 2);

		int subnumber = stoi(substr);

		if (subnumber>=10 && subnumber <=25)
		{
			if (i==len-2)
			{
				counts[i] = 2;
			}
			else 
			{
				counts[i] = counts[i + 1] + counts[i + 2];
			}
		}
		else
		{
			counts[i] = counts[i + 1];
		}
	}

	int count = counts[0];
	delete[] counts;
	return count;
}


// ====================���Դ���====================
void Test(const string& testName, int number, int expected)
{
	if (GetTranslationCount(number) == expected)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

void Test1()
{
	int number = 0;
	int expected = 1;
	Test("Test1", number, expected);
}

void Test2()
{
	int number = 10;
	int expected = 2;
	Test("Test2", number, expected);
}

void Test3()
{
	int number = 125;
	int expected = 3;
	Test("Test3", number, expected);
}

void Test4()
{
	int number = 126;
	int expected = 2;
	Test("Test4", number, expected);
}

void Test5()
{
	int number = 426;
	int expected = 1;
	Test("Test5", number, expected);
}

void Test6()
{
	int number = 100;
	int expected = 2;
	Test("Test6", number, expected);
}

void Test7()
{
	int number = 101;
	int expected = 2;
	Test("Test7", number, expected);
}

void Test8()
{
	int number = 12258;
	int expected = 5;
	Test("Test8", number, expected);
}

void Test9()
{
	int number = -100;
	int expected = 0;
	Test("Test9", number, expected);
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
	Test8();
	Test9();

	return 0;
}