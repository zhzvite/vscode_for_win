#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int get(vector<int> num,int l,int r){
    int res = 0;
    for (int i = l; i >= r;i--)
        res = res * 10 + num[i];
        return res;
        //返回第l到r之间位数的数字
    
}
int power10(int x){
    int res = 1;
    while(x--)
        res *= 10;
    return res;
    //算10的x次方
}
int count(int n,int x){
    if(!n)
        return 0;
    vector<int> num;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    int res = 0;
    for (int i = n - 1 - !x; i >= 0;i--){//要是是数0的位数,那首位肯定没有0
        if(i<n-1)//防止首位
        {
            res += (get(num, n - 1, i + 1)-(!x)) * power10(i);//特判一下0的情况
        }
        if(num[i]==x)
            res += get(num, i - 1, 0) + 1;
            else if(num[i]>x)
            res += power10(i);

    }
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b,a||b){
        if(a>b)
            swap(a, b);
        for (int i = 0; i <= 9;i++)
            cout << count(b, i) - count(a - 1, i) << " ";
        cout << endl;
    }
    system("pause");
}
/*
1 10
44 497
346 542
1199 1748
1496 1403

*/