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
const int N=10;
double pi = 3.1415926535;
typedef pair<int, int> pii;
int x[10], y[10];
double r[N],ansmax;
bool st[N];
int n;
int stx, sty, edx, edy;
double cal(int k){
    double s = min(min(abs(x[k] - stx), abs(x[k] - edx)),min(abs(y[k]-sty),abs(y[k]-edy)));
    for (int i = 1; i <= n;i++)
    if(k!=i&&st[i]){
            double d = sqrt(pow(x[k] - x[i], 2) + pow(y[k] - y[i], 2));
            s = min(s, max(d - r[i], 0.0));
    }
    return s;
}
void dfs(int k,double sum){
   if(k>n){
        ansmax = max(ansmax, (double)sum);
        return;
   }
   for (int i = 1; i <= n;i++){
    if(!st[i]){
            r[i] = cal(i);
            st[i] = true;
            dfs(k + 1, sum + (pi * r[i] * r[i]));
            st[i] = false;
    }
   }
}
int main(){
    double sss;
    read(n), read(stx), read(sty), read(edx), 
    read(edy);
    sss = abs(stx - edx) * abs(sty- edy);
    for (int i = 1; i <= n;i++)
        read(x[i]), read(y[i]);
    //想随便挑一个点开始搜索
    //计算所有的面积,感觉要设一个数组存每个点之间的距离
    dfs(1, 0);
    cout << (int)(sss - ansmax+0.5);//注意double转成int默认是向下取整,然后我们用ceil是向上取整,为了造出四舍五入的效果,采取+0.5然后强制转int的方案.
    system("pause");
}
