// _12_String_path_in_matrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <string>
#include <stack>

using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == nullptr || rows<1 ||cols<1 || str == nullptr)
	{
		return false;
	}
	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int	pathLen = 0;
	for (int i = 0; i < rows; i++)	
	{
		for (int j = 0; j < cols; j++)
		{
			if (hasPathCore(matrix, rows, cols, i, j, str, pathLen, visited))
			{
				return true; ;
			}
		}
		
	}
	delete[] visited;
	return false;

}

/*
bool hasPathCore(const char* matrix, int rows, int cols, int row,
	int col, const char* str, int& pathLength, bool* visited)
{
	if (str[0] == '\0')
	{
		return true;
	}
	if (col >= 0 && row >= 0 && col < cols && row < rows && visited[row*cols + col] == 0)
	{
		
		if (matrix[row*cols + col] == str[0])
		{
			pathLength++;
		}
		else
		{
			return false;
		}
		visited[row*cols + col] = 1;
		if (hasPathCore(matrix, rows, cols, row, col + 1, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row - 1, col, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row, col - 1, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row + 1, col, &str[1], pathLength, visited))
			return true;
		visited[row*cols + col] = 0;
		pathLength--;
	}
	return false;
}
*/


/*
// 官方解法
bool hasPathCore(const char* matrix, int rows, int cols, int row,
	int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visited[row * cols + col])
	{
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, pathLength, visited);

		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}
*/

// 实际上不需要pathlength 参数
bool hasPathCore(const char* matrix, int rows, int cols, int row,
	int col, const char* str, int& pathLength, bool* visited)
{
	if (str[0] == '\0')
	{
		return true;
	}
	if (col >= 0 && row >= 0 && col < cols && row < rows && visited[row*cols + col] == 0 && matrix[row*cols + col] == str[0])
	{
		visited[row*cols + col] = 1;

		if (hasPathCore(matrix, rows, cols, row, col + 1, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row - 1, col, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row, col - 1, &str[1], pathLength, visited))
			return true;
		if (hasPathCore(matrix, rows, cols, row + 1, col, &str[1], pathLength, visited))
			return true;
		visited[row*cols + col] = 0;
	}
	return false;
}



// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";

	Test("Test1", (const char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
	const char* matrix = "ABCESFCSADEE";
	const char* str = "SEE";

	Test("Test2", (const char*)matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	Test("Test3", (const char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SLHECCEIDEJFGGFIE";

	Test("Test4", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEM";

	Test("Test5", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEEJIGOEM";

	Test("Test6", (const char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEMS";

	Test("Test7", (const char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAA";

	Test("Test8", (const char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAAA";

	Test("Test9", (const char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
	const char* matrix = "A";
	const char* str = "A";

	Test("Test10", (const char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
	const char* matrix = "A";
	const char* str = "B";

	Test("Test11", (const char*)matrix, 1, 1, str, false);
}

void Test12()
{
	Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();
	getchar();
	return 0;
}