#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <stack>
using namespace std;
template <typename T>
inline void read(T &x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            flg = 1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    if (flg)
        x = -x;
}
const int N = 110;
int n, m;
int g[N][N];
int dp[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int res;
int dfs(int x,int y){
    int &v = dp[x][y];
    if(v!=-1)
        return v;
    v = 1;
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a>=0&&a<n&&b>=0&&b<m&&g[a][b]<g[x][y])
            v = max(v, dfs(a,b) + 1);//递归
    }
    return v;
}
int main(){
    read(n), read(m);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            read(g[i][j]);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            res = max(res, dfs(i, j));
    cout << res;
    system("pause");
    return 0;
    }    