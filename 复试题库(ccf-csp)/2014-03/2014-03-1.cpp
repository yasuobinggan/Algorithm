#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn = 1005;

int posnum[maxn], negnum[maxn];
int n;
int vert(int value)
{
	return 0 - value;
}

void testout()
{
    cout<<"************************";
    cout<<endl<<"������"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<negnum[i]<<" ";
    }

    cout<<endl<<"������"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<posnum[i]<<" ";
    }
    cout<<endl<<"************************"<<endl;
}
int main()
{
	memset(posnum, 0, sizeof(posnum));
	memset(negnum, 0, sizeof(negnum));

	cin >> n;
	int ans = 0;
	int value;
	for (int i = 0; i<n; i++)
	{
		cin >> value;

		if (value >= 0 && negnum[value] != 0)
		{
			negnum[value]--;
			ans++;
			//cout<<"�����٣�"<<negnum[value]<<" ";
			//cout<<"��ǰ�����"<<ans<<endl;
			//testout();
		}
		else if (value >= 0 && negnum[value] == 0)
		{
			posnum[value]++;
			//cout<<"�����ӣ�"<<posnum[value]<<endl;
			//testout();
		}
		else if (value<0 && posnum[vert(value)] != 0)
		{
			posnum[vert(value)]--;
			ans++;
			//cout<<"�����٣�"<<posnum[vert(value)]<<" ";
			//cout<<"��ǰ�����"<<ans<<endl;
			//testout();
		}
		else if (value<0 && posnum[vert(value)] == 0)
		{
			negnum[vert(value)]++;
			//cout<<"�����ӣ�"<<negnum[vert(value)]<<endl;
			//testout();
		}
	}
	cout << ans;
	return 0;
}


/*
11
-1 1 -1 -1 1 2 -2 3 4 5 -3
*/
