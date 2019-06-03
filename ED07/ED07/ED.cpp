#include <iostream>
#include <stack>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、Fibonacci数列
	2>、合法括号序列判断
*/
//////////////////////////////////////////////////////////////////////

/*

1>、
标题：Fibonacci数列 | 时间限制：1秒 | 内存限制：32768K
	Fibonacci数列是这样定义的：
	F[0] = 0	F[1] = 1
	for each i ≥ 2: 
		F[i] = F[i-1] + F[i-2]
	因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其
变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。

	输入描述：
		输入为一个正整数N(1 ≤ N ≤ 1,000,000)
	输出描述：
		输出一个最小的步数变为Fibonacci数"
*/


//////////////////////////////////////////////////////////////////////

void ED01()
{
	int N;
	cin >> N;

	int a = 0;
	int b = 1;
	int c = 0;
	while (1)
	{
		c = a + b;
		a = b;
		b = c;

		if (c >= N)
		{
			break;
		}
	}
	int min = 0;
	min = c - N;
	int tmp = N - a;
	if (min > tmp)
	{
		min = tmp;
	}
	cout << min << endl;
}

//////////////////////////////////////////////////////////////////////

/*

2>、
标题：合法括号序列判断 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java]
	对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

*/

//////////////////////////////////////////////////////////////////////


class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		//(()())
		//()a()()
		//()(()()
		//((()))
		//())(()
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
				if (sc.empty() || sc.top() != '(')
					return false;
				else
					sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};

void ED02()
{
	string A;
	Parenthesis s;
	getline(cin, A);
	bool ret = s.chkParenthesis(A, A.length());
	if (ret)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "flase";
	}
}
//////////////////////////////////////////////////////////////////////

int main()
{
//	ED01();
	ED02();
	return 0;

}