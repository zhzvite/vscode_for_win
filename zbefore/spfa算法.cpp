//spfaÀ„∑®
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 10010;
int ne[N], idx, e[N], h[N], w[N];
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int  c) {
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int spfa() {
	memset(st, false, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size()) {
		int t = q.front();
			q.pop();
			st[t] = false;
			for (int i = h[t]; ~i; i = ne[i]) {
				int j = e[i];
				if (dist[j] > dist[t] + w[i]) {
					dist[j] = dist[t] + w[i];
					if (!st[j]) {
						q.push(j);
						st[j] = true;
					}
				}	
			}
	}
	if (dist[n] == 0x3f3f3f3f)return -1;
	else return dist[n];
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
	if (t == -1)cout << " no";
	else cout << t;

}
/*
3 3 
1 2 5
2 3 -3
1 3 4

*/

