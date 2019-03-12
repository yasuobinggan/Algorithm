//begin()�ǵ�����
#include<bits/stdc++.h>
using namespace std;
const int maxn=17;
int G[maxn][maxn],g[maxn][maxn],p;
struct Node{
    int x;
    int y;
    Node(int _x,int _y):x(_x),y(_y){}
    Node(){}
};
vector<Node> point;
//��ʼ�����䷽������
void init()
{
    for(int i=4;i>=1;i--)
    {
        for(int j=1;j<=4;j++)
        {
            if(g[i][j]==1)
            {
                int curj=j+p-1;
                point.push_back(Node(i,curj));
            }
        }
    }

}
//�ж��Ƿ��������
bool judge()
{
    int low=point.front().x;
    //it��һ��ָ��
    for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
    {
        //����Ͳ�����һ���ѱ�ռ��||��һ��Ϊ�߽�
        if((it->x==low&&G[low+1][it->y]==1)||it->x==15)
        {
            return false;
        }
        if(it->x!=low)
            break;
    }
    return true;
}
void fall()
{
    init();
    while(judge())
    {
        for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
        {
            it->x++;
            //cout<<"����"<<it->x<<" "<<it->y<<endl;
        }
    }
    //����λ�û�ͼ
    //���������е�ֵ
    for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
    {
        G[it->x][it->y]=1;
    }
}
void out()
{
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //����
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>G[i][j];
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cin>>g[i][j];
        }
    }
    cin>>p;

    //����
    fall();

    //���
    out();
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
0 1 1 1
0 0 0 1
0 0 0 0
3
*/
