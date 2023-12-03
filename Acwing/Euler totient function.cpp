//求出给定数字的欧拉函数,但要求前n个数的欧拉函数则比较慢
#include<iostream>
using namespace std;
int main(){
    int n,res,a;
    cin>>n;
    while(n--){
        cin>>a;
        res=a;
        for(int i=2;i<=a/i;i++){
            if(a%i==0){
                res=res/i*(i-1);
                while(a%i==0)a/=i;
            }
        }   if(a>1)res=res/a*(a-1);
            cout<<res<<endl;
    }
    system("pause");
    return 0;
}