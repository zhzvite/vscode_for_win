#include<iostream>
using namespace std;
const int N=510,inf=1e9;
int n,dp[N][N],a[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    cin>>a[i][j];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=i+1;j++)//初始化要考虑边界问题,每行多初始化一个
    dp[i][j]=-inf;//题目要求要从最上层到最底层的最大路径,要考虑到数字可以为负数
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
    int res=-inf;
    for(int i=1;i<=n;i++)res=max(res,dp[n][i]);
    cout<<res;
    system("pause");
    // 5 
    // 7
    // 3 8
    // 8 1 0
    // 2 7 4 4
    // 4 5 2 6 5
}

