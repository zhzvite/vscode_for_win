#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 210,inf=0x3f3f3f3f;
int n, m, q;
int dist[N][N];
void floyd() {//基于动态规划的算法的k次前k-1次的点有关
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {			
			if (i == j)dist[i][j] == 0;
			else dist[i][j] = inf;
		 }
	}
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		dist[x][y] = min(dist[x][y],z);
	}
	floyd();
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] > inf / 2)cout << "impossible";
		else cout << dist[a][b];
	}
		
}
