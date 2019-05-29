/*

两个编程题：
	1>、字符串中找出连续最长的数字串
	2>、n 个数离出现次数大于等于 n/2 的数

*/

///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////

/*

1>、
标题：字符串中找出连续最长的数字串 | 时间限制： 1 秒 | 内存限制：32768k
	输入一个字符串 str,输出字符串 str 中的连续最常的数字串

	输入描述：
		一个测试输入包含一个测试用例，一个字符串 str,长度不超过 255
	输出描述：
		在一行内输出 str 中连续最长的数字串

*/

///////////////////////////////////////////////////////////////////////////////////

//初解
void ED01_01()
{
	string str;
	cin >> str;

	string ret, cur;
	int count = 0;
	int max = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 49 && str[i] <= 57)
		{
			cur = &(str[i]);	//记录出现数字的地址
			count = 0;
			//统计每次连续出现数字的长度
			for (int j = i; j < str.length(); j++)	
			{
				if (str[j] > 57 || str[j] < 49)
				{
					i = j;
					break;
				}
				count++;
			}
		}
		//每次统计好的数字与上一次进行计较，如果比上一次长，
		//则记录好数字穿的长度，并记录好数字开始位置
		//长度用来控制子数字串长度
		if (max < count)
		{
			max = count;
			ret = cur;
		}
	}
	ret.resize(max);
	cout << ret << endl;
}

//优化
void ED01_02()
{
	string str, res, cur;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		//数字 += 到 cur
		if (str[i] >= '0'&&str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			//找出更长的字符串，则更新字符串
			if (res.size() < cur.size())
			{
				res = cur;
			}
			else
			{
				cur.clear();
			}
		}
	}
	cout << res << endl;
}

///////////////////////////////////////////////////////////////////////////////////
/*

2>、
标题：n 个数离出现次数大于等于 n/2 的数 | 时间限制： 1 秒 | 内存限制：32768k
	输入 n 个整数，输出出现次数大于等于数组长度一半的数

	输入描述：
		每个测试输入包含 n 个空格分隔的 n 个整数， n 不超过100，其中有一个整数出现次数大于等于 n/2
	输出描述：
		输出出现次数大于等于 n/2 的数

*/

///////////////////////////////////////////////////////////////////////////////////
//初解：排序找中间数
void ED02_01()
{
	vector<int> Vec;
	int a = 0;
	while (cin >> a)
	{
		Vec.push_back(a);
	}

	sort(Vec.begin(), Vec.end());

	cout << Vec[Vec.size() / 2 - 1] << endl;
}

//时间优化，时间复杂度：O(n)
void ED02_02()
{
	vector<int> Vec;
	int a = 0;
	while (cin >> a)
	{
		Vec.push_back(a);
	}

	int count = 1;
	int key = Vec[0];
	for (int i = 1; i < Vec.size(); ++i)
	{
		if (key == Vec[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count == 0)
		{
			key = Vec[i];
			count++;
		}
	}
	cout << key << endl;
}


///////////////////////////////////////////////////////////////////////////////////

int main()
{
	ED01_01();
	ED01_02();
	ED02_01();
	ED02_02();
	return 0;
}

