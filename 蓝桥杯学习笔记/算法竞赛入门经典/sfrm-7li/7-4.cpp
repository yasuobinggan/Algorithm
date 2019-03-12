/*
	������uva524
		�Ա���lengthȫ�ֱ������ֲ����� 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
#define mlength 16
int cnt[mlength]; 

bool judge(int x,int y)
{
	int i;
	for(i=2;i<x+y;i++)
	{
		if((x+y)%i==0)
			return false;//������������false 
	}
	return true;//����������true 
}
bool judge1(int t,int length)
{
	for(int i=0;i<length;i++)
	{
		if(cnt[i]==t)
			return false;//�������ﷵ��false 
	}
	return true;//���������ﷵ��true 
}
void stamp(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<cnt[i]<<"\t"; 
	}
	cout<<endl;
}
void dfs(int length,int n)//ѭ����ĩβ��Ҫ��� 
{
	int i;
	if(length==n)
	{
		if(judge(cnt[length-1],cnt[0])) 
			stamp(n);
		else
			return;
	}
	else
		for(i=2;i<=n;i++)
		{
			if(judge1(i,length))
			{
				if(judge(cnt[length-1],i))
				{
					cnt[length]=i;
					//length++;
					dfs(length+1,n);		
				} 
			}
		} 
}
int main()
{
	int n,length;
	while(cin>>n)
	{
		cnt[0]=1;
		length=1;
		dfs(length,n);
	}
	return 0;
} 
