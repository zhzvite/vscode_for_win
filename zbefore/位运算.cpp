//�����ص��¼����λ����Ļ�����Ӧ��
#include<iostream>
using namespace std;
int lowbit(int x) {
     return x & (-x);
}//�����������Դ��Ͳ�������ʣ�����x�Ķ����������һ��β��һ����������

int main()
{
	int x;
//	x=10;
//	for (int i = 0; i < 4; i++) {
//	cout << (x << i)<<endl;
//	}
	int n;
	cin >> n;
	while (n--) {
		cin >> x;
		int res = 0;
		while (x) {
			x -= lowbit(x);
			res++;
		}
		cout << res << " ";//���ô˶γ������¼���ÿ�����ֵĶ�����һ�ж��ٸ�
	}
}