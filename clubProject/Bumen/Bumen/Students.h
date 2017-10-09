#pragma once
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
	int StudentNo;
	string FreeTime[5];//空余时间，多个
	string StudentTags[10];//标签，多个
	double Point;//绩点
	int aspiration[6];//志愿
	int front[6];
	int last[6];
	string we[6];
	void StudentData(int n, int m);
	//学生有五个志愿
};