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

// ������48��������ظ��ַ������ַ���
// ��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
// �ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���

#include <string>
#include <iostream>

// ����һ��������
bool hasDuplication(const std::string& str, int position[]);

int longestSubstringWithoutDuplication_1(const std::string& str)
{
	if (str.length()<=0)
	{
		return 0;
	}
	int maxLen = 0;
	
	for (int start = 0; start < str.length(); start++)
	{
		for (int end = start; end < str.length(); ++end)
		{
			int count = end - start + 1;
			std::string substr = str.substr(start, count);
			int position[26];
			if (!hasDuplication(substr,position))
			{
				maxLen = substr.length()>maxLen? substr.length():maxLen;
			}
		}
	}
	return maxLen;
}

bool hasDuplication(const std::string& str, int position[])
{
	for (int i = 0; i < 26; i++)
	{
		position[i] = -1;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (position[str[i]-'a']>=0)
		{
			return true;
		}
		position[str[i] - 'a'] = i;
	}
	return false;
}

// ����һ����̬�滮
int longestSubstringWithoutDuplication_2(const std::string& str)
{
	if (str.length() == 0)
		return 0;

	int maxLength = 0;
	int currLength = 0;
	int* position = new int[26];
	for (int i = 0; i < 26; i++)
	{
		position[i] = -1;          //-1 �������ĸû�г��ֹ�
	}
	auto begin = str.begin();
	for (auto it = begin; it != str.end(); it++)
	{
		int preIndex = position[*it - 'a'];
		int currIndex = it - begin;
		if (preIndex == -1 || currIndex-preIndex > currLength)
		{
			++currLength;
		}
		if (currIndex-preIndex <= currLength)
		{
			currLength = currIndex - preIndex;
		}
		position[*it - 'a'] = currIndex;

		if (currLength>maxLength)
		{
			maxLength = currLength;
		}
	}

	delete[] position;

	return maxLength;

}

// ====================���Դ���====================
void testSolution1(const std::string& input, int expected)
{
	int output = longestSubstringWithoutDuplication_1(input);
	if (output == expected)
		std::cout << "Solution 1 passed, with input: " << input << std::endl;
	else
		std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
	int output = longestSubstringWithoutDuplication_2(input);
	if (output == expected)
		std::cout << "Solution 2 passed, with input: " << input << std::endl;
	else
		std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
	testSolution1(input, expected);
	testSolution2(input, expected);
}

void test1()
{
	const std::string input = "abcacfrar";
	int expected = 4;
	test(input, expected);
}

void test2()
{
	const std::string input = "acfrarabc";
	int expected = 4;
	test(input, expected);
}

void test3()
{
	const std::string input = "arabcacfr";
	int expected = 4;
	test(input, expected);
}

void test4()
{
	const std::string input = "aaaa";
	int expected = 1;
	test(input, expected);
}

void test5()
{
	const std::string input = "abcdefg";
	int expected = 7;
	test(input, expected);
}

void test6()
{
	const std::string input = "aaabbbccc";
	int expected = 2;
	test(input, expected);
}

void test7()
{
	const std::string input = "abcdcba";
	int expected = 4;
	test(input, expected);
}

void test8()
{
	const std::string input = "abcdaef";
	int expected = 6;
	test(input, expected);
}

void test9()
{
	const std::string input = "a";
	int expected = 1;
	test(input, expected);
}

void test10()
{
	const std::string input = "";
	int expected = 0;
	test(input, expected);
}

int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();

	return 0;
}