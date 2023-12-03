#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int cnt = 1;
bool cmp(int a,int b){
    return a < b;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 2; i <= n; i++)
    {
        if(a[i]!=a[i-1])
            break;
        else
            cnt++;
    }
    cout << cnt;
    system("pause");
}