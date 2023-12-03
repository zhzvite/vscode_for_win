#include<iostream>
#include<cstring>
using namespace std;
int t;
int n;
const int  N =2e5 + 10;
int dp[N];
int a[N];
int main(){
    cin >> t;
    while(t--){
        
        memset(dp, 0, sizeof dp);
        dp[0] = -0x3f3f3f3f;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            dp[i] = a[i];
        }
        for (int i = 2; i <= n;i++){
            if((a[i]%2==0&&a[i-1]%2!=0)||(a[i]%2!=0&&a[i-1]%2==0))
                dp[i] = max(dp[i], dp[i - 1] + a[i  ]);
        }
        for (int i = 1; i <= n;i++)
            dp[0] = max(dp[0], dp[i]);
        cout << dp[0] << endl;
        
    }
//    system("pause");
}