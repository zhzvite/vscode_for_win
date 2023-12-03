#include<iostream>
using namespace std;

typedef int long long ll;
struct
{
    ll u, v, w;
} a[110];
ll n, m, k;
ll ans = 0x3f3f3f3f, num[20], p[20];
bool vis[20];
int find(int x){
    if(x!=p[x])
        return find(p[x]);
    return p[x];
}
void dfs(int step,int lst){
    if(step==n-1){
        int anss = 0;
        for (int i = 1;i<)
    }

}
int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)
        p[i] = i;
    for (int i = 1; i < m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    dfs(0, 1);
    cout << ans << endl;
    system("pause");
}
