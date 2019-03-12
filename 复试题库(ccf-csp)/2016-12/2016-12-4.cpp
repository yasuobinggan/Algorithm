#include<bits/stdc++.h>
using namespace std;
const int INF=0x7F7F7F7F;
const int N=1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];
//stΪ��ʼ��,edΪ��β
int solve(int st,int ed)
{
    if(dp[st][ed]==INF)
    {
        for(int i=st;i<ed;i++)//iΪ�ָ��
            dp[st][ed]=min(dp[st][ed],solve(st,i)+solve(i+1,ed)+sum[ed]-sum[st-1]);
    }
    return dp[st][ed];
}

int main()
{
    int n;
    //��ʼ������
    memset(dp,INF,sizeof(dp));
    //��������
    cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        //ǰ׺��
        sum[i]=sum[i-1]+v[i];
        //�߽�
        dp[i][i]=0;
    }
    //DP����(��Ϊ���)
    solve(1,n);
    //������
    cout<<dp[1][n]<<endl;

    return 0;
}
/*
5
1 3 4 2 5
*/
