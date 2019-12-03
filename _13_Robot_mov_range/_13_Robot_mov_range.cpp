// _13_Robot_mov_range.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void movingCore(int threshold, int rows, int cols, int row, int col, int& count, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col);
int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows<=0 || cols<= 0)
	{
		return 0;
	}
	bool* visited = new bool[rows*cols];
	memset(visited,0,rows*cols);
	int count = 0;
	movingCore(threshold,rows,cols,0,0,count,visited);

	delete[] visited;
	return count;
}

void movingCore(int threshold, int rows, int cols, int row, int col, int& count,bool* visited)
{
	if (!visited[row*cols + col] && check(threshold, rows, cols, row, col))
	{
		++count;
		visited[row*cols + col] = 1;
		movingCore(threshold, rows, cols, row, col + 1, count, visited);
		movingCore(threshold, rows, cols, row - 1, col, count, visited);
		movingCore(threshold, rows, cols, row, col - 1, count, visited);
		movingCore(threshold, rows, cols, row + 1, col, count, visited);

	}

}
int getSum(int num)
{
	int sum = 0;
	while (num!=0)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}
bool check(int threshold, int rows, int cols, int row, int col) 
{
	if (row>=0 && col>=0 && row< rows && col<cols)
	{
		int sum = getSum(row) + getSum(col);
		if (sum<=threshold)
		{
			return true;
		}
	}
	return false;
}

// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
	test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
	test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
	test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
	test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
	test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
	test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
	test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
	test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
	test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
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
	getchar();
	return 0;
}