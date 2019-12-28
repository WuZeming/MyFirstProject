// _38_2_strCombination.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
void Combination(char *pStr, int num,std::string buff);
void Combination(char *pStr)
{
	if (pStr == nullptr)
	{
		return;
	}
	std::string buff;
	Combination(pStr, strlen(pStr),buff);
}

void Combination(char *pStr, int num, std::string buff)
{
	if (*pStr == '\0'|| num == 0)
	{
		std::cout << buff << std::endl;
		return;
	}

	Combination(pStr + 1, num,buff);
	buff = buff + *pStr;
	Combination(pStr + 1, num - 1,buff);
}




// ====================测试代码====================
void Test(char* pStr)
{
	if (pStr == nullptr)
		printf("Test for nullptr begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Combination(pStr);

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
