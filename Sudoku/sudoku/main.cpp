#include<iostream>
#include"SudokuGenerate.h"
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{
	SudokuGenerate s;
	int n;
	
	//srand((unsigned)time(NULL));
	freopen("./sudoku.txt", "w", stdout);

	//输入不合法
	if (*argv[2] <= '0' || *argv[2] > '9')
	{
		cout << "Input Error!" << endl;
	}
	else
	{
		n = atoi(argv[2]);
		for (int i = 0; i < n; i++)
		{
			s.init();
			s.initArray();
			s.generate(0);
			//cout << "成功生成第" << i + 1 << "个数独!!" << endl;
		}
	}
	
	return 0;
}