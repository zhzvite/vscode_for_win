#include<iostream>
using namespace std;
bool check(int x){
    int a = x / 100;
    int b = (x / 10) % 10;
    int c = x % 10;
    if((a*b)==c)
        return true;
    else
        return false;
}
int main(){
    int x;
    cin >> x;
    for (int i = x;;i++){
        
        if(check(i)){
            cout << i;
            break;
        }
    }
    //system("pause");
}