#include "Calculator.h"

#include <iostream>

bool Scan::ToStringQueue(string input)

{

	size_t markOfReadPos = 0; //标识已经导入到input的第几位,初始0为input第一位

	bool ifDigit = false; //标识当前读到的字符是否是数字

	bool ifdecimal = false; //标识是否有小数

	for (size_t i = 0; i != input.size(); i++)

	{

		if (isdigit(input[i]) || input[i] == '.') //判断是否为数字,包括小数点

		{

			if (input[i] == '.') //说明此刻的数有小数部分

			{

				ifdecimal = true;

			}

			ifDigit = true;

			continue;
		}


		else //为符号 + - * % （ ）
		
		{
			
			if (ifDigit == true) //判断是否刚读完一串数字
			
			{
				
				ifDigit = false;

				string tmp = input.substr(markOfReadPos,i - markOfReadPos); //i - markOfReadPos为要截取的字符串字符数

				//判断输入的数字是否超过10位

				if (ifdecimal) //有小数位时，要排除小数点“.”占用位
				
				{
					
					if ((tmp.size() - 1) > 10) //整数部分 + 小数部分 超过10位
					
					{
						
						return false;
						
					}
					
				}


				else //整数
				
				{
					
					if (tmp.size() > 10) //整数部分超过10位
					
					{
						
						return false;
						
					}
					
				}


				m_scanstring.push(tmp); //将markOfReadPos 到 i位置的数字 的string导入queue

				markOfReadPos = i;

				ifdecimal = false;
				
			}


			string sign;

			sign.insert( sign.begin(), input[i] ); //把char转化成string

			m_scanstring.push(sign);

			markOfReadPos++;
			
		}
		
	}


	if (ifDigit) //表示表达式最后为数字
	
	{
		string tmp = input.substr(markOfReadPos,input.size() - markOfReadPos); //i - markOfReadPos为要截取的字符串字符数


		//判断输入的数字是否超过10位

		if (ifdecimal) //有小数位时，要排除小数点“.”占用位
		
		{
			
			if ((tmp.size() - 1) > 10) //整数部分 + 小数部分 超过10位
			
			{
				
				return false;
				
			}
			
		}


		else //整数
		
		{
			
			if (tmp.size() > 10) //整数部分超过10位
			
			{
				
				return false;
				
			}
			
		}


		m_scanstring.push(tmp); //将markOfReadPos 到 i位置的数字 的string导入queue
		
	}

	return true;
	
}


void Print::PrintQueue(queue<string>& tmpQueue)

{
	while(!tmpQueue.empty()) //此种遍历会清空queue
	
	{
		
		cout<<tmpQueue.front()<<endl;

		tmpQueue.pop();
		
	}
				
}
