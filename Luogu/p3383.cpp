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
int n, q;
const int N = 1e8+3;

bool st[N];
int p[1000010];
int cnt = 0;
void get_primes(int n)
{ // 线性筛
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            p[cnt++] = i;
        for (int j = 0; p[j] <= n / i; j++)
        {
            st[p[j] * i] = true;
            if (i % p[j] == 0)
                break; // p[j]一定是i的最小质因子
        }
    }
}
int main(){
    read(n);
    read(q);
    get_primes(n);
    //二分查找素数
    while(q--){
        int a;
        read(a);
        cout <<p[a - 1] << endl;
    }
    
    
    
    system("pause");
}