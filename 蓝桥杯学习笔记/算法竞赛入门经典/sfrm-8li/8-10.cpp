/*
	uva714 
	���⣺��˳�����N����������N�����ֳ�������M�Σ�ʹ����M��ÿ�εĺ��е����ֵ��С��
	�����Сֵ��1<=N<=100000,1<=M<=N,ÿ������1��10000֮�䣩������ж��ֿ��ܵĻ���������ǰ����л��֡�

˼·��

1�����ں������е����Ե���������˿����ö���ö�ٵİ취ȥʵ����������POJ3258�зǳ����Ƶĵط��������ﲻ��Ҫ����

2�������ʱ����Ҫ�õ�̰�ĵ�˼�룬�Ⱦ�����ǰ���֡�

3����ŵ�˼·���Ƕ���ö�����������������ֵ֮��Ȼ����������ֵͨ���Ӻ���ǰ�ķ�ʽ���ֳɶΣ�
���ʣ��ɻ��ֶ���i+1��ֵ��ȣ�������ǰ������ʣ��Ķ���ǰ���֣�����ʵ�ֿ�����һ���������use��ʾ�Ƿ񻮷֡�

5��ע��high_bound���ܳ�int��������Ҫlong long ���档
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const int N=500+5;

LL pos[N];
int vis[N];
LL num,m,group;//num���鳤��;m:�����е������,���ֲ����½�;group:���ֵ����� 

bool is(int x)
{
	int k=1;//��ʼһ������ 
	LL sum=0;
	for(int i=num-1;i>=0;i++)//Ϊ��Ȼǰ��Ļ���С 
	{
		if(sum+pos[i]<=x)
			sum+=pos[i];
		else
		{
			k++;
			sum=pos[i]; 
		}
		if(k>group)
			return false;
	}
	return true;
}

void out()//��� 
{
	
}
int main()
{
	int Case;
	cin>>Case;
	while(Case--)
	{
		LL sum=0;
		m=0;
		cin>>num>>group;
		for(int i=0;i<num;i++)
		{
			cin>>pos[i];
			if(pos[i]>m)
				m=pos[i];
			sum+=pos[i];
		}
		int mid;
		while(m < sum)//�����Ͻ磬�½� 
		{
			mid=(sum+m)/2;
			if(is(mid))
				sum=mid;
			else
				m=mid+1;
		}
		out();
	}
	return 0;
}
