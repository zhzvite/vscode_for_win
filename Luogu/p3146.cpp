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
int n;
int a[250],s[250];
int ans;
int dp[250][250];//表示从i到j中出现的最大值
int main(){
    read(n);
    for (int i = 1; i <= n;i++)
        {
        read(dp[i][i]); // 初始化,每个小区间的点最大值都是他自己
        ans = max(ans, dp[i][i]);
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int l = i, r = i + len - 1;
                for (int k = i; k < r; k++)
                {
                    if (dp[l][k] == dp[k + 1][r] && dp[l][k] > 0)
                    {
                        dp[l][r] = max(dp[l][r], dp[l][k] + 1);
                        ans = max(dp[l][r], ans);
                    }
                    //    cout << "dp" << i << " " << r <<" "<<k<<" "<< dp[i][r]<<endl;
                }
            }
    }
    cout << ans;

    system("pause");
    return 0;
}