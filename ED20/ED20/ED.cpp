#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
两个编程题：
	1>、字符串反转
	2>、公共字串计算
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

1. 标题：字符串反转 | 时间限制：1秒 | 内存限制：32768K 
	写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。
	
	例如：
		输入描述： 
			输入N个字符
		输出描述： 
			输出该字符串反转后的字符串

	示例1: 
		输入 
			abcd
		输出 
			dcba

*/
void ED01()
{
	string str;
	while (cin >> str)
	{
		int begin = 0;
		int end = str.length() - 1;
		while (begin < end)
		{
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			begin++;
			end--;
		}
		cout << str << endl;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2. 标题：公共字串计算 | 时间限制：1秒 | 内存限制：32768K 
	计算两个字符串的最大公共字串的长度，字符不区分大小写

	详细描述：
		接口说明
		原型：
			int getCommonStrLength(char * pFirstStr, char * pSecondStr);	
			输入参数：
				char * pFirstStr //第一个字符串
				char * pSecondStr//第二个字符串

	输入描述： 
		输入两个字符串
	输出描述： 
		输出一个整数

	示例1: 
		输入 
			asdfas
			werasdfaswer 
		输出 
			6
*/
int getCommonStrLength(string str1, string str2)
{
	int max = 0;
	for (size_t i = 0; i < str1.length(); i++)
	{
		for (size_t j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				int count = 0;
				int cur1 = i;
				int cur2 = j;
				while (str1[cur1++] == str2[cur2++])
				{
					count++;
					if (cur1 == str1.length() || cur2 == str2.length())
					{
						break;
					}
				}
				if (max < count)
				{
					max = count;
				}
			}
		}
	}
	return max;
}

void ED02()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int ret = getCommonStrLength(str1, str2);
		cout << ret << endl;
	}
}

int main()
{
	ED01();
	ED02();
	return 0;
}