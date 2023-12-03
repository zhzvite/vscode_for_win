#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//q[N]为队列，d[N]是入度
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort() {//队列中hh是对头，tt是队尾
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++) {
		if (!d[i])q[++tt] = i;}//将入度为0的点放进队列
		while (hh <= tt) {
			int t = q[hh++];
			for (int i = h[t]; i != -1; i = ne[i]) {
				int j = e[i];
				d[j]--;//让入度减减
				if (d[j] == 0)q[++tt] = j;//当入度减为零了，将他压入队列
			}
		}
	return tt == n - 1;//判断它是不是有向无环图
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
		for (int i = 0; i < n; i++)cout << q[i] << " ";//q[i]中存的就是拓扑序（如果有
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