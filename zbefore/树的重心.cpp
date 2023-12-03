#include<iostream>
#include<cstring>
using namespace std;
const int N = 10010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;//正常连接表
bool st[N];//记录他有没有被遍历过
int ans = N;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx, idx++;
}
//以u为根的子树中点的数量
int dfs(int u) {
	st[u] = true;
	int sum = 1, res = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = ne[i];
		if (!st[j]) {//如果他没有被扫过
			int s = dfs(j);//这个是加上j为根的子树的点的数量
			res = max(res, s);//挑出最大的
			sum += s;//sum就是u的下级所有点的数量
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;//回归吗，溯源
}
int main() {
	cin >> n ;
	memset(h, -1, sizeof h);//初始化h统一为-1
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