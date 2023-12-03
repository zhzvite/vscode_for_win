#include<iostream>

#include<algorithm>
using namespace std;
int n, x, sum;
int a[15];
bool cmp(int a,int b){
    return a < b;
}
int main(){

    cin >> n >> x;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < n;i++){
        if(a[i]<=x)
            sum += a[i];
    }
    cout << sum;
    system("pause");
}