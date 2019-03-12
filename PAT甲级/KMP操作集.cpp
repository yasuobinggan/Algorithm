const int maxn=1e5;
int next[maxn];
//���Ƽ���next����
void next(char s[],int len)
{
	next[0]=-1;
	int j=-1;//������չλ�õ�ָ��

	//��ǰ�����������
	for(int i=1;j<len;i++)
	{
		//ƥ�䲻�ɹ���ǰ����
		//������������һ����ֹͣ����
		while(j!=-1&&s[j+1]!=s[i])
		{
			//��֮ǰ�ķ������
			j=next[j];
		}
		//ƥ��ɹ�ָ���ƶ�
		if(s[j+1]==s[i])
		{
			j++;
		}
		//��¼next����
		next[i]=j;
	 }
 }
 //��ͨKMPƥ��
 bool KMP(char text[],char pattern[])
 {
 	int n=strlen(text),m=strlen(pattern);
 	//����pattern��next����
	 getNext(pattern,m);
 	//��ʼ��j
 	int j=-1;
 	for(int i=0;i<n;i++)
 	{
 		while(j!=-1&&pattern[j+1]!=text[i])
 		{
 			j=next[j];
		 }
		if(pattern[j+1]==text[i])
		{
			j++;
		}
		//ƥ�䵽���һλ�ɹ�
		if(j==m-1)
		{
			return true;
		}
	 }
	 return false;
}
//��¼���ִ�����KMPƥ��
int KMP(char text[],char pattern[])
{
    int n=strlen(text),m=strlen(pattern);
    getNext(pattern,m);

    int ans=0,j=-1;
    for(int i=0;i<n;i++)
    {
        while(j!=-1&&pattern[j+1]!=text[i])
        {
            j=next[j];
        }
        if(pattern[j+1]==text[i])
        {
            j++;
        }
        //patternƥ��ɹ�
        if(j==m-1)
        {
            ans++;
            //j���˵�next[j]����ƥ��
            j=next[j];
        }
    }
    return ans;
}
