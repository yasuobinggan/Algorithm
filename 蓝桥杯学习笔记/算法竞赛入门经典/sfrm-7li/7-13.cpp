/*
	�����ݼ��� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn=1000+5;
int maxd,n,a[maxn];

bool dfs(int d,int num,int cur)//num:���еĳ���,cur:��ǰ�� 
{
	if(d==maxd)
	{
		if(n==cur)
			return true;
		return false;
	}
	
	int m=0;
	for(int i=0;i<num;i++)//��ȡ��ǰ���������� 
		m=max(m,a[i]);
		
	if(m*(1<<(max-d)<n))//��֦�����ݣ�//if�������� 
		return false;
		
	for(int i=num-1;i>=0;i--)
	{
		a[num]=cur+a[i];//�˷�
		num++; 
		if(dfs(d+1,num,cur+a[i]))
			return true;
			
		a[num-1]=cur-a[i];//����
		if(dfs(d+1,num,cur-a[i]))
			return true;
		
		num--; 
	}
	return false;	 
}

int main()
{
	while(cin>>n&&n)
	{
		for(maxd=0;;maxd++)
		{
			a[0]=1;
			if(dfs(0,1,1))
				break;
		}
		cout<<maxd<<endl;
	}
	return 0;
}

