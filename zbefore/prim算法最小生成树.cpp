//在最小生成树中无所为边的权重是正还是负
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N = 510,inf=0x3f3f3f3f;
int n, m;  
int g[N][N];
int dist[N];
bool st[N];
int prim() {
    memset(dist, inf, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
            if (i>0 && dist[t] == inf)return inf;//因为第一次i=0的循环所有dist都是inf，只是为了第一次更新所有的dist为到1的最短距离
            if (i>0)res += dist[t];//先累加再更新
            for (int j = 1; j <= n; j++)
                dist[j] = min(dist[j],g[t][j]);
            st[t] = true;
        
    }
    return res;
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f3f3f3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x][y] = g[y][x] = min(g[x][y],c);//取得是边长的最小值，同时构建无向图
    }
   int t= prim();
   if (t == inf)cout << "impossible";
   else cout << t;
}
/*
5 10
1 2 8
2 2 7
2 1 1
3 4 3
4 4 -10
1 3 -9
5 2 -4
3 1 0
1 4 8
4 4 7
*/

