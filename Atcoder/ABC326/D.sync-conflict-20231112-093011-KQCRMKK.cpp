#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using namespace std;
const int Max = 15;
int  cnt;
string r, c;

char a[Max][Max], ch[] = {'.', 'A', 'B', 'C'};
int vis[Max][500], vis2[Max][500];
int n;
bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == '.')
                continue;
            if (a[i][j] != r[i - 1])
                return 0;
            else
                break;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == '.')
                continue;
            if (a[j][i] != c[i - 1])
                return 0;
            else
                break;
        }
    return 1;
}

void dfs(int x, int y)
{
    if (cnt == n * n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++)
                if (!vis[i][ch[j]] || !vis2[i][ch[j]])
                    return;
        if (check())
        {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    cout << a[i][j];
                cout << "\n";
            }
            system("pause");
        }
        return;
    }
    
    if (n - vis[x]['.'] < 3 || n - vis2[y]['.'] < 3)
        return;
    cnt++;
    for (int i = 1; i <= 3; i++)
    {
        if (!vis[x][ch[i]] && !vis2[y][ch[i]])
        {
            a[x][y] = ch[i];
            vis[x][ch[i]] = 1;
            vis2[y][ch[i]] = 1;
            if (y + 1 <= n)
                dfs(x, y + 1);
            else
                dfs(x + 1, 1);
            vis[x][ch[i]] = 0;
            vis2[y][ch[i]] = 0;
        }
    }
    a[x][y] = '.';
    vis[x]['.']++;
    vis2[y]['.']++;
    if (y + 1 <= n)
        dfs(x, y + 1);
    else
        dfs(x + 1, 1);
    vis[x]['.']--;
    vis2[y]['.']--;
    cnt++;
}
void  main()
{
    cin >> n;
    cin >> r >> c;
    dfs(1, 1);
    cout << "No";
    system("pause");
    //return 0;
}