#include<iostream>
#include<string>
#include<map>
#include<cmath>
using namespace std;
int n, m, k;
string s;
const int N = 1e5 + 10;
int a[N];
map<char, int> mapp;
int main(){
    cin >> n;
    while(n--){
        mapp.clear();
        cin >> m >> k >> s;
        for (int i = 0; i < s.size();i++){
            mapp[char (s[i])]++;
        }
        int cnt = 0;
        for(auto t:mapp){
            cnt++;
            a[cnt] = t.second;
        }
        int sum = 0;
        bool flag = false;
        for (int i = 1; i <= cnt;i++){
            if(a[i]&1)
                sum++;
        //    cout << a[i] << endl;
        }

            if (sum == 1)
                cout << "Yes" << endl;
            else
            {
                k = k - (sum - 1);
                if (k >= 0 && k < (m - (sum - 1)))
                {cout << "Yes"<<endl;}
            else
                cout << "No"<<endl;
        }
    }
    system("pause");
}