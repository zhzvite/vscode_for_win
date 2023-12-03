#include<iostream>
using namespace std;
int n;
int a[110];
int cnt = 0;
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            if (i <= 9)
            {
                if (i <= a[i])
                    cnt++;
                if ((i * 10 + i) <= a[i])
                    cnt++;
            }
            if (i == 11)
            {
                if (i <= a[i])
                    cnt++;
                if (1 <= a[i])
                    cnt++;
            }
            if (i == 22)
            {
                if (i <= a[i])
                    cnt++;
                if (2 <= a[i])
                    cnt++;
            }
            if (i == 33)
            {
                if (i <= a[i])
                    cnt++;
                if (3 <= a[i])
                    cnt++;
            }
            if (i == 44)
            {
                if (i <= a[i])
                    cnt++;
                if (4 <= a[i])
                    cnt++;
            }
            if (i == 55)
            {
                if (i <= a[i])
                    cnt++;
                if (5 <= a[i])
                    cnt++;
            }
            if (i == 66)
            {
                if (i <= a[i])
                    cnt++;
                if (6 <= a[i])
                    cnt++;
            }
            if (i == 77)
            {
                if (i <= a[i])
                    cnt++;
                if (7 <= a[i])
                    cnt++;
            }
            if (i == 88)
            {
                if (i <= a[i])
                    cnt++;
                if (8 <= a[i])
                    cnt++;
            }
            if (i == 99)
            {
                if (i <= a[i])
                    cnt++;
                if (9 <= a[i])
                    cnt++;
            }
        }
    cout << cnt << endl;
    system("pause");
}