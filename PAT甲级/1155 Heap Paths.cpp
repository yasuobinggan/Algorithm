//flag 0���Ƕ� 1С���� 2�󶥶�
#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int N,v[MAXN];
int judge(int endindex)
{
    int flag;
    int i=endindex;
    //С����
    if(v[endindex]>v[endindex/2])
        flag=1;
    //�󶥶�
    if(v[endindex]<=v[endindex/2])
        flag=2;
    while(i>=1)
    {
        //С����
        if(v[i]>v[i/2]&&flag==1)
        {
            continue;
        }
        //�󶥶�
        if(v[i]<=v[i/2]&&flag==2)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return flag;
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>v[i];
    }
    bool initflag=judge(N);
    cout<<initflag<<endl;
    bool flag;
    for(int i=N-1;i>(N/2);i--)
    {
        flag=judge(i);
        if(flag!=initflag)
        {
            cout<<"Not Heap";
            return 0;
        }
        else
        {
            continue;
        }
    }
    if(flag==1)
    {
        cout<<"Min Heap";
    }
    else if(flag==2)
    {
        cout<<"Max Heap";
    }
    else
        cout<<"Not Heap";
    return 0;
}
