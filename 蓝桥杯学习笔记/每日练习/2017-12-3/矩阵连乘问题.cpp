#include<stdio.h>
#include<stdlib.h>
#define size 100
void MatrixChain(int p[],int n1,int m[size][size],s[size][size])//n1��ʾ������ 
{
	int i,j;int r;
	for(i=0;i<n1;i++)m[i][i]=0;
	for(r=1;r<n1;r++)
	{
		for(i=0;i<=n1-1-r;i++)
		{
			j=i+r;
		}
	}
	
}
void printm(int m[size][size],int n1)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n1;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
}
int main()
{
	int i,n,n1;
	int p[size];
	int m[size][size],s[size][size];
	printf("�������˾������:\n");
	scanf("%d",&n1);
	n=n1+1;
	printf("�������˾���ı�:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	MatrixChain();
	printm(m,n1);
	return 0;
}
