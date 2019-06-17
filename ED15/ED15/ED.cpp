#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

/*

��������⣺
	1>����������������������1�ĸ���
	2>������

*/

////////////////////////////////////////////////////////////////////////////////

/*
1>
���⣺��������������������1�ĸ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K

	��ʵ�����½ӿ�

	public static	int	findNumberOf1(int num)
	{
		//��ʵ��
		return 0;
	}
	
	Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2

	����������
		����һ������
	���������
		����������������1�ĸ���
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
���⣺���� | ʱ�����ƣ�3�� | �ڴ����ƣ�32768K | �������ƣ�[Python, C++, C#, Java]
	�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ܷ�
��������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ���
����Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
	������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ������
���׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

	����������
		4,[0,7,1,6],[1,5,0,6]
	���أ�
		10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)

*/

//����
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

//�Ż����׶���
class Gloves2
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//����ÿһ����ɫ��������������
		for (int i = 0; i < n; i++) {
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//���������ֶ��е���ɫ���ף�ִ���ۼ�-��Сֵ+1
			//�ҵ���Сֵ������
			else {
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		//���Ϊ�����Ҷ����������������еĽ��+��0���ڵ�������+����ټ�һ�϶����ܱ�֤��
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