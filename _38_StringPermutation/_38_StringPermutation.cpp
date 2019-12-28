// _38_StringPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
void Permutation(char *pStr, char* str);
void Permutation(char *pStr)
{
	if ( pStr == nullptr)
	{
		return;
	}
	Permutation(pStr,pStr);

}

void Permutation(char *pStr,char* str)
{
	if (*pStr == '\0')
	{
		std::cout << str << std::endl;
		return;
	}
	for (char* index = pStr; *index != '\0'; index++)
	{
		char temp = *pStr;
		*pStr = *index;
		*index = temp;

		Permutation(pStr + 1,str);

		temp = *pStr;
		*pStr = *index;
		*index = temp;
	}
}




// ====================测试代码====================
void Test(char* pStr)
{
	if (pStr == nullptr)
		printf("Test for nullptr begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

int main(int argc, char* argv[])
{
	Test(nullptr);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	return 0;
}
