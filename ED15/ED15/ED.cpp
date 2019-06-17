#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

/*

两个编程题：
	1>、查找输入整数二进制中1的个数
	2>、手套

*/

////////////////////////////////////////////////////////////////////////////////

/*
1>
标题：查找输入整数二进制中1的个数 | 时间限制：1秒 | 内存限制：32768K

	请实现如下接口

	public static	int	findNumberOf1(int num)
	{
		//请实现
		return 0;
	}
	
	譬如：输入5 ，5的二进制为101，输出2

	输入描述：
		输入一个整数
	输出描述：
		计算整数二进制中1的个数
*/

int findNumberOf1(int num)
{
	int count = 0;
	if (num < 0)
	{
		count = 1;
		num = num & 0x7fffffff;
	}
	while (num)
	{
		if ((num & 0x01) == 1)
		{
			count++;
		}
		num = num >> 1;
	}
	return count;
}

void ED01()
{
	int num = 0;
	while (cin >> num)
	{
		int ret = findNumberOf1(num);
		cout << ret << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
/*
2>
标题：手套 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java]
	在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分
辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他
至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
	给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手
手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

	测试样例：
		4,[0,7,1,6],[1,5,0,6]
	返回：
		10(解释：可以左手手套取2只，右手手套取8只)

*/

//初解
class Gloves1 {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int LCount = 0;
		int RCount = 0;
		vector<int> LCur;
		vector<int> RCur;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0)
			{
				RCount += right[i];
			}
			if (right[i] == 0)
			{
				LCount += left[i];
			}
			if (right[i] && left[i])
			{
				LCur.push_back(left[i]);
				RCur.push_back(right[i]);
				count++;
			}
		}
		int Lmin = 13;
		int Rmin = 13;
		int LNum = 0;
		int RNum = 0;
		for (int i = 0; i < count; i++)
		{
			if (Lmin > LCur[i])
			{
				Lmin = LCur[i];
			}
			if (Rmin > RCur[i])
			{
				Rmin = RCur[i];
			}
			LNum += LCur[i];
			RNum += RCur[i];
		}
		if (LNum < RNum)
		{
			RCount++;
			LCount = LCount + LNum - Lmin + 1;
		}
		else
		{
			LCount++;
			RCount = RCount + RNum - Rmin + 1;
		}
		return RCount + LCount;
	}
};

void ED02_01()
{
	Gloves1 g1;
	vector<int>left = { 1,7,1,6 };
	vector<int>right = { 1,5,0,6 };
	cout << g1.findMinimum(4, left, right) << endl;
}

//优化，易读版
class Gloves2
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//遍历每一种颜色的左右手套序列
		for (int i = 0; i < n; i++) {
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//对于左右手都有的颜色手套，执行累加-最小值+1
			//找到最小值和总数
			else {
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		//结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

void ED02_02()
{
	Gloves1 g2;
	vector<int>left = { 1,7,1,6 };
	vector<int>right = { 1,5,0,6 };
	cout << g2.findMinimum(4, left, right) << endl;
}
////////////////////////////////////////////////////////////////////////////////
int main()
{
	//ED01();
	ED02_01();
	ED02_02();
	return 0;
}