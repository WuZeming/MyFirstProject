#include "stdafx.h"
#include <iostream>
using namespace std;

bool find(int **matrix , int rows, int columns, int elements)
{// 从有序二维数组中查找指定元素
	if (matrix == nullptr || rows<=0 || columns<= 0)
	{
		return false;
	}
	int currRow = 0;
	int currColumn = columns - 1;
	while (currRow <rows && currColumn >= 0)
	{
		if (*((int*)matrix+currRow*columns+currColumn) == elements)
		{
			return true;
		}
		if (*((int*)matrix + currRow*columns + currColumn) < elements)
		{
			++currRow;
		}
		if (*((int*)matrix + currRow*columns + currColumn)>elements)
		{
			--currColumn;
		}
	}
	return false;
}

/*
int main() 
{
	int matrix[4][4] = { 1, 2, 8, 9,
						2, 4, 9, 12,
						4, 7, 10, 13,
						6, 8, 11, 15 };
	int element = 6;
	bool ret = find((int**)matrix, 4, 4,element);
	cout << "result: " << ret << endl;
	getchar();
}*/