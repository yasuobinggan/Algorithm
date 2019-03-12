#include <iostream>

using namespace std;

int n;
int a[505][505];

bool isBad(int h,int l) {	//λ��Խ���ж�
	return (h<0 || l<0 || h>=n ||l>=n);
}

bool PutMove(int prvs, int h, int l) {	//prvs������ʲô�ƶ������h�С���l�е�λ��
	if (prvs == -1){	//����һ�������⣬�������ӿո����
		cout << a[h][l];
		if (!isBad(h,l+1))		//����ûԽ��
			PutMove(1,h,l+1);	//�����ƶ�
	}
	else
		cout << " " << a[h][l];
	if (h == n-1 && l == n-1)	//�ݹ����
		return true;
	switch(prvs) {
		case 0:		//��
			if (!isBad(h-1,l+1))	//������ûԽ��
				PutMove(3,h-1,l+1);	//�������ƶ�
			else
				PutMove(2,h+1,l-1);	//�������ƶ�
			break;
		case 1:		//��
			if (!isBad(h+1,l-1))	//������ûԽ��
				PutMove(2,h+1,l-1);	//�������ƶ�
			else
				PutMove(3,h-1,l+1);	//�������ƶ�
			break;
		case 2:		//�L
			if (!isBad(h+1,l-1))	//������ûԽ��
				PutMove(2,h+1,l-1);	//�������ƶ�
			else if (!isBad(h+1,l))	//����ûԽ��
				PutMove(0,h+1,l);	//�����ƶ�
			else
				PutMove(1,h,l+1);	//�����ƶ�
			break;
		case 3:		//�J
			if (!isBad(h-1,l+1))	//������ûԽ��
				PutMove(3,h-1,l+1);	//�������ƶ�
			else if (!isBad(h,l+1))	//����ûԽ��
				PutMove(1,h,l+1);	//�����ƶ�
			else
				PutMove(0,h+1,l);	//�����ƶ�
			break;
	}
}

int main() {
	cin >> n;
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			cin >> a[i][j];
	PutMove(-1,0,0);
	return 0;
}
