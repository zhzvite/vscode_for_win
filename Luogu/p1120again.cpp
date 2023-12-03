#include<iostream>
#include<algorithm>
using namespace std;
const int N = 70;
int a[N], ne[N];
int sum=0, res,n,len,m;
bool flag;
bool st[N];
bool cmp(int a,int b){
    return a > b;
}
void dfs(int k,int last ,int res){
    int i;
    if (!res)
    {
        if (k == m)
        {
            flag = true;
            return;
        }
        // 可以拼下一节
        for ( i = 1; i <= n; i++)
            if (!st[i])
                break;
        st[i] = true;
        dfs(k + 1, i, len - a[i]);
        st[i] = false;
        if(flag)
            return;
   }
   //拼剩下的
   int l = last, r = n + 1, mid;
   while(l+1!=r){
        mid = (l + r) >> 1;
        if(a[mid]>res)
            l = mid;
        else
            r = mid;        
   }
   for (i = r; i <= n;i++){
        if (st[i])
            continue;
        st[i] = true;
        dfs(k, i, res - a[i]);
        st[i] = false;
        if(flag)
            return;
        if(res==a[i]||res==len)
            return;
        i = ne[i];
   }
}
int main(){
    cin >> n;
    for (int i = 1; i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    //预处理ne
    sort(a + 1, a + 1 + n, cmp);
    ne[n] = n;
    for (int i = n - 1; i >= 1;i--){
        if(a[i]==a[i+1])ne[i]=ne[i+1];
        else
            ne[i] = i;
    }
    for (len = a[1]; len <= sum / 2; len++){
        if(sum%len!=0)
            continue;
        m = sum / len;
        flag = false;
        st[1] = true;
        dfs(1, 1, len - a[1]);
        st[1] = false;
        if(flag)
            {cout << len;
            system("pause");
            return 0;
            }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}