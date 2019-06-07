#include <iostream>
#include <vector>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////
/*
��������⣺
	1>��������
	2>������ǿ�ȵȼ�
*/
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
/*
1>��
 ���⣺������ | ʱ�����ƣ�3�� | �ڴ����ƣ�32768K | �������ƣ�[Python, C++, C#, Java]
	����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ������һ����ά����
board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ�
��ҵ����ӡ�

	����������
		[[1,0,1],[1,-1,-1],[1,-1,0]]
	���أ�
		true
*/
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		int row = board.size();
		//���ÿһ�еĺ����Ƿ����row
		int i, j, sum;
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//���ÿһ�еĺ����Ƿ����row
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		//������Խ��ߵĺ����Ƿ����row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//��鸱�Խ��ߵĺ����Ƿ����row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;
		return false;
	}
};
void ED01()
{
	Board b;
	vector<vector<int>> bd = { {1, 0, 1},{1, -1, -1},{1, -1, 0} };
	cout << b.checkWon(bd) << endl;;
}

/////////////////////////////////////////////////////////////////////////

/*
2>��
���⣺����ǿ�ȵȼ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
	һ�����볤��:
	5��: С�ڵ���4 ���ַ�		10 ��: 5 ��7 �ַ�		25 ��: ���ڵ���8 ���ַ�
	������ĸ:
	0 ��: û����ĸ		10 ��: ȫ����С����д��ĸ		20 ��: ��Сд�����ĸ
	��������:
	0 ��: û������		10 ��: 1 ������		20 ��: ����1 ������
	�ġ�����:
	0 ��: û�з���		10 ��: 1 ������			25 ��: ����1 ������
	�塢����:
	2 ��: ��ĸ������		3 ��: ��ĸ�����ֺͷ���		5 ��: ��Сд��ĸ�����ֺͷ���
	�������ֱ�׼:
	>= 90: �ǳ���ȫ		>= 80: ��ȫ��Secure��		>= 70: �ǳ�ǿ
	>= 60: ǿ��Strong��		>= 50: һ�㣨Average��		>= 25: ����Weak��
	>= 0: �ǳ���

	��Ӧ���Ϊ��
		VERY_WEAK,			WEAK,			AVERAGE,			STRONG,
		VERY_STRONG,		SECURE,			VERY_SECURE
	���������������ַ��������а�ȫ������
	ע��
		��ĸ��a-z, A-Z		���֣�-9
	���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
		!"#$%&'()*+,-./ (ASCII�룺x21~0x2F)
		:;<=>?@ (ASCII<=><=><=><=><=>�룺x3A~0x40)
		[\]^_` (ASCII�룺x5B~0x60)
		{|}~ (ASCII�룺x7B~0x7E)

	�ӿ�������
		Input Param
		String pPasswordStr: ���룬���ַ�����ʽ��š�
		Return Value
	���ݹ��������İ�ȫ�ȼ���
		public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
		{
			//������ʵ�ֹ���
			return null;
		}

	����������
		����һ��string������
	���������	
		�������ȼ�
	ʾ��1:	
	����
		38$@NoNoNo
	���
		VERY_SECURE
*/

int numChar(string str, int k)
{
	//����ASCII���ж���ĸ��Сд
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			big++;
		else if (str[i] >= 97 && str[i] <= 122)
			small++;
	}
	if ((small + big) == 0)
		return 0;
	else if (small == k || big == k)
		return 10;
	else if (small > 0 && big > 0)
		return 20;
	return 0;
}
int numNumber(string str, int k)
{
	//����ASCII���ж����ָ�������ȥ�ַ���0��֮����0~9֮��ļ�Ϊ����
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 20;
}
int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		//��ȥ��ĸ�����֣�������Ϊ����
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 25;
}
void ED02()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
			sum1 = 5;
		else if (k >= 8)
			sum1 = 25;
		else
			sum1 = 10;
		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
			sum5 = 2;
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	ED01();
	ED02();
	return 0;
}
