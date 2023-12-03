#include<iostream>
#include<cmath>
using namespace std;
const int N = 5010;
int n, c, m, k;
int a[N];
int dp[N][10010];
int main(){
    cin >> n >> c >> m >> k;
    for (int i = 1; i <= c;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= c;i++){
        for (int j = 1; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
        if(a[i]<=min(m,k)&&j-a[i]>=0)   
         dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+a[i]);
        }
    }
    cout << dp[c][m];
    system("pause");
}