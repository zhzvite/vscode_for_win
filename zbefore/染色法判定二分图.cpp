#include<iostream>
#include<algorithm>
using namespace std;
int h[100010], ne[200010], e[200010], idx;
int n, m;
int p[100010];
int color[100010];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] =idx++;//����
}
bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c)) {
                return false;
            }    
        }
        else if (color[j] == c)return false;
    }  
    return true;
    
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {  
            if (!dfs(i, 1)) {
                flag = false;
                break;
           }
        }
    }
    if (flag)cout << "yes";
    else cout << "no";
}
/*
4 4
1 3
1 4
2 3
2 4
*/