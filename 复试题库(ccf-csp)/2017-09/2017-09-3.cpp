//unordered_map
//c++�ж���ͬ��string����ʵ���ϲ�ͬ
#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,vector<string>> ans;
void prostring(string &value)
{

}
int main()
{
    cin>>n>>m;
    getchar();
    string input;
    string input_sum;
    for(int i=1;i<=n;i++)
    {
        getline(cin,input);
        input_sum+=input;
    }
    //���������ַ����ո�
    string tar;
    for(int i=0;i<=n;i++)
    {
        if(input_sum[i]!=' ')
            tar+=input_sum[i];
    }
    //cout<<tar<<endl;

    //�ַ�������
    int j;
    //�ڲ�Ӧ���ǵݹ鴦��
    for(int i=1;i<=tar.size()-2;)
    {
        string key;
        vector<string> val;
        string value;
        j=i;
        while(j!=':')
        {
            if(tar[j]!='"')
            {
                key+=input_sum[j];
            }
            j++;
        }

        if(tar[j]=='{')
        {
            if()
        }
        else
        {

        }
        while(j!=',')
        {
            j++;
        }
        i=j+1;
    }

    //��ѯ����
    string stext;
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}
