#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、另类加法
	2>、求路径总数
*/

//////////////////////////////////////////////////////////////////////////

/*
1>
标题：另类加法 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java]
	请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。给定两个int A和B。
请返回A＋B的值


*/

//////////////////////////////////////////////////////////////////////////

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			//对应位的和
			sum = A ^ B;
			//对应位和的进位，既然是进位，就要整体左移一位
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};

void ED01()
{
	UnusualAdd u;

	cout << u.addAB(1, 2) << endl;
	cout << u.addAB(-4, 2) << endl;
	cout << u.addAB(-1, -2) << endl;
}

//////////////////////////////////////////////////////////////////////////

/*

2>
标题：求路径总数 | 时间限制：1秒 | 内存限制：32768K
	请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，
m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求
不能走回头路，即：只能往右和往下走，不能往左和往上走。

*/

/*

思路：
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------

	1. 对于上面的n*m(3*3)的格子，有两种情况
		a. 如果n或者m为1，则只有一行或者一列，从左上角走到右下角的路径数为n + m
			比如： 1 * 1格子，可以先向下走，再向右走，到达右下角；或者先向右走，
			再向下走，到达右下角，共两条，即 1 + 1 = 2.
		b. 如果n,m都大于1，那么走到[n][m]格子的右下角只有两条路径，
			<1>: 从[n - 1][m]格子的右下角向下走，到达
			<2>: 从[n][m - 1]格子的右下角向右走，到达
			所以走到[n][m]格子的右下角的数量为[n-1][m] + [n][m - 1],可以通过递归实现，
			情况a为递归的终止条件。

*/
//////////////////////////////////////////////////////////////////////////

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//b情况，递归
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a情况，终止条件
		return n + m;
	else
		//格子为0时， 路径为0
		return 0;
}

void ED02()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
}

//////////////////////////////////////////////////////////////////////////

int main()
{
	ED01();
	ED02();
	return 0;
}
