//最长上升子序列O(n*n)
// #include<iostream>
// using namespace std;
// const int N=1010;
// int n,dp[N],a[N];
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++){
//         dp[i]=1;//初始化
//         for(int j=1;j<i;j++)      
//             if(a[j]<a[i])   dp[i]=max(dp[i],dp[j]+1);         
//     }
//     int res=0;
//     for(int i=1;i<=n;i++)res=max(res,dp[i]);
//     cout<<res<<endl;
//     system("pause");
//     return 0;
// }
//记录状态转移的记录(但只会得到其中一条路径),每次更新完用一个记忆化数组将**坐标**存下来
//记录路迳
#include<iostream>
using namespace std;
const int N=1010;
int n,dp[N],a[N],g[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        dp[i]=1;//初始化
        g[i]=0;
        for(int j=1;j<i;j++)      
            if(a[j]<a[i]){
                 if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    g[i]=j;
                 }
            }       
    }
    int k=1;
    for(int i=1;i<=n;i++){
        if(dp[i]>dp[k])k=i;
    }
    cout<<dp[k]<<endl;
    for(int i=0,len=dp[k];i<len;i++){//要注意要确定以dp[k]为len
         cout<<a[k]<<" "; 
         k=g[k];   
    }
    system("pause");
    return 0;
}