/*
	���仯���� 
*/ 
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
#define MAXN 41
int pile[4][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int n,top[4];//top���ÿ���ѵĳ�ջλ�� 
int dfs(int count,bool hash[])
{
	if(dp[top[0]][top[1]][top[2]][top[3]]!=-1)
		return dp[top[0]][top[1]][top[2]][top[3]];
		
	if(count==5)
		return dp[top[0]][top[1]][top[2]][top[3]]=0;
	
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(top[i]==n)//������Ѿ�ȡ���� 
			continue;
		int color=pile[i][top[i]];
		++top[i];
		if(hash[color])//��ɫƥ�� 
		{
			//
			hash[color]=false;
			ans=max(ans,dfs(count-1,hash)+1);
			hash[color]=true;
		}
		else//��ɫ��ƥ�� 
		{
			//
			hash[color]=true;
			ans=max(ans,dfs(count+1,hash));
			hash[color]=false;
		}
		--top[i];
	}
	
	return dp[top[0]][top[1]][top[2]][top[3]]=ans;
 } 
int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<4;j++)
				cin>>pile[i][j];
		}
		
		bool hash[25];//��ɫ�ı��λ 
		memset(dp,-1,sizeof(dp));
		memset(hash,false,sizeof(hash));
		top[0]=top[1]=top[2]=top[3]=0;
		cout<<dfs(0,hash);
	}
	return 0;
 } 
