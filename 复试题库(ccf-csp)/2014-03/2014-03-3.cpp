//ģ��
//�ָ��ַ���(�����ַ����еĿո�)
#include<bits/stdc++.h>
using namespace std;
const int maxn=26;
const int INF=(1<<30)-1;
string input;
int N;
struct Node{
    bool flag;
    bool par;//����
};
//�����־
Node visited_in[maxn];
//�����־(һ�������ַ���һ�������־(����Ϊ����ֵ))
struct _Node{
    bool flag;
    string par;
};
//�洢�������Ĳ���ֵ
_Node visited_out[maxn];
void init_visited_out()
{
    for(int i=0;i<maxn;i++)
    {
        visited_out[i].flag=false;
    }

}
int main()
{
    cin>>input;
    cin>>N;

    //Ԥ����
    memset(visited_in,false,sizeof(visited_in));
    for(int i=0;i<input.size();i++)
    {
        if(input[i]!=':')
        {
            visited_in[input[i]-'a'].flag=true;//����ĸѡ��
            if(input[i+1]==':')
            {
                visited_in[input[i]-'a'].par=true;//�в���
            }
        }
        else
            continue;
    }

    getchar();
    //ģ��
    string sten;//����
    vector<string> curans;
    for(int i=1;i<=N;i++)
    {
        init_visited_out();
        getline(cin,sten);
        //�ո���
        string cur;
        int pos=0;//��¼��һ���ո����һ��λ��
        ///����Ĵ���
        for(int j=0;j<sten.size();j++)
        {
            if(sten[j]!=' ')
            {
                cur+=sten[j];
                curans.push_back(cur);
            }
            else
                cur="";
        }

        //��ÿ��ѡ��ƥ��
        for(int k=1;k<curans.size();k++)
        {
            if(curans[k][0]=='-')
            {
                if(visited_in[curans[k][1]-'a'].flag==true)
                {
                    visited_out[curans[k][1]-'a'].flag=true;
                    if(visited_in[curans[k][1]-'a'].par==true)
                    {
                        visited_out[k].par=curans[k+1].substr(1);
                    }
                }
            }
            else
                break;
        }

        //���
        cout<<"Case "<<i<<":";
        for(int k=0;k<maxn;k++)
        {
            if(visited_out[k].flag==true)
            {
                char c='a'+k;
                cout<<" -"<<c;
                if(visited_in[k].par==true)
                {
                    cout<<" "<<visited_out[k].par;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
albw:x
4
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
*/
