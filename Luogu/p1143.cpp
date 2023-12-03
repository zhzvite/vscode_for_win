#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n, m;
string s;
int ans = 1;
int sum;
int g = 0;
int c[10000010];

int main(){
    cin >> n >> s >> m;
    //将一个进制下的数转换成另外一个进制
    //先将其转化成10进制
    for (int i = 0; i < s.size();i++){
        if(s[i]<'A'){
             ans = pow(n, s.size() - 1 - i);
             ans *= (s[i] - '0');
             sum += ans;
        }
        else {
             ans = pow(n, s.size() - 1 - i);
             ans *= (s[i] - 'A' + 10);
             sum += ans;
        }
    }
    while(sum>0){
        c[g] = sum % m;
        g++;
        sum /= m;
    }
    for (int i = g - 1; i >= 0;i--){
        if(c[i]>=10)
             cout <<char( c[i] + 'A' - 10);
        else
             cout << c[i];
    }
    system("pause");

}