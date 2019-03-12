#include<bits/stdc++.h>
using namespace std;
const int maxv=1000;
const int INF=(1<<30)-1;//��ʾ����ͨ

int n,m,s,G[maxv][maxv];//nΪ������,mΪ����,sΪ���
int d[maxv];//��㵽���������̾��� 
bool vis[maxv];
void Dijkstra(int s)//���ͬ����Ҫ��ʼ�� 
{
	d[s]=0;//���Լ��ľ���Ϊ0
	 
	for(int i=0;i<n;i++)//ÿ���㶼��Ҫ��һ�� 
	{
		int min=INF;
		int u=-1;//��¼��̽ڵ㣬������� 
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j]; 
			}
		}
		vis[u]=true;//��¼�Ѿ�����
		if(u==-1)//ͼ�д��ڲ���ͨ 
			return;
		for(int k=0;k<n;k++)
		{
			if(vis[k]==false&&G[u][k]<INF&&d[u]+G[u][k]<d[k])
			{
				d[k]=d[u]+G[u][k];	
			}	
		}	
	 } 
 } 
int main()
{
	int u,v,w;//��������ͼ����ĳ��ñ����� 
	cin>>n>>m>>s;//�������,����,�����
	
	//��ʼ��ͼ 
	fill(G[0],G[0]+maxv*maxv,INF);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u][v]=w;
	 }
	 
	 //Dijkstra 
	fill(d,d+maxv,INF);//�������� 
	fill(vis,vis+maxv,0);//�������� 
	//vis[s]=true;
	 Dijkstra(s);
	//
	 for(int i=0;i<n;i++)
	 {
	 	cout<<d[i]<<" ";
	 }
	return 0;
}
/*
6 8 0
0 1 1
0 3 4
0 4 4 
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3 
*/
