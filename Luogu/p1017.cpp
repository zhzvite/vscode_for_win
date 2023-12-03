#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <stack>
using namespace std;
template <typename T>
inline void read(T &x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            flg = 1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    if (flg)
        x = -x;
}
int  s;
int n;
int t;
const int N = 1e5 + 10;
int c[N];
void turn(int n){
    if(n==0)
        return;
    int m = n % t;
    if(m<0)
        m = m - t, n = n + t;
    if(m>=10)
        m += 'A' - 10;
    else
        m += '0';
    turn(n / t);
    cout<<(char)m;
    return;
}
int main(){
    cin >> s;
    cin >> t;
    cout << s << "=";
    turn(s);
    cout << "(base" << t << ")";

    system("pause");
}
