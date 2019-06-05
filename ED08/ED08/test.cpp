#include <iostream>
#include <string>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
/*
���������⣺
	1>��
	2>��
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
1>
���⣺�������򷽷� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
		1)�����ַ������ֵ����������磺
			"car" < "carriage" < "cats" <
			"doggies < "koala"
		2)�����ַ����ĳ����������磺
			"car" < "cats" < "koala" <
			"doggies" < "carriage"
	������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

	����������
		�����һ��Ϊ�ַ�������n(n �� 100)��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
	���������
		�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
		������ݳ������ж������ֵ����������"lengths",
	������ַ�ʽ���������"both"���������"none"

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
���⣺����С������ | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������

	����������
		��������������A��B��
	���������
		���A��B����С��������
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