#include<iostream>
#include<vector>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、汽水瓶
	2>、查找两个字符串a,b中的最长公共子串
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

1. 标题：汽水瓶 | 时间限制：1秒 | 内存限制：32768K
	有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换 多少瓶汽水喝？”答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3 个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板
先借给你一瓶汽水，喝掉这瓶满的，喝完以 后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

	输入描述： 
		输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的 空汽水瓶数。
		n=0表示输入结束，你的程序不应当处理这一行。
	输出描述： 
		对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

*/

void ED01()
{
	int n = 0;
	vector<int> vec;
	int count = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		int Empty = n;
		int Water = 0;
		if (n < 2)
		{
			Empty = 0;
		}
		while (Empty > 1)
		{
			Water += Empty / 3;
			Empty = Empty % 3 + Empty / 3;
			if (Empty == 2)
			{
				Water++;
				break;
			}
		}
		vec.push_back(Water);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
2. 标题：查找两个字符串a,b中的最长公共子串 | 时间限制：1秒 | 内存限制：32768K 
	查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。 
	
	输入描述：
		输入两个字符串 
	输出描述： 
		返回重复出现的字符 
		
	示例1: 
	输入 
		abcdefghijklmnop 
		abcsafjklmnopqrstuvw 
	输出 
		jklmnop
*/
void ED02()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		if (str1.length() > str2.length())
		{
			swap(str1, str2);
		}
		string ret = str1;
		int max = 0;
		for (size_t i = 0; i < str1.length(); i++)
		{
			for (size_t j = 0; j < str2.length(); j++)
			{
				if (str1[i] == str2[j])
				{
					int cur1 = i;
					int cur2 = j;
					int count = 0;
					while (str1[cur1++] == str2[cur2++])
					{
						count++;
						if (str1[cur1] == '\0' || str2[cur2] == '\0')
							break;
					}
					if (count > max)
					{
						max = count;
						if (str1.length() < str2.length())
						{
							ret = &str1[i];
						}
						else
						{
							ret = &str2[j];
						}
					}
				}
			}
		}
		for (int i = 0; i < max; i++)
		{
			cout << ret[i];
		}
		cout << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	ED01();
	ED02();
	return 0;
}