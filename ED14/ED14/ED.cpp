#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、计算日期到天数转换
	2>、幸运的袋子
*/

//////////////////////////////////////////////////////////////////////////////////////////
/*
1>
标题：计算日期到天数转换 | 时间限制：1秒 | 内存限制：32768K
	根据输入的日期，计算是这一年的第几天。。
	详细描述：
		输入某年某月某日，判断这一天是这一年的第几天？。

	接口设计及说明：
		Description : 数据转换
		Input Param : year 输入年份
		Month 输入月份
		Day 输入天
		Output Param :
		Return Value : 成功返回0，失败返回-1（如：数据错误）

		public static int iConverDateToDay(int year, int month, int day)
		{
			//在这里实现功能，将结果填入输入数组中
			return 0;
		}

		Description :
		Input Param :
		Output Param :
		Return Value : 成功:返回outDay输出计算后的第几天;
		失败:返回-1

		public static int getOutDay()
		{
			return 0;
		}

		输入描述：
			输入三行，分别是年，月，日
		输出描述：
			成功 : 返回outDay输出计算后的第几天;
			失败:返回 - 1
*/

//初解
vector<int> vec{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool IsPre(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

void iConverDateToDay(int year, int month, int day)
{
	int outday = 0;
	if ((IsPre(year)) && month > 2 || (month == 2 && day == 29))
	{
		outday = 1;
	}
	for (int i = 0; i < month - 1; i++)
	{
		outday += vec[i];
	}
	cout << (outday + day) << endl;
}

void ED01_01()
{
	int year = 0;
	int month = 0;
	int day = 0;
	while (cin >> year >> month >> day) 
	{
		iConverDateToDay(year, month, day);
	}
}

//整理后
void ED01_02()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
/*

2>
标题：幸运的袋子 | 时间限制：1秒 | 内存限制：32768K
	一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当
且仅当所有球的号码的和大于所有球的号码的积。
	
	例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
	你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算
一下你可以获得的多少种不同的幸运的袋子。

	输入描述：
		第一行输入一个正整数n(n ≤ 1000)
		第二行为n个数正整数xi(xi ≤ 1000)
	输出描述：
		输出可以产生的幸运的袋子数

		*/


int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//如何sum大于multi,则后面就没有符合要求的组合了
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

void ED02()
{
	int n;
	while (cin >> n)
	{
		int *x = new int [n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//ED01_01();
	//ED01_02();
	ED02();
	return 0;
}