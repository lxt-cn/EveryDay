#include <iostream>
#include <string>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/*

两个编程题：
	1>、统计回文
	2>、连续最大和

*/

////////////////////////////////////////////////////////////////////////////////

/*
1>、
标题：统计回文 | 时间限制：1秒 | 内存限制：32768k
	“回文串”是一个正读和反读都一样的字符串，比如 "level" 或者 "noon" 等等就是回文串。花花非常喜欢这种拥有
	对称美的回文串，生日的时候它得到两个礼物分别是字符串A和字符串B.
	如果字符串 B 插入的位置不同就考虑为不一样的办法。

	例如：
		A= "aba", B = "b".这里有 4 种把 B 插入 A 的办法：
		"在 A 的第一个字母之前："baba" 不是回文"
		"在第一个字母 'a' 之后："abba" 是回文"
		"在字母 'b' 之后："abba" 是回文"
		"在第二字母 'a' 之后："abab" 不是回文"
		所以满足条件的答案为 2
	
	输入描述：
		每组输入数据共两行
		第一行为字符串A
		第二行为字符串B
		字符串长度均小于 100 且只包含小写字母
	输出描述：
		输出一个数字，表示把字符串 B 之后构成一个回文串的方法数。


*/
////////////////////////////////////////////////////////////////////////////////

//判断是否回文
bool IsReturnStr(string Str)
{
	bool flag = false;
	int begin = 0;
	int end = Str.length() - 1;
	while (begin < end)
	{
		if (Str[begin] != Str[end])
		{
			return flag;
		}
		++begin;
		--end;
	}
	flag = true;
	return flag;
}

void ED01()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);

	int count = 0;
	for (int i = 0; i <= A.length(); i++)
	{
		//将字符串 B 插入到 字符串 A 的每一个位置，再判断是否是回文
		string cur = A;
		cur.insert(i, B);
		if (IsReturnStr(cur))
		{
			++count;
		}

	}
	cout << count << endl;
}


////////////////////////////////////////////////////////////////////////////////

/*
2>、
标题：连续最大和 | 时间限制：1秒 | 内存限制：32768k
	一个数组有N个元素，求连续子数组的最大和。例如： [-1, 2, 1],和最大的连续子数组为 [2, 1],其和为 3

	输入描述：
		输入为两行。第一行一个整数 n（1 <= n <= 100000）,表示一共有 n 个元素，第二行为 n 个数，
	即每个元素，每个整数都在 32 位 int 范围内。以空格分隔。
	输出描述：
		所有连续子数组中和最大的值。
*/

////////////////////////////////////////////////////////////////////////////////


void ED02()
{
	int n = 0;
	cin >> n;
	vector<int> A(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int result = A[0];
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < A.size(); i++)
	{
		//计算到 A[i] 的子数组的最大和
		sum2 = sum1 >= 0 ? sum1 + A[i] : A[i];
		if (sum2 > result)
		{
			result = sum2;
		}
		if (sum2 < 0)
		{
			sum2 = 0;
		}
		sum1 = sum2;
	}

	cout << result << endl;
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
	//ED01();
	ED02();
	return 0;
}
