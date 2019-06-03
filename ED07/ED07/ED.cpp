#include <iostream>
#include <stack>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////
/*
��������⣺
	1>��Fibonacci����
	2>���Ϸ����������ж�
*/
//////////////////////////////////////////////////////////////////////

/*

1>��
���⣺Fibonacci���� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	Fibonacci��������������ģ�
	F[0] = 0	F[1] = 1
	for each i �� 2: 
		F[i] = F[i-1] + F[i-2]
	��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N����������
��Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����

	����������
		����Ϊһ��������N(1 �� N �� 1,000,000)
	���������
		���һ����С�Ĳ�����ΪFibonacci��"
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

2>��
���⣺�Ϸ����������ж� | ʱ�����ƣ�3�� | �ڴ����ƣ�32768K | �������ƣ�[Python, C++, C#, Java]
	����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

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