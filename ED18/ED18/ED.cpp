#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////

/*
���������:
	1>��ͳ��ÿ�������ӵ�����
	2>���ַ���ͨ���
*/

////////////////////////////////////////////////////////////////////////////////////////////
/*
1>
���⣺ͳ��ÿ�������ӵ����� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ�������
�Ӷ���������ÿ���µ���������Ϊ���٣�

	ͳ�Ƴ�����������
	param monthCount �ڼ�����
	return ��������

	public static int getTotalCount(int monthCount)
	{
		return 0;
	}

	����������
		����int�ͱ�ʾmonth
	���������
		�����������int��
*/
int fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int getTatalCount(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return getTatalCount(n - 1) + fib(n - 2);
	}
}

void ED01()
{
	int n = 0;
	while (cin >> n)
	{
		cout << getTatalCount(n) << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
/*
2>
���⣺�ַ���ͨ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ��
��λʵ���ַ���ͨ������㷨��

	Ҫ��
		ʵ������2��ͨ�����
			*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
			����ƥ��1���ַ�
	���룺
		ͨ������ʽ��
			һ���ַ�����	�����
		����ƥ��Ľ������ȷ���true���������false
	
	����������
		������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
	���������
		����ƥ��Ľ������ȷ���true���������false
	
	ʾ��1:
		����
			te?t*.*
			txt12.xls
		���
			false
*/
bool match(const char* pattern, const char *str)
{
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
		return match(pattern + 1, str + 1);
	}
	return false;
}
void ED02()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//ED01();
	ED02();
	return 0;
}