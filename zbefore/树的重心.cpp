#include<iostream>
#include<cstring>
using namespace std;
const int N = 10010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;//�������ӱ�
bool st[N];//��¼����û�б�������
int ans = N;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}
//��uΪ���������е������
int dfs(int u) {
	st[u] = true;
	int sum = 1, res = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = ne[i];
		if (!st[j]) {//�����û�б�ɨ��
			int s = dfs(j);//����Ǽ���jΪ���������ĵ������
			res = max(res, s);//��������
			sum += s;//sum����u���¼����е������
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;//�ع�����Դ
}
int main() {
	cin >> n ;
	memset(h, -1, sizeof h);//��ʼ��hͳһΪ-1
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b),add(b,a);
	}
	dfs(1);
	cout << ans << endl;
}
/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
*/