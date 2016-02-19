#include "Calculator.h"
#include <iostream>
using namespace std;

int main()
{
	string input;
	Scan scanMachine;
	Print printMachine;

	cin>>input;

	if (scanMachine.ToStringQueue(input))
	{
		printMachine.PrintQueue(scanMachine.m_scanstring);
	}
	else
	{
		cout<<"包含位数超10位的数字,请重新输入！";
	}

	system("pause");

	

}