//ѭ������
//!!!!��Ѵ�
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    queue<int> q;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        q.push(i);
    //ģ����ֹ���
    int no=0,head;
    //
    while(!q.empty())
    {
        head=q.front();
        q.pop();
        no++;
        if(no%k==0||no%10==k)
            continue;
        else
            q.push(head);
    }
    cout<<head;
    return 0;
}
