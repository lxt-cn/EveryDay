#include <iostream>
#include <string>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
/*
两个面试题：
	1>、
	2>、
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
1>
标题：两种排序方法 | 时间限制：1秒 | 内存限制：32768K
	考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
		1)根据字符串的字典序排序。例如：
			"car" < "carriage" < "cats" <
			"doggies < "koala"
		2)根据字符串的长度排序。例如：
			"car" < "cats" < "koala" <
			"doggies" < "carriage"
	考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

	输入描述：
		输入第一行为字符串个数n(n ≤ 100)接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
	输出描述：
		如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
		如果根据长度排列而不是字典序排列输出"lengths",
	如果两种方式都符合输出"both"，否则输出"none"

*/
/////////////////////////////////////////////////////////////////////////////////////////

bool IsLexSort(vector<string> SArr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (SArr[i] > SArr[i+1])
		{
			return false;
		}
	}
	return true;
}

bool IsLengSort(vector<string> SArr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (SArr[i].length() > SArr[i+1].length())
		{
			return false;
		}
	}
	return true;
}

void ED01()
{
	int n = 0;
	cin >> n;
	vector<string> SArr;
	SArr.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> SArr[i];
	}

	bool ret1 = IsLexSort(SArr, n);
	bool ret2 = IsLengSort(SArr, n);
	if (ret1 && ret2)
	{
		cout << "both" << endl;
	}
	if (ret1 == true && ret2 != true)
	{
		cout << "lexicographica" << endl;
	}
	if (ret2 == true && ret1 != true)
	{
		cout << "lengths" << endl;
	}
	if (ret1 != true && ret2 != true)
	{
		cout << "none" << endl;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
/*

2>
标题：求最小公倍数 | 时间限制：1秒 | 内存限制：32768K
	正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

	输入描述：
		输入两个正整数A和B。
	输出描述：
		输出A和B的最小公倍数。
*/
/////////////////////////////////////////////////////////////////////////////////////////

void ED02()
{
	size_t A = 0;
	size_t B = 0;
	cin >> A >> B;

	int max = A > B ? A : B;
	for (size_t i = max; i <= (A*B); i++)
	{
		if ((i%A == 0) && (i%B == 0))
		{
			cout << i << endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	ED01();
	ED02();
	return 0;
}