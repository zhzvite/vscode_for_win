#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2e5+10;
int ne[N], idx, e[N], h[N], w[N];
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int  c) {
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
void spfa() {
	//memset(st, false, sizeof st);
	memset(dist, -1, sizeof dist);
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
				if (dist[j] < dist[t] + w[i]) {
					dist[j] = dist[t] + w[i];
					//cnt[j]=cnt[t]+1; if(cnt[j]>=n)return true;判断负环
					if (!st[j]) {
						q.push(j);
						st[j] = true;
					}
				}	
			}
	}
	
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	spfa();
	cout<<dist[n];
    //system("pause");
    return 0;
}