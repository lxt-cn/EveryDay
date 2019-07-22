#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
两个编程题：
	1>、微信红包
	2>、计算字符串的距离
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
1. 标题：微信红包 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
	春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。
请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。 给定一个红包的金额数组 gifts 及它的大小 n，请
返回所求红包的金额。 若没有金额超过总数的一半，返回 0。 

	测试样例：
		[1,2,3,2,2],5
	返回：
		2

*/

class Gift {
public:
	// 初解
	// 遍历查找记录每个红包出现的次数，一旦出现次数超过一半的数字，直接返回。
	int getValue01(vector<int> gifts, int n) {
		// write code here
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			int ret = gifts[i];
			for (int j = i+1; j < n; j++)
			{
				if (ret == gifts[j])
				{
					count++;
				}
				if (count >= (n / 2))
				{
					return ret;
				}
			}
		}
		return 0;
	}

	// 排序，超过一半数字的金额一定排在中间位置
	int getValue02(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());

		// 统计中间数字出现次数，测试是否满足条件，满足则返回中间数，否则，返回 0
		int mid = gifts[n / 2];
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == mid)
			{
				count++;
			}
		}

		if (count > n / 2)
			return mid;
		else
			return 0;
	}

	// map 统计
	int getValue03(vector<int> gifts, int n) {
		map<int, int> count;

		int mid = gifts.size() / 2;
		for (const auto& e : gifts)
		{
			++count[e];
		}
		for (const auto& e : count)
		{
			if (e.second >= mid)
				return e.first;
		}
		return 0;
	}
};

void ED01()
{
	Gift g;
	vector<int> gifts = { 1,2,3,2,2 };
	cout << g.getValue01(gifts, 5) << endl;
	cout << g.getValue02(gifts, 5) << endl;
	cout << g.getValue03(gifts, 5) << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2. 标题：计算字符串的距离 | 时间限制：1秒 | 内存限制：32768K
	Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。 许可的编辑操作包括将一个字符
替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先 由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

	Ex：
		字符串A: abcdefg
		字符串B: abcdef
		通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两 个字符串的距离。

	要求：
		给定任意两个字符串，写出一个算法计算它们的编辑距离。

	请实现如下接口
		// 功能：计算两个字符串的距离
		// 输入： 字符串A和字符串B
		// 输出：无
		// 返回：如果成功计算出字符串的距离，否则返回-1

	输入描述： 
		输入两个字符串
	输出描述： 
		得到计算结果

	示例1 : 
		输入 
			abcdefg abcdef
		输出 
			1

*/

/*
【解题思路】：
	动态规划解题：
		状态： word1 的前 1，2，3，...，m 个字符转换成 word2 的前 1，2，3，...，n 个字符需要的编辑距离

		F(i,j): word1 的前 i 个字符于 word2 的前 j 个字符的编辑距离
		状态递推：F(i,j) = min{F(i-1,j)+1, F(i,j-1)+1,F(i-1,j-1)=(w1[i] == w2[j]?0:1)} 表示从删除，增加和替换操作中选择一个最小操作数
			F(i-1,j):w1[1,...,i-1]与 w2[1,...,j]的编辑距离，删除 w1[i]的字符
		--> F(i,j-1): w1[1,...,i]于w2[1,...,j-1]的编辑距离，增加一个字符-->F(i,j) F(i-1,j-1): w1[1,...,i-1] 与 w2[1,...,j-1]的编辑距离，
			如果w1[i]与w2[j]相同， 不做任何操作，编辑距离不 变，如果w1[i]与w2[j]不同，替换w1[i]的字符为w2[j]--->F(i,j) 
		初始化： 初始化一定要是确定的值，如果这里 不加入空串，初始值无法确定 
			F(i,0) = i :word与空串的编辑距离，删除操作 
			F(0,i) = i :空串与word的编辑距离，增加操作 
		返回结果：F(m,n)

*/
int calStringDistance(string word1, string word2)
{
	// word 与空串之间的编辑距离为 word 的长度
	if (word1.empty() || word2.empty())
	{
		return max(word1.size(), word2.size());
	}

	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)初始化
	vector<vector<int>> f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i)
	{
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i)
	{
		f[0][i] = i;
	}

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			//  F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) + (w1[i]==w2[j]?0:1) } 
			// 判断 word1 的第 i 个字符是否与 word2 的第 j 个字符相等
			if (word1[i - 1] == word2[j - 1])
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符相等， F(i-1, j-1)编辑距离不变
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符不相等， F(i-1,j-1)编辑距离 +1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];

}

void ED02()
{
	string word1, word2;
	while (cin >> word1 >> word2)
	{
		cout << calStringDistance(word1, word2) << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	ED01();
	ED02();
	return 0;
}