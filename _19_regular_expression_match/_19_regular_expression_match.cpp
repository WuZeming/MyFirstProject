// _19_regular_expression_match.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

bool matchCore(const char* string, const char* pattern)
{
	if (*string == '\0' && *pattern == '\0')
	{
		return true;
	}
	if (*string != '\0' && *pattern == '\0')
	{
		return false;
	}
	if (*(pattern+1) == '*')
	{
		if (*pattern == *string || (*pattern == '.'&& *string != '\0'))
		{
			return matchCore(string + 1, pattern + 1) ||
				   matchCore(string, pattern + 2) ||
				   matchCore(string + 1,pattern);
		}
		else
		{
			return matchCore(string, pattern + 2);
		}
	}
	if (*string == *pattern || (*pattern == '.'&& *string!='\0'))
	{
		return matchCore(string + 1, pattern + 1);
	}
	else
	{
		return false;
	}

}

bool match(const char* string,const char* pattern)
{
	if (string == nullptr|| pattern ==nullptr)
	{
		return false;
	}
	return matchCore(string, pattern);
}


// ====================���Դ���====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (match(string, pattern) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Test("Test01", "", "", true);
	Test("Test02", "", ".*", true);
	Test("Test03", "", ".", false);
	Test("Test04", "", "c*", true);
	Test("Test05", "a", ".*", true);
	Test("Test06", "a", "a.", false);
	Test("Test07", "a", "", false);
	Test("Test08", "a", ".", true);
	Test("Test09", "a", "ab*", true);
	Test("Test10", "a", "ab*a", false);
	Test("Test11", "aa", "aa", true);
	Test("Test12", "aa", "a*", true);
	Test("Test13", "aa", ".*", true);
	Test("Test14", "aa", ".", false);
	Test("Test15", "ab", ".*", true);
	Test("Test16", "ab", ".*", true);
	Test("Test17", "aaa", "aa*", true);
	Test("Test18", "aaa", "aa.a", false);
	Test("Test19", "aaa", "a.a", true);
	Test("Test20", "aaa", ".a", false);
	Test("Test21", "aaa", "a*a", true);
	Test("Test22", "aaa", "ab*a", false);
	Test("Test23", "aaa", "ab*ac*a", true);
	Test("Test24", "aaa", "ab*a*c*a", true);
	Test("Test25", "aaa", ".*", true);
	Test("Test26", "aab", "c*a*b", true);
	Test("Test27", "aaca", "ab*a*c*a", true);
	Test("Test28", "aaba", "ab*a*c*a", false);
	Test("Test29", "bbbba", ".*a*a", true);
	Test("Test30", "bcbbabab", ".*a*a", false);

	return 0;
}