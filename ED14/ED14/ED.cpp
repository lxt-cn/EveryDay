#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
/*
��������⣺
	1>���������ڵ�����ת��
	2>�����˵Ĵ���
*/

//////////////////////////////////////////////////////////////////////////////////////////
/*
1>
���⣺�������ڵ�����ת�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	������������ڣ���������һ��ĵڼ��졣��
	��ϸ������
		����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��

	�ӿ���Ƽ�˵����
		Description : ����ת��
		Input Param : year �������
		Month �����·�
		Day ������
		Output Param :
		Return Value : �ɹ�����0��ʧ�ܷ���-1���磺���ݴ���

		public static int iConverDateToDay(int year, int month, int day)
		{
			//������ʵ�ֹ��ܣ��������������������
			return 0;
		}

		Description :
		Input Param :
		Output Param :
		Return Value : �ɹ�:����outDay��������ĵڼ���;
		ʧ��:����-1

		public static int getOutDay()
		{
			return 0;
		}

		����������
			�������У��ֱ����꣬�£���
		���������
			�ɹ� : ����outDay��������ĵڼ���;
			ʧ��:���� - 1
*/

//����
vector<int> vec{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool IsPre(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

void iConverDateToDay(int year, int month, int day)
{
	int outday = 0;
	if ((IsPre(year)) && month > 2 || (month == 2 && day == 29))
	{
		outday = 1;
	}
	for (int i = 0; i < month - 1; i++)
	{
		outday += vec[i];
	}
	cout << (outday + day) << endl;
}

void ED01_01()
{
	int year = 0;
	int month = 0;
	int day = 0;
	while (cin >> year >> month >> day) 
	{
		iConverDateToDay(year, month, day);
	}
}

//�����
void ED01_02()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
/*

2>
���⣺���˵Ĵ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ�
�ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
	
	���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
	������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���
һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�

	����������
		��һ������һ��������n(n �� 1000)
		�ڶ���Ϊn����������xi(xi �� 1000)
	���������
		������Բ��������˵Ĵ�����

		*/


int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ����
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1��������������
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//���sum����multi,������û�з���Ҫ��������
			break;
		}
		//Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi
		sum -= x[i];
		multi /= x[i];
		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

void ED02()
{
	int n;
	while (cin >> n)
	{
		int *x = new int [n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		//�ӵ�һ��λ�ÿ�ʼ����
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//ED01_01();
	//ED01_02();
	ED02();
	return 0;
}