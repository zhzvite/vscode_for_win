#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define int long long 
int t;
int n;
int cnt = 0;
const int N = 2e5 + 10;
int st[3];
vector<int> m;
map<int, int> mapp;
signed main(){
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        mapp.clear();
        m.clear();
        st[1] = 0;
        st[2] = 0;
        while(n--){
            int a;
            cin >> a;
            mapp[a]++;
            if(a==1||a==2)
            m.push_back(a);
        }
        for(auto tt: mapp)
         if(tt.second>=2){
                for (int i = tt.second - 1; i >= 1;i--)
                    cnt += i;
         }
         for(auto tt: m){
            if(tt==1)
                st[1]++;
            if(tt==2)
                st[2]++;
         }
         if(st[1]>0&&st[2]>0)
         cnt += st[1] * st[2];
         cout << cnt << endl;
    }
    system("pause");
}
