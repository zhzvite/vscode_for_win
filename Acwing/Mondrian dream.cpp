//统计把n*m的矩形切成若干个1*2的小矩形,问有多少种方案
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
const int N = 12, M = 1 << N;
typedef long long int ll;
ll dp[N][M];
bool st[M];
int main(){
    while(cin>>n>>m,n||m){
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < 1 << n;i++){
            st[i] = true;
            int cnt = 0;
            for (int j = 0; j < n;j++){
                if(i>>j & 1){
                    if(cnt&1)
                        st[i] = false;
                    cnt = 0;
                }
                else
                    cnt++;}
                if(cnt&1)
                    st[i] = false;
        }11
        dp[0][0] = 1;
        for (int i = 1; i <= m;i++){
            for (int j = 0; j < 1 << n;j++){
                for (int k = 0; k < 1 << n;k++){
                    if((j&k)==0&&st[j|k]){
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0]<<endl;
    }
        system("pause");
}
/*
1 2
1 3
1 4

*/
