#include<iostream>
using namespace std;
typedef long long int ll;
ll tt, a, b;
int main(){
    bool flag = false;
    cin>>tt;
    while(tt--){
        cin >> a >> b;
        int t = 0; 
           flag = true;
        while(a>0||b>0){
            int c = (a & 1);
            int d = (b & 1);
            if(t==0){
                if(c==0&&d==1)
                    t++;
                if(c==1&&d==1)
                {
                    flag = false;
                    break;
                }

            }
            else if(t==1){
              if(c==0&&d==1){
                    flag = false;
                    t = 0;
                    break;
              }
              if(c==1&&d==0)
                    t = 0;
              if(c==1&&d==1)
                    t = 1;
              if(c==0&&d==0)
                    t = 1;
            } 
            a /= 2;
            b /= 2;
        }
        if(flag==false || t)
            cout << "NO";
        //if(t==1)
        //    cout << "NO";
        else
            cout << "YES";
        cout << endl;
    
    }
    system("pause");
}