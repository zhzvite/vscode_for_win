#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int t, n, k,cc;
int main(){
    cin>>t;
    while(t--){
        cin >> n>>k;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        if(k==4){
            int cnt = 0;
            int s = 0;
            for (int i = 1; i <= n;i++){
                if(a[i]!=0)
                    cc++;
                if(a[i]==3||a[i]==7)
                    s++;
                while(a[i]%2==0&&a[i]!=0){
                    cnt++;
                    a[i] /= 2;
                }
                
            }
            if(cnt>=2)
                cout << "0" << endl;
            else {
                if(cnt==1&&cc>=2)
                cout << "1"<<endl;
                else {
                    if(s>=1)
                        cout << "1"<<endl;
                        else
                        cout << 2 << endl;
                  }
                
                }
               
        }    
        else {int minn = 0x3f3f3f3f;
                for (int i = 1; i <= n;i++){
                int t = (a[i] + k - 1) / k * k;
                minn = min(minn, abs(t - a[i]));
                }
                cout << minn << endl;
        }
        
        
    }
    //system("pause");
}