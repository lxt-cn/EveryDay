#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
��������⣺
	1>���ַ�����ת
	2>�������ִ�����
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

1. ���⣺�ַ�����ת | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
	д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ�����
	
	���磺
		���������� 
			����N���ַ�
		��������� 
			������ַ�����ת����ַ���

	ʾ��1: 
		���� 
			abcd
		��� 
			dcba

*/
void ED01()
{
	string str;
	while (cin >> str)
	{
		int begin = 0;
		int end = str.length() - 1;
		while (begin < end)
		{
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			begin++;
			end--;
		}
		cout << str << endl;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2. ���⣺�����ִ����� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
	���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд

	��ϸ������
		�ӿ�˵��
		ԭ�ͣ�
			int getCommonStrLength(char * pFirstStr, char * pSecondStr);	
			���������
				char * pFirstStr //��һ���ַ���
				char * pSecondStr//�ڶ����ַ���

	���������� 
		���������ַ���
	��������� 
		���һ������

	ʾ��1: 
		���� 
			asdfas
			werasdfaswer 
		��� 
			6
*/
int getCommonStrLength(string str1, string str2)
{
	int max = 0;
	for (size_t i = 0; i < str1.length(); i++)
	{
		for (size_t j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				int count = 0;
				int cur1 = i;
				int cur2 = j;
				while (str1[cur1++] == str2[cur2++])
				{
					count++;
					if (cur1 == str1.length() || cur2 == str2.length())
					{
						break;
					}
				}
				if (max < count)
				{
					max = count;
				}
			}
		}
	}
	return max;
}

void ED02()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int ret = getCommonStrLength(str1, str2);
		cout << ret << endl;
	}
}

int main()
{
	ED01();
	ED02();
	return 0;
}