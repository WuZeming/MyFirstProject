// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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

	m_pData = new char[strlen(str.m_pData) + 1]; //strlen()�����ַ������ȣ����ǲ�����ĩβ�Ŀ��ַ�
	strcpy(m_pData, str.m_pData);

	return *this;

}*/

/*

CMyString& CMyString::operator=(const CMyString& str) {
	//�˷���������ʱ�������Ȼ�������ͷ�ԭ���ڴ棬�Ҳ�Υ���쳣��ȫ��ԭ��
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
{// �����������ظ���Ԫ��
	//��Ч����
	if (numbers == nullptr || len <=0)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (numbers[i]<0 || numbers[i]>len-1)
			return false;
	}
	//��ʼ����
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
	//δ���ҵ�
	cout << "weizhaodao" << endl;
	return false;
}*/
int countRange(int* numbers, int length, int start , int middle) 
{// ���ö��ֲ��ң����ı�����Ԫ��λ�ã����������е��ظ�Ԫ�أ����Ǵ˷�������һ����ȱ�ݡ�
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