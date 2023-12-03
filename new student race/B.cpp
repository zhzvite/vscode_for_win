#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll q, k;
const int N = 1e6 + 10;
ll a[N];
const int mod = 1e9 + 7;
ll ans = 1;
ll l, r;
int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main(){
    cin >> q >> k;
    for (int i = 1; i <= q;i++){
        cin >> a[i];
    }
    for (int i = 2;;i++){
        if(k==qpow(2,i-1)){
            l = 0;
            break;
        }
        if(k<qpow(2,i)&&k>qpow(2,i-1)){
            l = qpow(2, i - 1);
            r = qpow(2, i);
            break;
                }
            
    }
    //cout << l << endl;
    for (int i = 1; i <= q;i++){
        if(a[i]<=k-l||a[i]>l)
            ans =(ans*(1 + k - a[i]))%mod;
        else
            ans = (ans * (k + 1)) % mod;
    }
    cout << ans%mod;
    system("pause");
}