#include<iostream>
#include<string>
#include<set>
#include<sstream> 
using namespace std;
set<string> dict;//string���� 
int main()
{
	string s,buf;
	int i;
	while(cin>>s)
	{
		for(i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' '; 
		}
		stringstream ss(s);//��װ����
		while(ss>>buf)
			dict.insert(buf);//����һ���� 
	}
	
	for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
		cout<<*it<<"\n"; 
	return 0;
}
