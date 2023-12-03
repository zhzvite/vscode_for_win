#include<iostream>
#include<string>
using namespace std;
const int N = 3e5 + 10;
int n, m;
char s[N];
int a[N];
int main(){
    cin >> n >> m ;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                a[i] = 1;
            }
        }
    //预处理
    for (int i = 1; i <= n;i++)
        a[i] = a[i] + a[i-1];
    for (int i = 1; i <= m;i++){
        int l, r;
        cin >> l >> r;
        int cnt = a[r] - a[l - 1];
        if(s[r]==s[r+1])
            cnt--;
        cout << cnt << endl;
    }
    system("pause");
}