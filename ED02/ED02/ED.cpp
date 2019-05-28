#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*

��������⣺
	1>������������
	2>�������ַ���

*/
//////////////////////////////////////////////////////////////////////////

/*
1>��
���⣺���������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768k
	ţţ��������������Ϊһ��������һ�������������У���������������Ƿǵ�����ǵݼ�����ġ�
ţţ��һ������Ϊ n ���������� A ����������һ�������ǰ����� A �ֳ����ɶ����������У�ţţ
��֪�������ٿ��԰���������Ϊ�������������С�
	
	����������
		����ĵ�һ��Ϊһ�������� n (1 <= n <= 10^5)
		�ڶ��а��� n ������ A_i��1 <= A_i <= 10^9��,��ʾ���� A ��ÿ������
	���������
		���һ����������ʾţţ���Խ� A ���ٻ���Ϊ���ٶ�����������

*/
/*
�ǵݼ���a[i] <= a[i+1]
�ݼ���  a[i] > a[i+1]
�ǵ�����a[i] >= a[i+1]
������  a[i] < a[i+1]

���Դ��������������
	һ��1 2 3 ��һ���ǵݼ����У�2 2 1 ��һ���ǵ�������
			3
		2		2	2
	1					1
	�����㲨��Ͳ���������������������������������������
		3		3
			2
	1

*/
void ED01()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		//�ҳ����岨��
		if ((v[i - 1]<v[i] && v[i]>v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
		{
			ret++;
			//�����
			if (i != n - 3)
			{
				i++;
			}
		}
	}
	cout << ret << endl;
}

/////////////////////////////////////////////////////////////////////////////////
/*
2>��
���⣺�����ַ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768k
	��һ�仰�ĵ��ʽ��е��ã���㲻���á�
	���� I like beijing.	�����������Ϊ beijing. like I

	����������
		ÿ������������� 1 ������������I like beijing.
		������������Ȳ����� 100
	���������
		�����������֮����ַ������Կո�ָ���
*/

void ED02()
{
	string s;
	getline(cin, s);

	//��ת��������
	reverse(s.begin(), s.end());

	//��ת����
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		reverse(start, end);
		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	cout << s << endl;
}

/////////////////////////////////////////////////////////////////////////////////
int main()
{
	ED01();
	ED02();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//��Ŀ������
//void ReverseString(string& str, int left, int right)
//{
//	while (left <= right)
//	{
//		int tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void ED02()
//{	
//	string str;
//	getline(cin, str);
//
//	ReverseString(str, 0 , str.size()-1);
//	int left = 0;
//	int right = 0;
//	for (int i = 0; i < str.size() - 1; i++)
//	{
//		if (str[i] == ' ')
//		{
//			right = i - 1;
//			ReverseString(str, left, right);
//			left = i + 1;
//			right = left;
//		}
//		if (i == (str.size() - 2))
//		{
//			right = i + 1;
//			ReverseString(str, left, right);
//		}
//	}
//	cout << str << endl;
//}
















