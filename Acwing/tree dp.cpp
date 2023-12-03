#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=6010;
int happy[N];
int e[N], ne[N], h[N], idx;
bool has_father[N];
int dp[N][2];
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void  dfs(int u){
    dp[u][1] = happy[u];
    for (int i = h[u]; i != -1;i=ne[i]){
        int j = e[i];
        dfs(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}


int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++)
        cin >> happy[i];
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            has_father[a] = true;
            add(b, a);
        }
    int root = 1;
    while(has_father[root])
        root++;
    dfs(root);
    cout << max(dp[root][1], dp[root][0]) << endl;
    system("pause");
    return 0;

}
/*
7
1 1 1 1 1 1 1
1 3
2 3
6 4
7 4
4 5
3 5
0 0


*/