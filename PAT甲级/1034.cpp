////���ĳ�vectorӦ�û����
//Ȩֵ�Ƚ�,����Ȩֵʹ�����ô��λ����
#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
using namespace std;
const int maxl = 26;
int G[maxl][maxl];//�绰��//����ͼ

bool fang[maxl];//���ʱ������
int gang_num[maxl];//ÿ������ĳ�Ա��
int h_w[maxl];//û���Ȩֵ��
bool g_k_h[maxl];//�Ƿ������ֵ,�Ƿ��������ͷ

int K, N;
//rootΪ��ǰ�������ĸ��ڵ�
int dfs(int root, int i, int curwei)//˼������ںϲ��л��mtw�����ô���(ֱ�������ô��θ���ʹ��)//mtw,mti��ȡ�����е�head
{

	if (curwei>K)
	{
		g_k_h[root] = true;
	}
	gang_num[root]++;
	int mti=i, mtw = 0;
	for (int j = 0; j<maxl; j++)
	{
		if (G[i][j] != 0 && !fang[j])
		{
			fang[j] = true;
			curwei += G[i][j];
			int curti = dfs(root, j, curwei);

			if (h_w[curti]>mtw)//��ǰ�����ֵ�������ֵ
			{
				mtw = h_w[curti];
				mti = curti;
			}
			//fang[j] = false;
		}
	}
	//��һ�����Ȩ
	int stw = 0;
	for (int z = 0; z<maxl; z++)
	{
		if (G[i][z] != 0)
			stw += G[i][z];
	}
	h_w[i] = stw;
	//�Ƚ�
	if (stw>mtw)
	{
		mtw = stw;
		mti = i;

	}
	return mti;
}
int main()
{
	char name1[3], name2[3];
	int weight;
	cin >> N >> K;

	memset(G, 0, sizeof(G));
	for (int i = 0; i<N; i++)
	{
		cin >> name1 >> name2;
		cin >> weight;
		G[name1[0] - 'A'][name2[0] - 'A'] += weight;
		G[name2[0] - 'A'][name1[0] - 'A'] += weight;
	}

	fill(gang_num, gang_num + maxl, 0);
	fill(g_k_h, g_k_h + maxl, 0);
	fill(h_w, h_w + maxl, 0);

	for (int i = 0; i<maxl; i++)
	{
		fang[i] = true;
		if (i != dfs(i, i, 0))
			g_k_h[i] = false;
		fill(fang, fang + maxl, 0);
	}


	int ans = 0;
	for (int i = 0; i<maxl; i++)
	{
		ans += g_k_h[i];
	}
	cout << ans << endl;
	for (int i = 0; i<maxl; i++)
	{
		if (g_k_h[i])
		{
			cout << i << " " << gang_num[i] << endl;
		}
	}
	return 0;
}
/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/



//��һ���汾
/*
//���ĳ�vectorӦ�û����
//Ȩֵ�Ƚ�,����Ȩֵʹ�����ô��λ����
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxl = 26;
int G[maxl][maxl];//�绰��//����ͼ

bool fang[maxl];//���ʱ������
int gang_num[maxl];//ÿ������ĳ�Ա��
int h_w[maxl];//û���Ȩֵ��
bool g_k_h[maxl];//�Ƿ������ֵ,�Ƿ��������ͷ

int K, N;
//rootΪ��ǰ�������ĸ��ڵ�
int dfs(int root, int i, int curwei)//˼������ںϲ��л��mtw�����ô���(ֱ�������ô��θ���ʹ��)//mtw,mti��ȡ�����е�head
{

	if (curwei>K)
	{
		g_k_h[root] = true;
	}
	gang_num[root]++;
	int mti=i, mtw = 0;
	//��һ�����Ȩ
	int stw = 0;
	for (int z = 0; z<maxl; z++)
	{
		if (G[i][z] != 0)
			stw += G[i][z];
	}
	h_w[i] = stw;
	//�Ƚ�
	if (stw>mtw)
	{
		mtw = stw;
		mti = i;

	}
	for (int j = 0; j<maxl; j++)
	{
		if (G[i][j] != 0 && !fang[j])
		{
			fang[j] = true;
			curwei += G[i][j];
			int curti = dfs(root, j, curwei);

			if (h_w[curti]>mtw)//��ǰ�����ֵ�������ֵ
			{
				mtw = h_w[curti];
				mti = curti;
			}
			//fang[j] = false;
		}
	}

	return mti;
}
int main()
{
	char name1[3], name2[3];
	int weight;
	cin >> N >> K;

	memset(G, 0, sizeof(G));
	for (int i = 0; i<N; i++)
	{
		cin >> name1 >> name2;
		cin >> weight;
		G[name1[0] - 'A'][name2[0] - 'A'] += weight;
		G[name2[0] - 'A'][name1[0] - 'A'] += weight;
	}

	fill(gang_num, gang_num + maxl, 0);
	fill(g_k_h, g_k_h + maxl, 0);
	fill(h_w, h_w + maxl, 0);

	for (int i = 0; i<maxl; i++)
	{
		fang[i] = true;
		if (i != dfs(i, i, 0))
			g_k_h[i] = false;
		fill(fang, fang + maxl, 0);
	}


	int ans = 0;
	for (int i = 0; i<maxl; i++)
	{
		ans += g_k_h[i];
	}
	cout << ans << endl;
	for (int i = 0; i<maxl; i++)
	{
		if (g_k_h[i])
		{
			cout << i << " " << gang_num[i] << endl;
		}
	}
	return 0;
}

*/

