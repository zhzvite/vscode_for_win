#include<iostream>
using namespace std;
int t;
int n;
const int N = 2e5 + 10;
int a[N];
int minn;
int st;
int main(){
    cin >> t;
    while(t--){
        minn = 0x3f3f3f3f;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            if(minn>a[i]){
                minn = a[i];
                st = i;
            }
        }
        bool flag = true;
        for (int i = st+1; i <= n;i++){
            if(a[i]<a[i-1])
                flag = false;
        }
        if(flag)
            cout << st - 1 << endl;
        else
            cout << "-1" << endl;
    }
    system("pause");
}