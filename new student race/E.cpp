// 在最小生成树中无所为边的权重是正还是负
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 5e3 + 10;
int n, t,inf=0x3f3f3f3f;
typedef long long int ll;
ll a[N];
ll g[N][N];
ll dist[N];
bool st[N];
ll prim()
{
    memset(st, false, sizeof st);
    memset(dist, inf, sizeof dist);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i > 0 && dist[t] == inf)
            return inf; // 因为第一次i=0的循环所有dist都是inf，只是为了第一次更新所有的dist为到1的最短距离
        if (i > 0)
            res += dist[t]; // 先累加再更新
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    return res;
}

int main()
{
     cin>>t;
     while(t--){
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n;i++){
            g[i][i] = 0x3f3f3f3f;
            for (int j = 1; j <= n;j++){
                g[i][j] = a[i] + a[j];
            }
        }
        cout << prim() << endl;
     }


    system("pause");
    return 0;
}
