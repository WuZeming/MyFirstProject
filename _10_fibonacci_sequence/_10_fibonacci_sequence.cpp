// _10_fibonacci_sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


long long Fibonacci_Solution1(int n)
{
	if (0 == n)
		return 0;
	if (1 == n)
		return 1;
	if (n > 1)
		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

long long  Fibonacci_Solution2(int n)
{
	if (0 == n)
		return 0;
	if (1 == n)
		return 1;
	int num_1 = 0;
	int num_2 = 1;
	int ret = 0;
	for (int i = 2; i <= n; i++)
	{
		ret = num_1 + num_2;
		num_1 = num_2;
		num_2 = ret;
	}
	return ret;
}

// ====================方法3：基于矩阵乘法====================
#include <cassert>

struct Matrix2By2
{
	Matrix2By2
	(
		long long m00 = 0,
		long long m01 = 0,
		long long m10 = 0,
		long long m11 = 0
	)
		:m_00(m00), m_01(m01), m_10(m10), m_11(m11)
	{
	}

	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
};

Matrix2By2 MatrixMultiply
(
	const Matrix2By2& matrix1,
	const Matrix2By2& matrix2
)
{
	return Matrix2By2(
		matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
		matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
		matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
		matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
	assert(n > 0);

	Matrix2By2 matrix;
	if (n == 1)
	{
		matrix = Matrix2By2(1, 1, 1, 0);
	}
	else if (n % 2 == 0)
	{
		matrix = MatrixPower(n / 2);
		matrix = MatrixMultiply(matrix, matrix);
	}
	else if (n % 2 == 1)
	{
		matrix = MatrixPower((n - 1) / 2);
		matrix = MatrixMultiply(matrix, matrix);
		matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
	}

	return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
	return PowerNMinus2.m_00;
}

// ====================测试代码====================
void Test(int n, int expected)
{
	if (Fibonacci_Solution1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (Fibonacci_Solution2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else
		printf("Test for %d in solution2 failed.\n", n);

	if (Fibonacci_Solution3(n) == expected)
		printf("Test for %d in solution3 passed.\n", n);
	else
		printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);

	return 0;
}