// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
/*
class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString&  str);
	~CMyString();

private:
	char* m_pData;
};

/*
CMyString& CMyString::operator=(const CMyString& str) {
	if (this == &str)
	{
		return *this;
	}
	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1]; //strlen()返回字符串长度，但是不包括末尾的空字符
	strcpy(m_pData, str.m_pData);

	return *this;

}*/

/*

CMyString& CMyString::operator=(const CMyString& str) {
	//此方案利用临时对象的自然销毁来释放原有内存，且不违背异常安全性原则。
	if (this == &str)
	{
		CMyString tempStr(str);
		char* p_temp = tempStr.m_pData;
		tempStr.m_pData = m_pData;
		m_pData = p_temp;
	}
	return *this;
}



CMyString::CMyString()
{
}

CMyString::~CMyString()
{
}

*/
/*
bool duplicate(int numbers[],int len ,int* duplication) 
{// 查找数组中重复的元素
	//无效输入
	if (numbers == nullptr || len <=0)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (numbers[i]<0 || numbers[i]>len-1)
			return false;
	}
	//开始查找
	for (int i = 0; i < len; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	//未查找到
	cout << "weizhaodao" << endl;
	return false;
}*/
int countRange(int* numbers, int length, int start , int middle) 
{// 利用二分查找，不改变数组元素位置，查找数组中的重复元素，但是此方法存在一定的缺陷。
	if (numbers == nullptr|| length<=0)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i !=length ; i++)
	{
		if (numbers[i]>=start && numbers[i]<=middle)
		{
			++count;
		}
	}
	return count;
}
int getDuplication(int *numbers, int length) 
{
	if (numbers == nullptr || length<=0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;

	while (start<=end)
	{
		int middle = ((end - start) >> 1 ) + start;
		int count = countRange(numbers, length, start, middle);
		if (start == end)
		{
			if (count>1)
			{
				return start;
			}
			else break;
		}
		if (count>middle -start +1)
		{
			end = middle;
		}
		else {
			start = middle+1;
		}
	}
	return -1;
}

/*

int main()
{
	int duplication = NULL;
	int numbers[7] = {1,2,2,4,5,6,6};
	//bool ret = duplicate(numbers, sizeof numbers/4, &duplication);
	int ret = getDuplication(numbers, sizeof numbers / 4);
	cout << "ret: " << ret << "   duplication: " << duplication << endl;
	getchar();
    return 0;
}

*/