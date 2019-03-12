/*
	����uva442
		�����ܾ��� 
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
//��Ȩֵ�������� 
#define maxn 10000+5
int in_order[maxn],post_order[maxn];
int lch[maxn],rch[maxn];//��������ţ����������  
int n;
bool read_list(int *a)
{
	/*
	char buf[maxn];
	if(!cin.getline(buf,maxn))
		return false;
	int i;
	for(i=0;buf[i]!=EOF;i++)
	{
		a[i]=buf[i];
		cout<<a[i]<<endl;
	}
	*/	
	string line;
	if(!getline(cin,line))
		return false;
	stringstream ss(line);
	n=0;int x;
	while(ss>>x)
		a[n++]=x;
	return n>0;
}
int build(int L1,int R1,int L2,int R2)
{
	//�������� 
	if(L1>R1)
		return 0;//����
	//�����ڵ� 
	int root=post_order[R2];
	int p=L1;
	//��õ�ǰ�ڵ�����������Ŀ
	while(in_order[p]!=root)
		p++;
	int cnt=p-L1;
	//������������������ 
	lch[root]=build(L1,p-1,L2,L2+cnt-1);
	rch[root]=build(p+1,R1,L2+cnt,R2-1);
	return root; 
}
int best,best_sum;//best��С�㣬best_sum��С�� 
//���������ǰ����д���ˣ�ֵ�÷�˼ 
void dfs(int root,int sum)//������������� 
{
	sum+=root;
	if(!lch[root]&&!rch[root])//Ҷ�ӽڵ�
	{
		if(sum<best_sum||(sum==best_sum&&root<best))
		{
			best=root;
			best_sum=sum;
		}
	} 
	if(lch[root])dfs(lch[root],sum);
	if(rch[root])dfs(rch[root],sum);
}
int main()
{
	
	while(read_list(in_order))
	{
		read_list(post_order);
		build(0,n-1,0,n-1);
		best_sum=100000000;
		dfs(post_order[n-1],0);
		cout<<"��С����С��Ȩֵ:"<<best<<"\t��С��Ȩֵ:"<<best_sum<<endl;
	}
	return 0;
}
