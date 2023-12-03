#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int g[10][10];
int st[10][10];
int vis[10];
int main(){
    for (int i = 1; i <= 9;i++){
        for (int j = 1; j <= 9;j++){
            cin >> g[i][j];
            vis[g[i][j]]++;
        }
    }
    for (int i = 1; i <= 9;i++)if(vis[i]!=9){
            cout << "No" << endl;
            return 0;
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 9;i++){
    memset(vis, 0, sizeof vis);
    for (int j = 1; j <= 9;j++){
        if(vis[g[i][j]]!=0){
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }

    for (int j = 1; j <= 9; j++)
    {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 9; i++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }



    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 3;i++){
    for (int j = 1; j <= 3;j++){
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 3; i++)
    {
    for (int j = 4; j <= 6; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 3; i++)
    {
    for (int j = 7; j <= 9; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 4; i <= 6; i++)
    {
    for (int j = 1; j <= 3; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 4; i <= 6; i++)
    {
    for (int j = 4; j <= 6; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 4; i <= 6; i++)
    {
    for (int j = 7; j <= 9; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 7; i <= 9; i++)
    {
    for (int j = 1; j <= 3; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
        //    system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 7; i <= 9; i++)
    {
    for (int j = 4; j <= 6; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
            system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 7; i <= 9; i++)
    {
    for (int j = 7; j <= 9; j++)
    {
        if (vis[g[i][j]] != 0)
        {
            cout << "No";
            system("pause");
            return 0;
        }
        vis[g[i][j]]++;
    }
    }
    cout << "Yes";
}