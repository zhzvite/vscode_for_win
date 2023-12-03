#include<iostream>
#include<string>
using namespace std;
int t;
int n;
string s;
int cnt, res,m;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        res = 0;
        cnt = 0;
        m = 0;
        for (int i = 0; i < n;i++){
            if(s[i]=='#')
            {    cnt = 0;
                m++;
            }
            else
                cnt++;
            res = max(cnt, res);
        }
        if(res>=3)
            cout << 2 << endl;
        else
            cout << n - m << endl;

    }
    system("pause");
}
