#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 6e3 + 10;
int ha[N], ne[N], e[N], h[N], idx;
bool st[N];
int dp[N][2];
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u){
    dp[u][1] = ha[u];
    for (int i = h[u]; i != -1;i=ne[i]){
        int j = e[i];
        dfs(j);
        dp[u][1] += dp[j][0];
        dp[u][0] += max(dp[j][1], dp[j][0]);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> ha[i];
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
        st[a] = true;
    }
    int root = 1;
    while(st[root])
        root++;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]);
    //system("pause");
}