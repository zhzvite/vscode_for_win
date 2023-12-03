//在边数限定条件的最短路
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int  N = 10010;
int dist[N], backup[N];
int n, m, k;
struct Edge {
	int a, b, w;
}edge[N];
int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 1; j <= m; j++) {
			int x = edge[j].a, y = edge[j].b, z = edge[j].w;
			dist[y] = min(dist[y], backup[x] + z);
		}
	}
	if (dist[n] >0x3f3f3f3f / 2)return -1;//存在负权，有可能是0x3f3f3f3f-2，小于0x3f3f3f3f
	else return dist[n];
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[i] = { x,y,z };
	}
	int t = bellman_ford();
	if (t == -1)cout << "impossible";
	else cout << t;
}
/*
3 3 1
1 2 1
2 3 1
1 3 3
*/