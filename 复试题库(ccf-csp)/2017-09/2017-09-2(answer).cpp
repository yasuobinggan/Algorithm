//ģ���¼�����ģ��ʱ��
//bool�������ȼ��������
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int key;//Կ�ױ��
    int time;//ʱ��
    int flag;//��or��
    friend bool operator<(Node a,Node b)//��������ȼ��Ӹߵ���
    {
        if(a.time!=b.time)
            return a.time>b.time;
        else if(a.flag!=b.flag)//�Ȼ���ȡ
            return a.flag>b.flag;
        else//Կ�׺�С������
            return a.key>b.key;
    }
};
priority_queue<Node> q;
const int maxn=1005;
int main()
{
    int N,K,w,s,c;
    cin>>N>>K;
    int box[maxn];
    //��ʼ��
    for(int i=1;i<N+1;i++)
        box[i]=i;
    //
    Node event1;
    Node event2;
    //����ѹ�����
    for(int i=0;i<K;i++)
    {
        cin>>w>>s>>c;
        //��Կ��
        event1.key=w;
        event1.time=s;
        event1.flag=1;
        q.push(event1);
        //�Ż�Կ��
        event2.key=w;
        event2.time=s+c;
        event2.flag=-1;
        q.push(event2);
    }
    //ģ���¼�
    Node temp;
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        //ģ����Կ��
        if(temp.flag==1)
        {
            int j=1;
            while(box[j]!=temp.key)
                j++;
            box[j]=0;
        }
        //ģ���Կ��
        else
        {
            int j=1;
            while(box[j]!=0)
                j++;
            box[j]=temp.key;
        }
    }
    //���
    for(int i=1;i<=N;i++)
        cout<<box[i]<<" ";
    return 0;
}
