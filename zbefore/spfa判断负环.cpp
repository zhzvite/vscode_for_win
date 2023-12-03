//spfa算法，通过维护一个cnt来判断是否存在负环
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 10010;
int ne[N], idx, e[N], h[N], w[N];
int dist[N],cnt[N];
bool st[N];
int n, m;
void add(int a, int b, int  c) {
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}
	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)return true;
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	int t = spfa();
	if (t)cout << "yes";
	else cout << "No";

}
/*
3 3
1 2 -1
2 3 4
3 1 -4

*/

