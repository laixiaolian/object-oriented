#pragma once
#include<iostream>
#include<string>
using namespace std;
class department {
public:
	int DepartmentNo; //部门编号
	int MemberLimit;//学生数上限
	string DepartmentTags[20]; //特点标签，两个以上
	string Schedules;//常规活动时间段
	int hour1;
	int hour2;
	string we;
	void DepartmentData(int n, int m);
};