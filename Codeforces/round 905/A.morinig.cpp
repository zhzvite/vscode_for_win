#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b, c, d;
        a = n / 1000;
        b = (n / 100) % 10;
        c = (n / 10) % 10;
        d = n % 10;
        //cout << a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if (a == 0)
            a = 10;
        if(b==0)
            b = 10;
        if(c==0)
            c = 10;
        if(d==0)
            d = 10;
        cout << abs(b - a) + abs(b - c) + abs(c - d) + 4 +abs(a-1)<< endl;
        
    }
    system("pause");
}