//������
//���˼��
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int pos[maxn];
int main()
{
    //ans��ʾ�ܽ�������
    int n,ans=0;
    scanf("%d",&n);
    //left��ų�0���ⲻ�ٱ�λ�ϵ����ĸ���
    int left=n-1,num;
    //����
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        //num��λ��Ϊi
        pos[num]=i;
        //�����0�������ڱ�λ�ϵ���
        if(num==i&&num!=0)
        {
            left--;
        }
    }
    //k��ų�0�����в��ڱ�λ�ϵ���С����
    int k=1;
    while(left>0)
    {
        //0�ڱ�λ��
        //Ѱ��һ����ǰ���ڱ�λ�ϵ�����0����
        if(pos[0]==0)
        {
            while(k<n)
            {
                //�ҵ�һ����ǰ���ڱ�λ�ϵ���k
                if(pos[k]!=k)
                {
                    swap(pos[0],pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        //0���ڱ�λ
        //
        while(pos[0]!=0)
        {
            swap(pos[0],pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
