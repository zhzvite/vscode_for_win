#include<iostream>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if((n+1)%3==0||(n-1)%3==0)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    system("pause");
}