#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 100+5;
map<string,string> dic;
char in[maxn*maxn];

int solve(char *key,char *a)
{//������ַ����ĳ���
    for(int i=0;i<strlen(a);i++)
    {
        char nowKey[maxn],value[maxn];
        int lenKey = strlen(key);
        int k=0;
        for(k=0;k<lenKey;k++)
            nowKey[k] = key[k];
        nowKey[k] = '\0';
        if(lenKey > 0)
        {
            nowKey[lenKey++] = '.';
            nowKey[lenKey] = '\0';
        }
        if(a[i] == '"')//key�ĵ�һ������
        {
            i++;
            while(a[i] != ':')
            {
                nowKey[lenKey++] = a[i++];
            }
            nowKey[lenKey-1] = '\0';
         }
         //i++;//��
         i++;//"���ǣ�
         if(a[i] == '"'){
             ///�õ�value��ֵ������map
             int j=7;
             i++;
             strcpy(value,"STRING ");
             while(a[i] != ',' && a[i] != '}'){
                 value[j++] = a[i++];
             }
             value[j-1] = '\0';
             dic[nowKey] = value;
         }else if(a[i] == '{')
         {
              ///���ȴ洢nowKey��map��
             dic[nowKey] = "OBJECT";
             i += solve(nowKey,a+i+1)+1;
          }
          //i++;//������}
          if(a[i] == '}')
              return i+1;
           //����ǣ����������
    }
}

int main()
{
    string str;
    int n,m;
    cin>>n>>m;
    n = n+1;
    int i=0;
    while(n--)
    {///�����ַ����ڲ���λ�ã�����λ�ö����Բ���һ�������ո�ʹ�� JSON �ĳ��ָ������ۣ�
    ///Ҳ������һЩ�ط����У�����Ӱ������ʾ���������ݡ�
    ///Ϊ�˴��������Ŀո�ͻ��У��ҽ��������ݴ洢��һ��һά��char������
        getline(cin,str);
        ///��������ַ����Ƚ��д����洢���ַ�������
        for(int k=0;k<str.length();k++)
        {
            if(str[k]=='\\')
                in[i++] = str[++k];
            else if(str[k] == ' ' || str[k] == '\n')
                continue;
            else{
                in[i++] = str[k];
            }
         }
    }
    in[i] = '\0';
    solve("",in+1);//�����һ��Ƕ��

    for(int j=0;j<m;j++)
    {
        string str2;
        getline(cin,str2);
        map<string,string>::iterator iter = dic.find(str2);
        if(iter != dic.end())
        {//�ҵ���
            cout<<dic[str2]<<endl;
        }else{
            cout<<"NOTEXIST"<<endl;
        }
    }
    //printf("%s\n",in);
    return 0;
}
