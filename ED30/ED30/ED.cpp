#pragma once

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、美国节日
	2>、分解因数
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
1. 标题：美国节日 | 时间限制：1秒 | 内存限制：32768K 
	和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不 相同。
	具体规则如下：
		* 1月1日：元旦
		* 1月的第三个星期一：马丁·路德·金纪念日
		* 2月的第三个星期一：总统节
		* 5月的最后一个星期一：阵亡将士纪念日
		* 7月4日：美国国庆
		* 9月的第一个星期一：劳动节
		* 11月的第四个星期四：感恩节
		* 12月25日：圣诞节
	现在给出一个年份，请你帮忙生成当年节日的日期。

	输入描述： 
		输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。 
	输出描述： 
		对应每一组数据，以“YYYY-MM-DD”格式输出当年所有的节日日期，每个日期占一行。
		每组数据之后输出一个空行作为分隔。 
		
	示例1: 
		输入 
			2014 
			2013 
		输出 
			2014-01-01	
			2014-01-20 
			2014-02-17
			2014-05-26
			2014-07-04
			2014-09-01 
			2014-11-27
			2014-12-25

			2013-01-01 
			2013-01-21 
			2013-02-18
			2013-05-27 
			2013-07-04
			2013-09-02 
			2013-11-28
			2013-12-25
*/

// 根据 年-月-日 通过蔡勒公式计算当前星期几 
// 1: 星期一 ... 7: 星期日
int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)  
	{
		month += 12; 
		year -= 1; 
	}

	int century = year / 100; 
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;    
	week = (week % 7 + 7) % 7;
	if (week == 0) 
	{
		week = 7; 
	}
	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1); //求出1号星期数  
	// 1 + 7(n - 1) + (所求星期数 + 7 - 1号星期数) % 7   
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;  
	return day; 
}

// 元旦 
void new_year_day(int year) 
{
	printf("%d-01-01\n", year); 
}

// 马丁·路德·金纪念日（1月的第三个星期一） 
void martin_luther_king_day(int year) 
{ 
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1)); 
}

// 总统日（2月的第三个星期一）
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}

// 阵亡将士纪念日（5月的最后一个星期一） 
void memorial_day(int year) 
{
	// 从 6 月往前数   
	int week = day_of_week(year, 6, 1);    
	// 星期一的话，从 31 号往前数 6 天，否则，数 week - 2 天
	int day = 31 - ((week == 1) ? 6 : (week - 2));  
	printf("%d-05-%02d\n", year, day); 
}

// 国庆 
void independence_day(int year) 
{
	printf("%d-07-04\n", year);
}

// 劳动节（9月的第一个星期一） 
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}

// 感恩节（11月的第四个星期四）
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}

// 圣诞节 
void christmas(int year)
{
	printf("%d-12-25\n", year); 
}

// 美国节日 
void holiday_of_usa(int year)
{
	new_year_day(year);
	martin_luther_king_day(year); 
	president_day(year);   
	memorial_day(year);    
	independence_day(year);   
	labor_day(year); 
	thanks_giving_day(year);  
	christmas(year);
}

void ED01()
{
	int year;
	while (std::cin >> year)
	{
		holiday_of_usa(year);
		putchar('\n');
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2. 标题：分解因数 | 时间限制：1秒 | 内存限制：32768K 
	所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,
并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。 

	输入描述： 
		输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。 
	输出描述：
		对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。 
		
	示例1:
		输入
			10
			18
		输出 
			10 = 2 * 5
			18 = 2 * 3 * 3
*/
void ED02() {
	unsigned int n;
	while (std::cin >> n)
	{
		printf("%d =", n); //输出 n =   
		for (unsigned i = 2; i <= std::sqrt(n); i++)
		{
			//反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况 
			while (n % i == 0 && n != i)  
			{
				//第一次打印 2 *,第二次打印两个 3 *
				printf(" %u *", i); 
				//能整除就修改n的值    
				n /= i;   
			}
		}
		//跳出后，n 已经是处理过的一个质数，就是最后一个质因数：5  
		printf(" %d\n", n);  
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//ED01();
	ED02();
	return 0;
}
