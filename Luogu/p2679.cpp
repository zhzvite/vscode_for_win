#include<iostream>
using namespace std;
int n,m,ki;
char a[1010], b[210];
long long int dp[1010][1010] , sum[1010][1010];
int mod = 1000000007;
int main()
{
    dp[0][0] = 1;//初始化
    cin >> n >> m >> ki >> a >> b;
    for (int i = 1; i <= n;i++){
        for (int j = m; j >= 1;j--)
        {
            for (int k = ki; k >= 1;k--){
                if(a[i-1]==b[j-1])
                    sum[j][k] = (sum[j - 1][k] + dp[j - 1][k - 1])%mod ;
                else
                    sum[j][k] = 0;
            dp[j][k] = (dp[j][k] + sum[j][k])%mod;
            }
        }
    }
    cout << dp[m][ki];
    system("pause");
}