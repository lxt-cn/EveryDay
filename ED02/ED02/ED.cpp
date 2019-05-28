#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*

两个编程题：
	1>、排序子序列
	2>、逆置字符串

*/
//////////////////////////////////////////////////////////////////////////

/*
1>、
标题：排序子序列 | 时间限制：1秒 | 内存限制：32768k
	牛牛定义排序子序列为一个数组中一段连续的子序列，并且这段子序列是非递增或非递减排序的。
牛牛有一个长度为 n 的整数数组 A ，他现在有一个任务是吧数组 A 分成若干段排序子序列，牛牛
想知道他最少可以把这个数组分为几段排序子序列。
	
	输入描述：
		输入的第一行为一个正整数 n (1 <= n <= 10^5)
		第二行包括 n 个整数 A_i（1 <= A_i <= 10^9）,表示数组 A 的每个数字
	输出描述：
		输出一个整数，表示牛牛可以将 A 最少划分为多少段排序子序列

*/
/*
非递减：a[i] <= a[i+1]
递减：  a[i] > a[i+1]
非递增：a[i] >= a[i+1]
递增：  a[i] < a[i+1]

所以此题有两种情况：
	一：1 2 3 是一个非递减序列，2 2 1 是一个非递增序列
			3
		2		2	2
	1					1
	二：算波峰和波谷有两个，但是排序子序列至少有两个数据
		3		3
			2
	1

*/
void ED01()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		//找出波峰波谷
		if ((v[i - 1]<v[i] && v[i]>v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
		{
			ret++;
			//情况二
			if (i != n - 3)
			{
				i++;
			}
		}
	}
	cout << ret << endl;
}

/////////////////////////////////////////////////////////////////////////////////
/*
2>、
标题：倒置字符串 | 时间限制：1秒 | 内存限制：32768k
	将一句话的单词进行倒置，标点不倒置。
	例如 I like beijing.	经过函数后变为 beijing. like I

	输入描述：
		每个测试输入包括 1 个测试用例：I like beijing.
		输入的用例长度不超过 100
	输出描述：
		依此输出倒置之后的字符串，以空格分隔。
*/

void ED02()
{
	string s;
	getline(cin, s);

	//翻转整个句子
	reverse(s.begin(), s.end());

	//翻转单词
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		reverse(start, end);
		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	cout << s << endl;
}

/////////////////////////////////////////////////////////////////////////////////
int main()
{
	ED01();
	ED02();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//题目二初解
//void ReverseString(string& str, int left, int right)
//{
//	while (left <= right)
//	{
//		int tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void ED02()
//{	
//	string str;
//	getline(cin, str);
//
//	ReverseString(str, 0 , str.size()-1);
//	int left = 0;
//	int right = 0;
//	for (int i = 0; i < str.size() - 1; i++)
//	{
//		if (str[i] == ' ')
//		{
//			right = i - 1;
//			ReverseString(str, left, right);
//			left = i + 1;
//			right = left;
//		}
//		if (i == (str.size() - 2))
//		{
//			right = i + 1;
//			ReverseString(str, left, right);
//		}
//	}
//	cout << str << endl;
//}
















