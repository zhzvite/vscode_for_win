//13:35
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
int tt;
int main(){
    cin>>tt;
    switch(tt){
        case 1:{
        cout << "I love Luogu!";
        break;
        }
        case 2:{
        cout << 6 << " " << 4;
        break;
        }
        case 3:{
        cout << "3"<< endl << 12<< endl << 2 << endl;
        break;}
        case 4:
        cout << fixed << setprecision(3) << 500.0 / 3.0;
        break;
        case 5:
        cout << (int )((260 + 220) / 32);
        break;
        case 6:
        cout << pow(36 + 81, 0.5);
        break;
        case 7:
        cout<<110<<endl<<90<<endl<<0<<endl;
        break;
        case 8:{
        double pi = 3.141593;
        int r = 5;
        double c = pi * 2 * r;
        double s = pi * r * r;
        double v = pi * r * r * r * 4.0 / 3.0;
        cout << c << endl
             << s << endl
             << v << endl;
        break;}
        case 9:
        cout << 22;
        break;
        case 10:
        cout<<9;
        break;
        case 11:
        cout<<100.0/3<<endl;
        break;
        case 12:{
        cout << 'M' - 'A' + 1;
        cout << endl;
        cout << (char)('A' +17);}
        break;
        case 13:{
         double pi = 3.141593;
         double v = pi * (64 + 1000) * 4.0 / 3.0;
        cout << floor(pow(v,1.0/3));
        break;}
        case 14:{
        cout << 50;
        break;}
        
    }
        system("pause");
}