//ɾ���ظ������
//bonus����
//coupons���
//times����
//exceed����
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5 + 5;
int coupons[maxn];
int products[maxn];
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	int ans = 0;
	int NC, NP;
	cin >> NC;
	for (int i = 0; i<NC; i++)
	{
		cin >> coupons[i];
	}
	cin >> NP;
	for (int i = 0; i<NP; i++)
	{
		cin >> products[i];
	}
	sort(coupons, coupons + NC, cmp);
	sort(products, products + NP, cmp);
	//two pointers
	//��������
	int p = 0, q = 0;
	while (p<NC&&q<NP)
	{
		if (coupons[p]>0 && products[q]>0)
		{
			ans += (coupons[p] * products[q]);
			p++; q++;

		}
		else
		{
			break;
		}
	}
	//��������
	p = NC - 1, q = NP - 1;
	while (p >= 0 && q >= 0)
	{
		if (coupons[p]<0 && products[q]<0)
		{
			ans += (coupons[p] * products[q]);
			p--; q--;

		}
		else
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
