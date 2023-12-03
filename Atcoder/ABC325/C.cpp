#include<iostream>
using namespace std;
using namespace std;
int n;
const int N = 1010;
char g[N][N];
int h, w;
bool st[N][N];
int cnt = 0;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
void dfs(int x,int y){
    st[x][y] = true;
    for (int i = 0; i <= 7;i++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if(x1>=1&&x1<=h&&y1>=1&&y1<=w){
            if(g[x1][y1]=='#'&&!st[x1][y1]){
                st[x1][y1] = true;
                dfs(x1, y1);
            }
        }
    }
}
int main(){
    cin >> h >> w;
    for (int i = 1; i <= h;i++)
        for (int j = 1; j <= w;j++)
            cin >> g[i][j];
    for (int i = 1; i <= h;i++)
        for (int j = 1; j <= w;j++)
        if(g[i][j]=='#'&&!st[i][j])
            {
                dfs(i, j);
                cnt++;
            }
    cout << cnt;
    system("pause");
}