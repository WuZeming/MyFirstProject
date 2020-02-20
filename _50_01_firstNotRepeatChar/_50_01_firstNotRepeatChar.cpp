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

// ������50��һ�����ַ����е�һ��ֻ����һ�ε��ַ�
// ��Ŀ�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������
// 'b'��

#include <cstdio>
#include <string>

char FirstNotRepeatingChar(const char* pString)
{
	if (pString == nullptr)
	{
		return '\0';
	}
	unsigned int hashTable[256];
	for (unsigned int i = 0; i < 256; i++)
	{
		hashTable[i] = 0;
	}
	const char* pHash = pString;
	while (*pHash != '\0')
	{
		hashTable[*pHash++]++;
	}
	pHash = pString;
	while (*pHash !='\0')
	{
		if (hashTable[*pHash] == 1)
		{
			return*pHash;
		}
		pHash++;
	}

	return '\0';
}

// ====================���Դ���====================
void Test(const char* pString, char expected)
{
	if (FirstNotRepeatingChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	// ����������ԣ�����ֻ����һ�ε��ַ�
	Test("google", 'l');

	// ����������ԣ�������ֻ����һ�ε��ַ�
	Test("aabccdbd", '\0');

	// ����������ԣ������ַ���ֻ����һ��
	Test("abcdefg", 'a');

	// ³���Բ��ԣ�����nullptr
	Test(nullptr, '\0');

	return 0;
}