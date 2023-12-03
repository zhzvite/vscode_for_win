#include<iostream>
#include<cmath>
using namespace std;
const int N = 1010;
int a[N][N];
int dp[N][N];
int n;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= i;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++)
        {
            dp[i][j] = max(dp[i - 1][j-1], dp[i-1][j ]) + a[i][j];
        //    cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int ans=0;
    for (int i = 1; i <= n;i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
    system("pause");

}
