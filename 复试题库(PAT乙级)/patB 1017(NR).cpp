#include <iostream>
#include <string> 
using namespace std;
int main()
{
	string a;
	int b;
	cin >> a >> b;
	int t, temp;
	int lena = a.length();
	t = (a[0] - '0') / b;  //�� 
	if (lena == 1 || (t != 0 && lena > 1)) 
	{ //��Ϊ����Ϊ1�����1������� 
	 	cout << t;
	}
	temp = (a[0] - '0') % b; //���� 
	for (int i = 1; i < lena; i++) 
	{
		t = ((temp * 10) + a[i] - '0') / b;
			cout << t;
		temp = ((temp * 10) + a[i] - '0') % b;
	} 
	cout << " " << temp;
	return 0;
}
