#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N=3e5 + 10;
int a[N];
int m;
int res=1;
bool cmp(int a,int b){
    return a < b;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n;i++){
        int l, r, mid;
        int flag = a[i] + m;
        l = i - 1, r = n + 1;
        if(a[n]<a[1]+m){
            cout << n << endl;
            return 0;
        }
        while(l+1!=r){
            mid = (l + r) / 2;
            if(a[mid]<flag)l=mid;
            else
                r = mid;
        }
        res = max(res, l - i + 1);
    }
    cout << res << endl;
    system("pause");
}
