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
const int N = 60;
int mapp[N][N];
int dp[N][N][N][N];
int n;
int a, b, c;
int main()
{
    read(n);
    while(cin>>a>>b>>c){
        if(a==0&&b==0&&c==0)
            break;
        else
            mapp[a][b] = c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int l = 1; l <= n; l++)
                for (int k = 1; k <= n; k++)
                {
                    dp[i][j][l][k] = max(max(dp[i - 1][j][l - 1][k], dp[i][j - 1][l][k-1]), max(dp[i-1][j][l][k-1], dp[i][j - 1][l-1][k])) + mapp[i][j];
                    if (i != 1 && j != k)
                        dp[i][j][l][k] += mapp[l][k];
                    // dp[i][j][l][k] = max(max(dp[i - 1][j][l - 1][k], dp[i][j - 1][l][k - 1]), max(dp[i - 1][j][l][k - 1], dp[i][j - 1][l - 1][k])) + mapp[i][j];
                    // if (i != 1 && j != k)
                    //     dp[i][j][l][k] += mapp[l][k];
                }
    cout << dp[n][n][n][n];
    system("pause");
}