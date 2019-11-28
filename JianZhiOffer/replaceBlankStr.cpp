#include"stdafx.h"
#include<iostream>
// ������5���滻�ַ����еĿո�
void replaceBlank(char*str, int length)
{
	if (str == nullptr ||length<=0)
	{
		return;
	}
	//�����ַ������ҳ��ո�����
	int countBlank = 0;
	int originLen = 0;
	int i = 0;
	while(str[i]!='\0')
	{
		if (str[i] == ' ')
		{
			++countBlank;
		}
		++originLen;
		++i;
	}
	int newLength = originLen + countBlank * 2;
	if (newLength>length)
	{
		return;
	}
	int end = newLength;
	int curr = originLen;
	while (end !=curr)
	{
		if (str[curr] == ' ')
		{
			str[end--] = '0';
			str[end--] = '2';
			str[end--] = '%';
		}
		else
		{
			str[end--] = str[curr];
		}
		--curr;
	}
}


int main()
{
	char str[100] = "   we are happy     ";
	std::cout << str << std::endl;
	replaceBlank(str,100);
	std::cout << str << std::endl;
	getchar();
}