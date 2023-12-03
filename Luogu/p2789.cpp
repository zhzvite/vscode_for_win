#include<iostream>
using namespace std;
bool st[100010];
int ans = 0;
void suv(int p,int m){
    if(p==0){
        if(!st[m])//记录交点的出现,出现一次记录一次
            ans++;
        st[m] = true;
    }
    else
        for (int r = p; r >= 1;r--)
            suv(p - r, r * (p - r) + m);
}
int main(){
    int n;
    cin >> n;
    suv(n, 0);
    cout << ans;
}