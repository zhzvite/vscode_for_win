#include<iostream>
#include<algorithm>
using namespace std;
const int N=310;
int n,s[N],dp[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)s[i]=s[i-1]+s[i];
    for(int len=2;len<=n;len++){//枚举区间长度
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;//循环区间的左端点
            dp[l][r]=1e8;//初始化
            for(int k=i;k<=r-1;k++){//k是从i开始,不是从一开始
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    cout<<dp[1][n];
    system("pause");
    return 0;
}