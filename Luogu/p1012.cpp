#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[25];
int n;
bool cmp(string a,string b){
    return a+b > b+a;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    sort(s + 1, s + 1 + n,cmp );
    for (int i = 1; i <= n;i++)
        cout << s[i];
    system("pause");
}