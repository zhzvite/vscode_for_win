#include<iostream>
#include<map>
using namespace std;
typedef pair<int, int> pii;
int n, m, k;
map<pii, int> mapp;
int main(){
    cin >> n >> m >> k;
    while(m--){
        int x, y;
        cin >> x >> y;
        mapp[make_pair(x, y)]++;

    }
    while(k--){
        int x, y;
        cin >> x >> y;
        mapp[make_pair(x, y)]--;
    }
    int ans = 0;
    for(auto w:mapp){
        if((w.second)>0)
            ans++;
    }
    cout << ans;
    system("pause");
}