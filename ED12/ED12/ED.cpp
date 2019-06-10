#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、二进制插入
	2>、查找组成一个偶数最接近的两个素数
*/
//////////////////////////////////////////////////////////////////////////////

/*
1>
标题：二进制插入 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java]
	有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,
其中二进制的位数从低位数到高位且以0开始。
	给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，
保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
*/

//初解
class BinInsert01 {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		//1024 19 2 6
		//1、使 m 的 i 到 j 位wei
		int tmp = 0x7fffffff;	// 0111 1111 1111 1111 1111 1111 1111 1111
		//tmp = tmp >> (32 - i);
		//tmp = tmp << j;
		m = m & (tmp >> (31 - (i - j + 1)));	
								// 0000 0000 0000 0000 0000 0000 0001 0011
		m = m << j;				// 0000 0000 0000 0000 0000 0000 0100 1100

		n = n & ((tmp >> (31 - j)) | (tmp << (i - 1)));
								// 0000 0000 0000 0000 0000 0000 0000 0011
		 						// 1111 1111 1111 1111 1111 1111 1000 0000
								// 1111 1111 1111 1111 1111 1111 1000 0011
								// 0000 0000 0000 0000 0000 0100 0000 0000
		n = n | m;
		return n;
	}
};

//优化代码
/*
思路：
	m:1024：100000000 00 n:19 ： 10011 
	要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然后再进行或运算（|）即可。
		m: 10000000000
		n: 00001001100
		   10001001100
*/
class BinInsert02 {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};

void ED01()
{
	BinInsert01 b1;
	BinInsert02 b2;
	int ret1 = b1.binInsert(1024, 19, 2, 6);
	int ret2 = b2.binInsert(1024, 19, 2, 6);
	cout << ret1 << endl;
	cout << ret2 << endl;
}


//////////////////////////////////////////////////////////////////////////////

/*

2>
标题：查找组成一个偶数最接近的两个素数 | 时间限制：1秒 | 内存限制：32768K
	任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对

	输入描述：
		输入一个偶数
	输出描述：
		输出两个素数

*/



bool IsPri(int x)
{
	for (int i =2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

void ED02()
{
	int n = 0;
	while (cin >> n)
	{
		if ((n % 2 == 0) && (n > 2))
		{
			int a = 0;
			int b = 0;
			int ret1 = 0;
			int ret2 = 0;
			int min = n;
			for (a = 1; a < n; a += 2)
			{
				for (b = 1; b < n; b += 2)
				{
					if (a + b == n)
					{
						if ((IsPri(a) && IsPri(b)) && (a <= b))
						{
							int sub = b - a;
							if (min > sub)
							{
								min = sub;
								ret1 = a;
								ret2 = b;
							}
						}
					}
				}
			}
			cout << ret1 << endl;
			cout << ret2 << endl;
		}
	}
}


int main()
{
	ED01();
	ED02();
	return 0;
}