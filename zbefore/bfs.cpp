#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110;
typedef pair<int, int> pii;
int n, m;
int g[N][N], d[N][N];//g负责存地图，d负责记录有没有走过
pii q[N * N],p[N ][N];
int bfs() {
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	int hh = 0, tt = 0;//采用栈的形式进行数据的堆叠
	memset(d, -1, sizeof d);
	q[0] = { 0,0 };
	d[0][0] = 0;
	while (hh <= tt) {
		auto t = q[hh++];
		for (int i = 0; i < 4; i++) {
			int x = t.first + dx[i], y = t.second + dy[i];//上下左右遍历
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[t.first][t.second] + 1;//记录他是几号点
			//	d[x][y] = 1;
				p[x][y] = t;//把上一个点塞进去了，类似于递归
				q[++tt] = { x,y };//满足条件则往栈顶压入数据
			}
		}
	}
	//输出路迳   
	int x = n - 1, y = m - 1;
	while (x || y) {
		cout << x << " " << y << endl;
		auto t = p[x][y];
		x = t.first, y = t.second;
	}
	return d[n - 1][m - 1];
}
int main() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> g[i][j];
	}
	cout<<bfs()<<endl;
	system("pause");

}
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/