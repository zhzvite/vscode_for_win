#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];//�����Ƕ�ά�����������Ż�
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];//�ӵ�һ����ʼ���
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >=v[i]; j--) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}cout << f[m];//���ص������������Ϊmʱ������ֵ
}
/*
4 5
1 2
2 4
3 4
4 5
*/
//8