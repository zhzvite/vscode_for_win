#include<iostream>
using namespace std;
int t;
int a, b, c;
bool flag1, flag2, flag3;
int main(){
    cin>>t;
    while(t--){
        cin >> a >> b >> c;

        flag1 = flag2 = flag3 = false;
        //
        if ((b % 2 == 0 && c % 2 == 0) || (b % 2 == 1 && c % 2 == 1))
            flag1 = true;
         if ((a % 2 == 0 && c % 2 == 0) || (a % 2 == 1 && c % 2 == 1))
             flag2 = true;
         if ((a % 2 == 0 && b % 2 == 0) || (b % 2 == 1 && a % 2 == 1))
             flag3 = true;
         cout << flag1 << " " << flag2 << " " << flag3 << endl;
    }
    system("pause");
}