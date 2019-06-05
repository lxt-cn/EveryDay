#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////
/*

��������⣺
	1>�������ǹ�
	2>������ת��

*/
///////////////////////////////////////////////////////////////////////
/*

1>��
���⣺�����ǹ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768k
	A,B,C������ʱ�����ѣ�ÿ�������ﶼ��һЩ�ǹ������ǲ�֪������ÿ�������Ͼ����ɶ����ǹ���
��������ֱ��������Ϣ��A-B��B-C��A+B��B+C�����ĸ���ֵ��ÿ����ĸ����ÿ������ӵ�е��ǹ�����
������Ҫͨ�����ĸ���ֵ�����ÿ���������ɶ��ٸ��ǹ�����A��B��C��
	���ﱣ֤���ֻ��һ������ A��B��C������������������

	����������
		����Ϊһ�У�һ�� 4 ���������ֱ�ΪA-B��B-C��A+B��B+C���ÿո��������Χ���� -30 �� 30֮�䣨�����䣩
	���������
		���Ϊһ�У�����������������A��B��C����˳�����A��B��C���ÿո��������ĩ�޿ո�
	�������������������A��B��C�������No��
		

*/

//ֱ����⣬��Ԫһ�η���
void ED01()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;

	if (B1 != B2)
		cout << "No" << endl;
	else
		cout << A << " " << B1 << " " << C << endl;
}

//////////////////////////////////////////////////////////////////////
/*

2>��
���⣺����ת�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768k
	����һ��ʮ������ M ���Լ���Ҫת���Ľ����� N����ʮ������ M ת��Ϊ N������

	����������
		����Ϊһ�У� M ��32λ��������N��2 <= N <= 16��,�Կո����
	���������
		Ϊÿ������ʵ�����ת���������ÿ�����ռһ�У�������� 9 �����Ӧ�����ֹ���ο� 16 ����
	�����磬10��A��ʾ���ȵȣ�

*/

//////////////////////////////////////////////////////////////////////

void ED02()
{
	int M = 0;
	int N = 0;
	cin >> M;
	while (cin >> N)
	{
		if (N >= 2 && N <= 16)
		{
			break;
		}
	}

	string str = "0123456789ABCDEF";
	string ret;
	bool flag = false;
	if (M < 0)
	{
		M = 0 - M;
		flag = true;
	}

	while (M)
	{
		ret += str[M%N];
		M /= N;
	}
	if (flag)
	{
		ret += '-';
	}
	reverse(ret.begin(), ret.end());

	cout << ret << endl;
}

int main()
{
	ED01();
	ED02();
	return 0;
}