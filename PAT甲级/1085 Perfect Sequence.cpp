//����
//
//���ֵľ����������壺���������е�һ������ĳ������Ԫ�ص�λ��
//parameter����
//form�γ�
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int N,p;
long long number[maxn];
int binarysearch(long long num,int left,int right)
{
    //��ȷ���޸ĵĴ���
    if(number[N-1]<(num*p))
        return N-1;

    while(left<right)
    {
        int mid=(left+right)/2;
        //������
        if(number[mid]>(num*p))
        {
            right=mid;
        }
        //������
        else
        {
            left=mid+1;
        }
    }
    //printf("%d  %d\n",left-1,number[left-1]);
    return left-1;
}
int main()
{
    scanf("%d%d",&N,&p);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&number[i]);
    }
    sort(number,number+N);
    //for(int i=0;i<N;i++)
    //{
    //    printf("%d ",number[i]);
    //}
    //printf("\n");
    int maxlength=1;
    for(int i=0;i<N;i++)
    {
        int curlength=binarysearch(number[i],i,N-1)-i+1;
        if(curlength>maxlength)
        {
            maxlength=curlength;
        }
    }
    printf("%d",maxlength);
    return 0;
}
