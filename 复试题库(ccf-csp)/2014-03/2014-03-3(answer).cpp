#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define MAX 207
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    getchar();//����getchar,getline���ٶ���һ���ַ���
    map<string,string> lsmap;//���������
    //����
    for(int i = 0 ;i < n; i++)
    {
        string ls;
        getline(cin, ls);
        int ip = 0;
        while(ip < ls.length() && ls[ip]!=' ')
            ip++;
    	ip++;//���õ�������ʼλ��
    	lsmap.clear();
        while(ip < ls.length())
        {
            string op = "", ag = "";
            //��ȡ����
            while(ip < ls.length() && ls[ip] != ' ')
            {
                op += ls[ip];
                ip++;
            }
            ip++;
            //�жϲ����Ƿ��ڱ�׼��
            if(op[0] != '-' || op.length() != 2 || str.find(op[1]) == string::npos)
                break;
            //�жϲ����Ƿ������ֲ���
            if(str.find(op.substr(1,1)+':')!= string::npos)
            {
                if(ip >= ls.length()) break;
                while(ip < ls.length() && ls[ip] != ' ')
                {
                    ag += ls[ip];
                    ip++;
                }
                ip++;
            }
            lsmap[op] = ag;
        }
        //���
        printf("Case %d:",i+1);
    	for(map<string,string>::iterator iter = lsmap.begin(); iter != lsmap.end(); iter++)
    	{

    		cout << " " << iter->first;
			if(iter->second != "")
                cout << " " << iter->second;
    	}
    	cout << endl;
    }
    return 0;
}
