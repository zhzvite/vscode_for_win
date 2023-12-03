#include<iostream>
using namespace std;
int n,m;
const int N = 3e5 + 10;
int a[N];
int main(){
    cin >> m;
    while(m--)
    {
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int ans = n;
    int cnt = 0;
    for (int i = ans; i > 0;i--){
       if(a[i]==n)
           n--;
    }
    cout << n<<endl;
}
    
    system("pause");
}