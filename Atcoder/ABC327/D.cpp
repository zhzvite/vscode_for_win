 #include<iostream>
 #include<vector>
using namespace std;
int n, m;
const int N = 2e5 + 10;
vector<int> g[N];
int a[N], b[N];
int vis[N];
bool flag = true;
void dfs(int i){
    if(flag==false)return;
    for(auto x:g[i]){
        if(vis[x]==0){
            vis[x] = -vis[i];
            dfs(x);
        }
        if(vis[x]==vis[i]){
            flag = false;
            return;
        }

    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m;i++){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= m;i++){
        if(vis[i]==0)
            vis[i] = 1;
        dfs(i);
    }
    if(!flag )
        cout << "No";
        else
        cout << "Yes";
        system("pause");
}
