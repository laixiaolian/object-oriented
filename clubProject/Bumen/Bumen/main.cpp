#include<iostream>
#include"Departments.h"
#include"Students.h"
#include"Function.h"
#pragma warning(disable:4996)
using namespace std;
int main()
{
	//输入部门数和学生数
	int n, m;
	cin >> n >> m;
	Student student;
	department d;
	Function function;
	freopen("import.txt", "w", stdout);
	cout << n << " " << m << endl;
	
	//生成部门和学生的数据
	d.DepartmentData(n, m);
	student.StudentData(n, m);

	function.input();//读入数据
	function.GetRank();//计算权重
	function.sort();//对权重从大到小排序
	function.print();//输出
	return 0;
}