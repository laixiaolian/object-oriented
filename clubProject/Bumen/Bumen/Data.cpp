#include<iostream>
#include<algorithm>
#include"Students.h"
#include"Departments.h"
#include<time.h>
#include<string>
using namespace std;
department depart[3010];
Student stu[3010];
string week[7] = { "Mon","Tues","Wed","Thur","Fri","Sat","Sun" };
string TotalTags[10] = { "programming","reading","film","music","dance","chess","handwriting","photograph","sports" ,"painting" };
void department::DepartmentData(int n, int m)
{
	srand((unsigned)time(NULL));//随机化种子

	for (int i = 0; i < n; i++)
	{
		depart[i].DepartmentNo = i + 1;//部门编号
		depart[i].MemberLimit = (rand() % 15) + 1;//每个部门的限定人数
												  //部门特点标签,每个部门4个
		int count[9] = { 0 };
		for (int j = 0; j < 4;)
		{
			int k = rand() % 9 + 1;
			//解决部门特点标签重复问题
			if (count[k] == 0)
			{
				count[k] = 1;
				depart[i].DepartmentTags[j] = TotalTags[k];
				j++;
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		//cout << "部门编号：" << depart[i].DepartmentNo << "  部门限定人数：" << depart[i].MemberLimit << endl;
		cout << depart[i].DepartmentNo << " " << depart[i].MemberLimit << endl;
		//cout << "部门特点：";

		for (int j = 0; j < 4; j++)
		{
			cout << depart[i].DepartmentTags[j] << "  ";
		}
		cout << endl;
		//cout << "部门常规活动时间段：";
		int day = rand() % 7;
		cout << week[day] << " ";
		int hour1 = rand() % (15 + 1) + 7; //生成空余时间范围为7：00-22：00
		int hour2 = hour1 + 1;

		//int型转换为字符串，方便后面时间的表示
		string str1 = std::to_string(hour2);
		string str2 = std::to_string(hour1);
		depart[i].Schedules = str2 + " :00- " + str1 + " :00";
		cout << depart[i].Schedules << endl;
	}

}
void Student::StudentData(int n, int m)
{
	srand((unsigned)time(NULL));//随机化种子
	for (int i = 0; i < m; i++)
	{

		stu[i].StudentNo = i + 1;
		stu[i].Point = ((double)(rand() % 400 + 100) / 100.0);//学生绩点

		for (int j = 0; j < 5; j++)
		{
			stu[i].aspiration[j] = rand() % n + 1;
		}
		//学生兴趣标签,每个学生3个
		int counts[9] = { 0 };
		for (int j = 0; j < 3; )
		{
			int k = rand() % 9 + 1;
			//解决兴趣标签重复的问题
			if (counts[k] == 0)
			{
				stu[i].StudentTags[j] = TotalTags[k];
				j++;
				counts[k] = 1;
			}

		}
		//cout << "学生编号：" << stu[i].StudentNo << "  绩点：" << stu[i].Point << endl;
		cout << stu[i].StudentNo << " " << stu[i].Point << endl;
		
		for (int j = 0; j < 5; j++)
		{
			//cout << "志愿：" << stu[i].aspiration[j] << " ";
			cout << stu[i].aspiration[j] << " ";
		}
		cout << endl;
		//cout << "学生兴趣：";
		for (int j = 0; j < 3; j++)
		{
			cout << stu[i].StudentTags[j] << " ";
		}
		cout << endl;
		//cout << "学生空闲时间段：" << endl;
		int k[7];
		for (int h = 0; h < 5; h++)
		{
			k[h] = rand() % 7;
		}
		int count[7] = { 0 };
		//每个学生生成五个空余时间段
		for (int l = 0; l<5;)
		{

			int h = rand() % 7;
			//cout << h << endl;
			k[l] = h;
			bool flag = true;
			int hour1 = rand() % (16 + 1) + 7; //生成空余时间范围为7：00-23：00
			int hour2 = rand() % (16 + 1) + 7; //生成空余时间范围为7：00-23：00

			//int型转换为字符串，方便后面时间的表示
			string str1 = std::to_string(hour2);
			string str2 = std::to_string(hour1);

			//要考虑hour1和hour2相等的情况
			if (hour2 != hour1)
			{
				if (hour2 < hour1)
				{
					stu[i].front[l] = hour2;
					stu[i].last[l] = hour1;
					stu[i].FreeTime[l] = str1 + " :00- " + str2 + " :00";
				}
				else if (hour2>hour1)
				{
					stu[i].front[l] = hour1;
					stu[i].last[l] = hour2;
					stu[i].FreeTime[l] = str2 + " :00- " + str1 + " :00";
				}
				count[h]++;
				//说明之前有过这一天出现
				if (count[h] != 1)
				{
					//int f = 0;
					for (int g = 0; g < l; g++)
					{
						if (h == k[g])
						{
							//同一天的空余时间区间有冲突
							if (((stu[i].front[l] <= stu[i].front[g]) && ((stu[i].last[l] >= stu[i].front[g]) ||
								(stu[i].last[l] > stu[i].last[g]))) || ((stu[i].front[l] > stu[i].front[g]) && stu[i].front[l] <= stu[i].last[g]))
							{
								flag = false;
								count[h]--;
								break;
							}
						}
						else
						{
							flag = true;
						}
					}
					if (flag == true)
					{
						cout << week[h] << " " << stu[i].FreeTime[l] << endl;
						l++;
					}
				}
				//之前从来没有这天的空余时间段，直接输出
				else
				{

					cout << week[h] << " " << stu[i].FreeTime[l] << endl;
					l++;
				}
			}
			//生成的前后时间相等时，重新生成
			else
			{
				continue;
			}
		}
	}
}