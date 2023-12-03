#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin>>a>>b;
    if(a>b){
        if((a-b)<=3)
            cout << "Yes";
        else
            cout << "No";
    }
    if(a<=b){
        if((b-a)<=2)
            cout << "Yes";
            else
            cout << "No";
    }
    system("pause");
}