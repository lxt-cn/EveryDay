#include <iostream>
#include <vector>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
��������⣺
	1>��С�׵�����֮·
	2>���ҳ��ַ����е�һ��ֻ����һ�ε��ַ�(�����Ѿ�����)
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
1. ���⣺С�׵�����֮· | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
	С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,
ÿ������ķ�����Ϊb1,b2,b3...bn. ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ
����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô�� ������,��һϵ�еĶ�����,С�׵���������ֵΪ����?

	���������� 
		����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ. �ڶ���n������,b1,b2...bn(1��bi��n)
		��ʾÿ������ķ����� 
	��������� 
		����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ 
		
	ʾ��1: 
		����
			3 50 
			50 105 200 
			5 20 
			30 20 15 40 100
		��� 
			110 
			205
*/

int Gac(int x, int y)
{
	if (x > y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	int max = 1;
	for (int i = 2; i <= x; i++)
	{
		if (x%i == 0 && y%i == 0)
		{
			if (max < i)
			{
				max = i;
			}
		}
	}
	return max;
}

void ED01()
{
	int n = 0;
	int a = 0;
	while (cin >> n >> a)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int bi = 0;
			cin >> bi;
			vec.push_back(bi);
		}
		for (int i = 0; i < n; i++)
		{
			if (a >= vec[i])
			{
				a += vec[i];
			}
			else
			{
				a += Gac(a, vec[i]);
			}
		}
		cout << a << endl;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
2. ���⣺�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�(�����Ѿ�����) | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
	�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�

	���������� 
		����һ���ǿ��ַ���
	��������� 
		�����һ��ֻ����һ�ε��ַ���������������-1

	��1: 
		���� 
			asdfasdfo
		��� 
			o
*/
char FirstOne(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int count = 1;
		for (int j = 0; j < str.length(); j++) 
		{
			if (str[i] == str[j] && i != j)
			{
				count++;
			}
			if (count != 1)
			{
				break;
			}
		}
		if (count == 1)
		{
			return str[i];
		}
	}
	return -1;
}

void ED02()
{
	string str;
	while (cin >> str)
	{
		char c = FirstOne(str);
		if (c == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << c << endl;
		}
	}
}

int main()
{
	//ED01();
	ED02();
	return 0;
}