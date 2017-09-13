#include<iostream>
#include<cstdio>
#include<string>
#include"SudokuGenerate.h"
#include<time.h>
using namespace std;

//每次生成新的数独之前，初始化二维数组
void SudokuGenerate::init()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			num[i][j] = 0;
		}
	}
}

//每次生成新的数独之前，先生成一个新的一维数组，将数字1-9的顺序打乱
//之后在生成9*9数独的每行时都随机从该一维数组中抽取元素
void SudokuGenerate::initArray()
{
	int array[9] = { 0 };
	count[11] = { 0 };
	int h=0;
	for(h=0;h<9;)
	{
		int temp = rand() % 9;
		//判断此次生成的temp是否已经在该一维数组中
		if (array[temp] == 0)
		{
			//因为temp=rand()%9生成的是0-8的随机数，所以要加一
			count[h] = temp+1;

			//标记这个随机数已经存在在一维数组中。
			array[temp] = 1;
			h++;
		}
	}

	//生成的一维数组
	/*for (int p = 0; p < 9; p++)
	{
		cout << count[p] << " ";
	}*/
	//cout << endl << endl;
}

//利用回溯法生成数独
bool SudokuGenerate::generate(int k)
{
	int i = k / 9;
	int j = k % 9;
	if (k == 81)
	{
		//生成一个数独，打印
		print();
		cout << endl;
		//printf("\n");
		return true;
	}

	//如果9*9方格中位置(i,j)已经放置了数字
	else if (num[i][j] != 0)
	{
		//生成下一位置的数字
		if (generate(k + 1))
		{
			return true;
		}
	}

	//对空位(i,j)生成数字
	else
	{
		//数独每行的数字从一维数组中随机抽取
		for (int l = 1; l <= 9;l++)
		{
			int temp = rand() % 9;
			num[i][j] = count[temp];

			//判断填入数字是否合法
			if (IsRightPlace(num[i][j], i, j))
			{
				if (generate(k + 1)) 
				{
					return true;
				}
			}
		}

		//不合法，则位置(i,j)重置为0，回溯
		num[i][j] = 0;
	}
	return false;
}

//判断填入的数字是否合法
bool SudokuGenerate::IsRightPlace(int number, int row, int col)
{
	int temp = number;

	//同列不同行中是否存在与之相同的数字
	for (int i = 0; i < 9; i++)
	{
		if (i != row&&num[i][col] == temp)
		{
			return false;
		}
	}

	//同行不同列行中是否存在与之相同的数字
	for (int i = 0; i < 9; i++)
	{
		if (i != col&&num[row][i] == temp)
		{
			return false;
		}
	}

	//判断3*3九宫格是否合法
	int m = row / 3;
	m *= 3;
	int n = col / 3;
	n *= 3;
	for (int i = m; i < m+3; i++)
	{
		for (int j = n; j < n+3; j++)
		{
			if (i != row&&j != col&&num[i][j] == temp)
			{
				return false;
			}
		}
	}
	return true;
}

//打印数独
void SudokuGenerate::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << num[i][j] << " ";
			//printf("%d ", num[i][j]);
		}
		cout << endl;
		//printf("\n");
	}
}


void SudokuGenerate::set(int number)
{
	init();
	num[0][0] = number;
}