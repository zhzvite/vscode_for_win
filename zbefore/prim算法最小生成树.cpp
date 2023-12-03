//����С������������Ϊ�ߵ�Ȩ���������Ǹ�
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
            if (i>0 && dist[t] == inf)return inf;//��Ϊ��һ��i=0��ѭ������dist����inf��ֻ��Ϊ�˵�һ�θ������е�distΪ��1����̾���
            if (i>0)res += dist[t];//���ۼ��ٸ���
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
        g[x][y] = g[y][x] = min(g[x][y],c);//ȡ���Ǳ߳�����Сֵ��ͬʱ��������ͼ
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

