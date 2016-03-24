#include<queue>
#include "string"
using namespace std;

class Scan
{
	public:
		Scan() {};
		~Scan() {};
		
	public:
		bool ToStringQueue(string input); //读取用户输入的四则运算表达式inupt,分解后转存到m_scanstring
		
	public:
		queue<string> m_scanstring;	
};


class Print
{
	public:
		Print() {};
		~Print() {};
		
	public:
		void PrintQueue(queue<string>& tmpQueue); //接受一个队列
};
