#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int t;
int k;
int sum;
int main(){
    cin >> t;
    while(t--){
        cin >> n>>k;
        cin >> s;
        sum = 0;
        for (int i = 0; i < s.size();i++)if(s[i]=='B')
                sum += 1;

        int i = 0;
        bool flag = false;
        if(sum<k){
            int m = k - sum;
            i = 0;
            while(m>0){
             if(s[i]=='A')
                 m--;
             i++;
            }
            flag = false;
        }
        else if(sum>k){
            int m = sum- k;
             i = 0;
            while(m>0){
                if(s[i]=='B')
                    m--;
                i++;
            }
            flag = true;
        }
        if(i==0)
            cout << 0 << endl;
        else {
            cout << 1 << endl;
            cout << i<<" ";
            if(flag)
                cout << "A" << endl;
              else
                  cout << "B" << endl;
        }
    }
    system("pause");
}