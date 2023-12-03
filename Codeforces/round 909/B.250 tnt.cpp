#include<iostream>
#include<cstring>
using namespace std;
typedef  long long ll;
int t;
int n;
const int N = 150010;
ll a[N];
ll b[N];
ll cnt = 0;
ll maxx = 0;
ll minn = 0x3f3f3f3f;
ll ans = 0;
void solve(){
    ans = 0;
    for (int i = 0; i < cnt;i++){
        int h = b[i];
        minn = 0x3f3f3f3f3f3f3f3f;
        maxx = 0;
        for (int i = 1; i <= n-h+1;i=i+h){
            maxx = max(maxx, a[i+h-1]-a[i-1]);
            minn = min(minn, a[i + h - 1] - a[i - 1]);
         //  cout<<maxx<<" "<<minn<<endl;
        }
        ans = max(ans,maxx - minn);
    }
    
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
       memset(b, 0, sizeof 0); 
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        for (int i = 1; i <= n / i;i++){
            if(n%i==0&&i!=n){
                b[cnt++] = i;
                if(n/i!=i&&i!=n&&n/i!=n)
                    b[cnt++] = n / i;
            }
        }
    //    for (int i = 0; i < cnt;i++)cout<<b[i]<<endl;

            for (int i = 1; i <= n; i++)
                a[i] = a[i] + a[i - 1];
        solve();
        
           }
    system("pause");
}
