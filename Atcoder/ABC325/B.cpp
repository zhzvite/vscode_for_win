#include<iostream>
#include<vector>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> x[i];
    int res = 0;
    for (int i = 0; i <= 23; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            int t = (i + x[j]) % 24;
            if (t >= 9 && t <= 17)
                s += w[j];
        }
        res = max(res, s);
    }
    cout << res << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}