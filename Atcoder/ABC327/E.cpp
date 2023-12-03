#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
const int N = 5010;
int f[N];
double dp[N][N];
double x = 1;
double maxn = -0x3f3f3f3f;
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> f[i];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++){
            dp[i][j] = max(dp[i - 1][j] ,dp[i - 1][j - 1] * 0.9 + f[i]);
        }
    }
    for (int i = 1; i <= n;i++){
        dp[n][i] = dp[n][i] / x - 1200 / sqrt(i);
        maxn = max(maxn, dp[n][i]);
        x = x * 0.9 + 1;
    }
    cout <<fixed<<setprecision(15)<< maxn;

    //system("pause");
}