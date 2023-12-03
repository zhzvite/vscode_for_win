//最长下降子序列,要采取(n^log n的做法
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int p[N];
bool st[N];
int cnt = 0;
int len = 0;
int main(){
    int d;
    while(cin>>d){
        cnt++;
        a[cnt] = d;
    }
    int n = cnt;
    p[0] = 0;
    
    for (int i = 1; i <= n;i++){
        int l = 0, r = len + 1;
        while (l + 1 != r)
        {
            int mid = (l + r) >> 1;
            if (p[mid]<a[i])
                r = mid;
                else
                l = mid;
        }
        if(st[i])
                continue;
        len = max(len,  l+ 1);
        p[l + 1] = a[i];
        st[i] = true;
    }
    cout << len;
    // 最长上升子序列长度
    // 优化版本时间复杂度(nlogn)
         len = 0;
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n; i++)
        {
                int l = 0, r = len + 1;
                while (l + 1 != r)
                {
                int mid = (l + r) >> 1;
                if (p[mid] < a[i])
                    l = mid; // 找到小于a[i]的最大f值,f是严格单调递增的
                else
                    r = mid;
                }
                len = max(len, l + 1); // 如果可以更新,则长度加一
                p[l + 1] = a[i];       // 将新的元素接到后面
        }
        cout << endl;
        cout << len;
        system("pause");
    }

