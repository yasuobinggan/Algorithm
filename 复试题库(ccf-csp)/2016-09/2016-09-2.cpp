//̰��
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int G[21][6];
int user[maxn];
//len������䳤��,num��䳤��
//cnt���ڼ������
bool judge_put1(int num)
{
    for(int i=1;i<=20;i++)
    {
        int st=1;
        int ed=5;
        while(G[i][st]!=0)
            st++;
        //if����ע��()
        if(st>5)
            continue;
        //�����������
        int len=ed-st+1;
        int cnt=0;
        int res=1;

        if(len>=num)
        {
            //Ԥ����
            res+=(i-1)*5;
            res+=st-1;
            //������
                //cout<<"������"<<endl;
            while(cnt<num)
            {
                cout<<res<<" ";
                res++;
                cnt++;
            }
            cout<<endl;
            //���
            for(int j=st;j<=st+num-1;j++)
                G[i][j]=1;
            return true;
        }
    }
    return false;
}
void put2(int num)
{
    int cnt=0;
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(G[i][j]==0)
            {
                //������
                cout<<(i-1)*5+j<<" ";
                G[i][j]=1;
                cnt++;
                if(cnt==num)
                {
                    cout<<endl;
                    return;
                }

            }
        }
    }

}
void test_out()
{
    cout<<"�����ͼ"<<endl;
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"***************************"<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>user[i];
    }
    memset(G,0,sizeof(G));
    for(int w=1;w<=n;w++)
    {
        if(!judge_put1(user[w]))
        {
            put2(user[w]);
        }

    }
    return 0;
}
/*
4
2 5 4 2
*/
