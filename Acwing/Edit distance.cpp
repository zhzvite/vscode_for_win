//给定字符串A和B,将a经过若干操作变为b,如删除,插入,替换,求最少操作次数
#include<iostream>
using namespace std;
const int N=1010;
int n,m;
char  a[N],b[N];
int dp[N][N];
int main(){
    cin>>n>>a+1>>m>>b+1;
    for(int i=0;i<=m;i++)dp[0][i]=i;//添加操作
    for(int i=0;i<=n;i++)dp[i][0]=i;//删除操作
    //dp过程
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
            if(a[i]==b[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
        }
    }   
    cout<<dp[n][m];
    system("pause");
}