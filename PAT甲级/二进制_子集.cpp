//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
void print_subset(int n, int s)//s��ʾ���ϵĴ���
{
	for (int i = 0; i<n; i++)
	{
		if ( s & (1 << i) )//(1<<i)����
			printf("%d", i);
		printf("\n");
	}
}
int main()
{
	int n = 4;
	1 << n;
	for (int i = 0; i< (1 << n); i++)
	{
		print_subset(n, i);//i��ʾ���ϵĴ���
	}
	return 0;
}

