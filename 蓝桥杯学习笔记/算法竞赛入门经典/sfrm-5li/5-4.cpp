#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<string> words;
map<string,int> cnt;
//Ϊʲô���λ����const�������β�
//�淶���ַ��� 
string repr(const string &s) 
{
	string ans=s;
	int i;
	for(i=0;i <s.length();i++)
	{
		ans[i]=tolower(ans[i]);
	}
	sort(ans.begin(),ans.end());// 
	return ans; 
} 
int main()
{
	int n=0;
	string s;
	while(cin>>s)
	{
		if(s=="#")
			break;
		words.push_back(s);
		
		string r=repr(s);
		if(!cnt.count(r))//���rû���ֹ�,��r��ֵΪ0 
			cnt[r]=0;
		cnt[r]++;
	}
	
	vector<string> ans;//�洢��������� 
	for(int i=0;i<words.size();i++)//��words��ɸѡstring����ans 
	{
		if(cnt[repr(words[i])]==1)//repr(words[i])�ȼ��������е�r 
			ans.push_back(words[i]);
	} 
	//�������� 
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
		
	return 0;
}
