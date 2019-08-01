#pragma once

#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、淘宝网店
	2>、斐波那契凤尾
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
1. 标题：淘宝网店 | 时间限制：1秒 | 内存限制：32768K 
	NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。

	输入描述： 
		输入包含多组数据。
		每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31)。
		日期用三个正整数表示，用空格隔开：year month day。 
	输出描述： 
		对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。 
	
	示例1:
		输入
			2000 1 1 2000 1 31
			2000 2 1 2000 2 29
		输出 
			62
			29

*/

//闰年判断函数 
inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//足年天数 
inline int profit_of_year(int year)
{
	return 2 * 31         
		 + 1 * 28   
		 + 1 * 31
		 + 2 * 30  
		 + 1 * 31  
		 + 2 * 30 
		 + 1 * 31
		 + 2 * 31  
		 + 2 * 30 
  		 + 2 * 31
		 + 1 * 30
		 + 2 * 31 
		 + leap_year(year);
}

//判断这个月份是不是质数月 
inline bool prime(int n) 
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}

//求出一个日子是这一年的第几天 
int profit_of_this_year(int year, int month, int day)
{
    if(!prime(month))
	{
        day *= 2;
	}
	while(--month)   
	{
        switch(month)  
		{
		case 1:
		case 8:   
		case 10:     
		case 12:    
			day += 62;       
			break;
		case 3:
		case 5: 
		case 7:  
			day += 31;
			break;   
		case 4:  
		case 6:  
		case 9:    
			day += 60; 
			break;   
		case 11:  
			day += 30;   
			break;
		case 2:   
			day += 28 + leap_year(year);   
			break;   
		default:
			;
		}
	}  
	return day;
}

void ED01()
{
	int year1, month1, day1, year2, month2, day2; 
	int count_profit = 0; 
	while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) 
	{
		count_profit = 0;   
		count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1); 
		//这里的day1 - 1虽然有可能会出现0日，但是实际2月0日就相当于1月31日，所以不影响结果。      
		count_profit += profit_of_this_year(year2, month2, day2);   
		if(year1 == year2) //避免起点和终点是同一年，如果是同一年，要减掉这一年的天数。    
		{
			count_profit -= profit_of_year(year1);  
		}  
		for(int i = year1 + 1; i < year2; i++) //中间足年每一年的天数        
		{
			count_profit += profit_of_year(i);
		}
		std::cout << count_profit << std::endl; 
	}	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2. 标题：斐波那契凤尾 | 时间限制：3秒 | 内存限制：32768K
	NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。
当然，斐波那契数会很大。因此，如果第n个 斐波那契数不到6位，则说出该数；否则只说出最后6位。

	输入描述： 
		输入有多组数据。 
		每组数据一行，包含一个整数n (1≤n≤100000)。
	输出描述： 
		对应每一组输入，输出第n个斐波那契数的最后6位。 
		
	示例1:
		输入
			1 
			2
			3
			4
			100000
		输出 
			1
			2
			3
			5
			537501

*/
void ED02() {
	int fib[100001];
	fib[0] = 1; 
	fib[1] = 1;
	//提前计算斐波那契数列，只保留后6位    
	for (int i = 2; i <= 100000; ++i)    
	{
		fib[i] = fib[i - 1] + fib[i - 2]; 
		fib[i] = fib[i] % 1000000;	//由于是相加，所以只要后六位不影响下一个数的结果    
	}
	//这里利用了OJ平台计时从开始读取数据的trick，这个技巧可以用在很多题目里   
	int n; 
	while (std::cin >> n) 
	{
		if (n < 29)
		{ 
			//斐波那契数列小于6位         
			printf("%d\n", fib[n]); 
		}   
		else 
		{
			printf("%06d\n", fib[n]);    
		}
	}
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//ED01();
	ED02();
	return 0;
}