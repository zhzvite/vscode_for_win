#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s;
int main(){
    cin >> n;
    cin >> s;
    bool flag = false;
    for (int i = 1; i <n;i++){
        if(s[i]=='a'&&s[i-1]=='b')
            {
                flag = true;
                break;
            }

        if(s[i]=='b'&&s[i-1]=='a'){
            flag = true;
            break;
        }    
    }
    if(flag)
            cout << "Yes";
            else
            cout << "No";
            system("pause");
            return 0;
}