#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])//n=6
{
	int i,j;
	
	if(k==N){ 
		b[M] = 0;
		if(m==0) printf("%s\n",b);
		return;
	}
	
	for(i=0; i<=a[k]; i++){
		for(j=0; j<i; j++) b[M-m+j] = k+'A';
		f(a,k+1,m-i,b);  //���λ��
	}
}
int main()
{	
	int  a[N] = {4,2,2,1,1,3};//6
	char b[BUF];//1024
	f(a,0,M,b);
	return 0;
}
//�ݹ麯���Ե����Ϸ��� 