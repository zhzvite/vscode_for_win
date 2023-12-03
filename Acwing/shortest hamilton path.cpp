#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
const int N = 20,M=1<<13;
int w[N][N];
int dp[M][M];
int main(){
    cin >> n ;
    for (int i = 0; i <n;i++)
        for (int j = 0; j < n;j++)
            cin >> w[i][j];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;//走过了0这个点,从0到0这个点的方案
    for (int i = 0; i < 1 << n;i++){
        for (int j = 0; j < n;j++){
            if(i>>j &1)
                for (int k = 0; k < n;k++){
                    if(i-(1<<j)>>k &1)
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
                }
        }
    }
    cout << dp[(1<<n)-1][n-1] << endl;
    system("pause");
    return 0;
}
/*
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0

*/