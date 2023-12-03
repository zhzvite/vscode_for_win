#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//q[N]Ϊ���У�d[N]�����
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort() {//������hh�Ƕ�ͷ��tt�Ƕ�β
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++) {
		if (!d[i])q[++tt] = i;}//�����Ϊ0�ĵ�Ž�����
		while (hh <= tt) {
			int t = q[hh++];
			for (int i = h[t]; i != -1; i = ne[i]) {
				int j = e[i];
				d[j]--;//����ȼ���
				if (d[j] == 0)q[++tt] = j;//����ȼ�Ϊ���ˣ�����ѹ�����
			}
		}
	return tt == n - 1;//�ж����ǲ��������޻�ͼ
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	if (topsort()) {
		for (int i = 0; i < n; i++)cout << q[i] << " ";//q[i]�д�ľ��������������
	}
	else cout << "-1";
}
/*
3 3
1 2
2 3
1 3
*/
//1 2 3