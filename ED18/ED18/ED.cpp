#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////

/*
两个编程题:
	1>、统计每个月兔子的总数
	2>、字符串通配符
*/

////////////////////////////////////////////////////////////////////////////////////////////
/*
1>
标题：统计每个月兔子的总数 | 时间限制：1秒 | 内存限制：32768K
	有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔
子都不死，问每个月的兔子总数为多少？

	统计出兔子总数。
	param monthCount 第几个月
	return 兔子总数

	public static int getTotalCount(int monthCount)
	{
		return 0;
	}

	输入描述：
		输入int型表示month
	输出描述：
		输出兔子总数int型
*/
int fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int getTatalCount(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return getTatalCount(n - 1) + fib(n - 2);
	}
}

void ED01()
{
	int n = 0;
	while (cin >> n)
	{
		cout << getTatalCount(n) << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
/*
2>
标题：字符串通配符 | 时间限制：1秒 | 内存限制：32768K
	问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求
各位实现字符串通配符的算法。

	要求：
		实现如下2个通配符：
			*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
			？：匹配1个字符
	输入：
		通配符表达式；
			一组字符串。	输出：
		返回匹配的结果，正确输出true，错误输出false
	
	输入描述：
		先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
	输出描述：
		返回匹配的结果，正确输出true，错误输出false
	
	示例1:
		输入
			te?t*.*
			txt12.xls
		输出
			false
*/
bool match(const char* pattern, const char *str)
{
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}
void ED02()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//ED01();
	ED02();
	return 0;
}