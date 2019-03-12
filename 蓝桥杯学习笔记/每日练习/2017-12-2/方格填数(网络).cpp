#include <stdio.h>
#include <math.h>
int flag[3][4]; //��ʾ��Щ��������
int mpt[3][4]; //����
bool visit[10];
int ans = 0;//��ѡ������ 
void init()   //��ʼ����ѡ�� 
{
	int i,j;
	for(i = 0 ; i < 3 ; i ++)
		for(j = 0 ; j < 4 ; j ++)
			flag[i][j] = 1;//flag[i][j]==1��ѡ 
	flag[0][0] = 0;
	flag[2][3] = 0;
}
void Solve()//�жϽ��Ƿ��ѡ 
{
	int dir[8][2] = { 0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};//��ʾ���� 
	int book = true;
	for(int i = 0 ; i < 3 ; i ++)
	{
		for(int j = 0 ; j < 4; j ++)
		{
			//�ж�ÿ������Χ�Ƿ�����
			if(flag[i][j] == 0)continue;
			for( int k = 0 ; k < 8 ; k ++)//�ж����ܵĿ�ѡ�� 
			{
				int x,y;
				x = i + dir[k][0];
				y = j + dir[k][1];
				if(x < 0 || x >= 3 || y < 0 || y >= 4 || flag[x][y] == 0)//Խ�絽����ѡ�ռ� 
					continue;
				if(abs(mpt[x][y] - mpt[i][j]) == 1)//δԽ�絽����ѡ�ռ�,�鿴��λ���Ƿ�ѡ��  
					book = false;//���������λ������,book=false,�˽ⲻ���� 
			}
		}
	}
	if(book) ans ++;
}
void dfs(int index)
{
	int x,y;
	x = index / 4;
	y = index % 4;
	//x,y����flag�ı��� 
	if( x == 3)//��ʾ��ѡ������ 
	{
		Solve();//�ж��Ƿ��ѡ,���Ƽ������Լ� 
		return;
	}
	if(flag[x][y])//flag��ѡ 
	{
		for(int i = 0 ; i < 10 ; i ++)
		{
			if(!visit[i])//iΪ��д������ 
			{
				visit[i] = true;//��ע���� 
				mpt[x][y] = i;
				dfs(index+1);
				visit[i] = false;
			}
		}
	}
	else//flag����ѡ 
	{
		dfs(index+1);
	}
}
//����ȫ����,����Լ�������ж��Ƿ���� 
int main()
{
	init();
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
