#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////////////////////////////////////////////////////

/*
��������⣺
	1>����������
	2>����ʯ��
*/

//////////////////////////////////////////////////////////////////////////////
/*

1>
���⣺�������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	�������������������
		xcopy /s c:\ d:\��
	�����������£�
	����1��������xcopy
	����2���ַ���/s
	����3���ַ���c:\
	����4: �ַ���d:\
	���дһ��������������ʵ�ֽ������и�����������������
	��������
		1.�����ָ���Ϊ�ո�
		2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������
	xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������
	C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
		3.����������
		4.������������֤��������ֲ�����Ҫ�������

	����������
		����һ���ַ����������пո�
	���������
		��������������ֽ��Ĳ�����ÿ����������ռһ��

*/

void ED01_01()
{
	string getstr;
	vector<vector<char>> vec;
	int count = 0;
	while (getline(cin, getstr))
	{
		int begin = 0;
		int end = getstr.length();
		while (begin < end)
		{
			vector<char> cur;
			if (getstr[begin] == '"')
			{
				begin++;
			}
			while (getstr[begin] != ' ' && getstr[begin] != '"' && begin < end)
			{
				cur.push_back(getstr[begin]);
				begin++;
			}
			count++;
			vec.push_back(cur);
			if (getstr[begin] == '"' || getstr[begin] == ' ')
			{
				begin++;
			}
		}
		cout << count << endl;
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < vec[i].size(); j++)
				cout << vec[i][j];
			cout << endl;
		}
	}
}

void ED01_02()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		//���ȼ����������
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			//�����˫���ţ���������ֱ����һ��˫���Ž���
			if (str[i] == '"')
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
		}
		//�Կո����������ո������Ȳ���������1
		cout << count + 1 << endl;
		//��flag��ʾ�Ƿ����˫���ţ�0��ʾ��˫����
		//˫�����еĿո�Ҫ��ӡ����
		//�����ı�flag��ֵ������˫���ſ���ʹflag��ԭ
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			//��˫���ţ�flagͨ������Ϊ0����һ��������˫���ţ�flag��Ϊ1
			if (str[i] == '"')
				flag ^= 1;
			//˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//˫�����еĿո�Ҫ��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//����˫����֮��Ŀո�ͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////
/*

2>
���⣺��ʯ�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
	С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1��
�����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��
ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��

	���磺
		N = 4��M = 24��
		4->6->8->12->18->24
		����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

	����������
		����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
	���������
		���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1

*/

// ���⣺�ݹ�ʵ�֣��ݹ��������OJ�г�ʱ
void getnum(vector<int>& vec, int N)
{
	for (int i = 2; i < N; i++)
	{
		if (N%i == 0)
		{
			vec.push_back(i);
		}
	}
}

int getStep(int N, int M)
{
	vector<int> vec;
	int min = M;
	if (N < M)
	{
		getnum(vec, N);
		for (int i = 0; i < vec.size(); i++)
		{
			int step = 1 + getStep(N + vec[i], M);
			if (step < min && step > 0)
			{
				min = step;
			}
		}
	}
	if (N > M)
	{
		return -M;
	}
	if (N == M)
	{
		return 0;
	}

	if (min == M)
	{
		return -1;
	}
	return min;
}

void ED02_01()
{
	int N, M;
	while (cin >> N >> M)
	{
		if ((N < 4 || N>100000) && (M < N || M>100000))
		{
			break;
		}

		int ret = getStep(N, M);
		cout << ret << endl;
	}
}

// �Ż����ǵݹ�
//����Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}

int Jump(int N, int M)
{
	//����ĵ����stepNum��Ĳ�������ʼNΪ1������N��NΪ1��
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;
	for (int i = N; i < M; i++)
	{
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;
		//0��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue;
		//����������ߵĲ���������divNum��������
		divisorNum(i, divNum);
		for (int j = 0; j < divNum.size(); j++)
		{
			//��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[M] == 0)
		return -1;
	else
		//��ʼ��ʱ�����һ��������Ҫ��1
		return stepNum[M] - 1;
}

void ED02_02()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
}

//////////////////////////////////////////////////////////////////////////////

int main()
{ 
	//ED01_01();
	//ED01_02();
	//ED02_01();
	ED02_02();
	return 0;
}