#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll b;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll l = 0, r, mid;
int main()
{
    cin >> b;
    for (int i = 1; i <= 37; i++)
    {
        if (qpow(i, i) == b)
        {
            cout << i;
            //system("pause");
            return 0;
        }
        
    }cout << -1;
    //    cout << l << " " << r;
    //system("pause");
}