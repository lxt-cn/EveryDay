#include <iostream>
#include <vector>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
两个编程题：
	1>、小易的升级之路
	2>、找出字符串中第一个只出现一次的字符(题面已经更新)
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
1. 标题：小易的升级之路 | 时间限制：1秒 | 内存限制：32768K 
	小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,
每个怪物的防御力为b1,b2,b3...bn. 如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值
增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.那么问 题来了,在一系列的锻炼后,小易的最终能力值为多少?

	输入描述： 
		对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值. 第二行n个整数,b1,b2...bn(1≤bi≤n)
		表示每个怪物的防御力 
	输出描述： 
		对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值 
		
	示例1: 
		输入
			3 50 
			50 105 200 
			5 20 
			30 20 15 40 100
		输出 
			110 
			205
*/

int Gac(int x, int y)
{
	if (x > y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	int max = 1;
	for (int i = 2; i <= x; i++)
	{
		if (x%i == 0 && y%i == 0)
		{
			if (max < i)
			{
				max = i;
			}
		}
	}
	return max;
}

void ED01()
{
	int n = 0;
	int a = 0;
	while (cin >> n >> a)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int bi = 0;
			cin >> bi;
			vec.push_back(bi);
		}
		for (int i = 0; i < n; i++)
		{
			if (a >= vec[i])
			{
				a += vec[i];
			}
			else
			{
				a += Gac(a, vec[i]);
			}
		}
		cout << a << endl;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
2. 标题：找出字符串中第一个只出现一次的字符(题面已经更新) | 时间限制：1秒 | 内存限制：32768K 
	找出字符串中第一个只出现一次的字符

	输入描述： 
		输入一个非空字符串
	输出描述： 
		输出第一个只出现一次的字符，如果不存在输出-1

	例1: 
		输入 
			asdfasdfo
		输出 
			o
*/
char FirstOne(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int count = 1;
		for (int j = 0; j < str.length(); j++) 
		{
			if (str[i] == str[j] && i != j)
			{
				count++;
			}
			if (count != 1)
			{
				break;
			}
		}
		if (count == 1)
		{
			return str[i];
		}
	}
	return -1;
}

void ED02()
{
	string str;
	while (cin >> str)
	{
		char c = FirstOne(str);
		if (c == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << c << endl;
		}
	}
}

int main()
{
	//ED01();
	ED02();
	return 0;
}