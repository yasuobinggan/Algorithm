#include<stdio.h>
#define max 8
int a[max][max];
int main()
{
	int n,i,j;
	int result=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	i=0;j=n-1;
	//�ȸ�ֵ��һ��,������� 
	while(result<=n*n)
	{
		while(a[i][j]==0&&i<n){a[i][j]=result;i++;result++;}//&&�Ƕ�·����� 
		i--;j--;
		while(a[i][j]==0&&j>=0){a[i][j]=result;j--;result++;}
		j++;i--;
		while(a[i][j]==0&&i>=0){a[i][j]=result;i--;result++;}
		i++;j++;
		while(a[i][j]==0&&i<n){a[i][j]=result;j++;result++;}
		j--;i++; 
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");			
	}
	return 0;
}
