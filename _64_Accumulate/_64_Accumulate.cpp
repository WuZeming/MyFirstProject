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

// ������64����1+2+��+n
// ��Ŀ����1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
// �ȹؼ��ּ������ж���䣨A?B:C����

#include <cstdio>

// ====================����һ====================
class Temp 
{
public:
	Temp() { N++; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static int GetSum()
	{
		return Sum;
	}


private:
	static int N;
	static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

int Sum_Solution1(int n)
{
	Temp::Reset();
	Temp* p= new Temp[n];
	delete[] p;
	p = nullptr;

	return Temp::GetSum();

}
// ====================������====================
class A;
A* array[2];
class A
{
public:
	virtual int fun(int n)
	{
		return 0;
	}
};

class B :public A
{
	virtual int fun(int n)
	{
		return array[!!n]->fun(n - 1)+n;
	}
};

int Sum_Solution2(int n)
{
	A a;
	B b;
	array[0] = &a;
	array[1] = &b;

	return array[1]->fun(n);
}

// ====================������====================
typedef unsigned int(*fun)(unsigned int);
fun f[2];
unsigned int function(unsigned int n)
{
	return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
	f[0] = function;
	f[1] = Sum_Solution3;
	return f[!!n](n - 1) + n;
}

// ====================������====================
template<unsigned int n> struct Sum_Solution4
{
	enum Value {N = Sum_Solution4<n-1>::N + n};
};
template<> struct Sum_Solution4<1>{
	enum Value { N = 1 };
};
template<> struct Sum_Solution4<0>
{

	enum { N = 0 };
};

// ====================���Դ���====================
void Test(int n, int expected)
{
	printf("Test for %d begins:\n", n);

	if (Sum_Solution1(n) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	if (Sum_Solution2(n) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.\n");

	if (Sum_Solution3(n) == expected)
		printf("Solution3 passed.\n");
	else
		printf("Solution3 failed.\n");
}

void Test1()
{
	const unsigned int number = 1;
	int expected = 1;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test2()
{
	const unsigned int number = 5;
	int expected = 15;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test3()
{
	const unsigned int number = 10;
	int expected = 55;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test4()
{
	const unsigned int number = 0;
	int expected = 0;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}