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
int n,m,len;
const int N = 70;
bool tt;
bool st[N];
int a[N];
int sum;
int ne[N];
bool cmp(int a,int b){
    return a > b;
}
void dfs(int k,int last,int res){
    int i;
    if(!res){
        if(k==m){
            tt = true;
            return;
        }
        for (i= 1; i <= n;i++){
            if(!st[i])//要是他没用过
                break;
        }
        st[i] = true;
        dfs(k + 1, i, len - a[i]);
        st[i] = false;
        if(tt)return;
    }
    int l = last , r = n+1, mid;
    while(l+1!=r){
        mid = (l + r) >> 1;
        if(a[mid]>res)
            l = mid;
        else
            r = mid;
    }//二分找出第一个小于或等于res的,然后再进行筛选
    for (i = r; i <= n;i++){
        if(!st[i]){
            st[i] = true;
            dfs(k, i, res - a[i]);
            st[i] = false;
            if(tt)return;
        //    if(res==a[i]||res==len)//一种优化要是在这种最优情况下还失败了就是前面的木棍的问题
            //    return;
            i = ne[i];    
        }
    }
    //return;
}
int main(){
    read(n);
    for (int i = 1; i <= n;i++){
        int d;
        read(d);
        if(d>50)
            continue;
        a[i] = d;
        sum += d;
    }
    sort(a + 1, a + n + 1, cmp);//从大到小排序
    ne[n] = n;
    for (int i = n - 1; i > 0;i--){
        if(a[i]==a[i+1])
            ne[i] = ne[i + 1];
            else
            ne[i] = i;//预处理ne,算是剪枝的一种
    }
        for ( len = a[1]; len <= sum / 2; len++)//
        {
            if (sum % len != 0)
                continue;
            m = sum / len; // 木头有多少根
            tt = false;//成功的标记
            st[1] = true;//每次都第一个选第一节
            dfs(1, 1, len - a[1]);
            st[1] = false;
            if (tt)
            {cout << len;
            system("pause");
            return 0;
            }            
    }
    cout << sum;
    return 0;
    }
        
