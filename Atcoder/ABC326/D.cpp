#include<iostream>
#include<string>
using namespace std;
const int N = 15;
typedef int long long ll;
int n;
string r, c;
char g[N][N];
char ch[] = {'.', 'A', 'B', 'C'};
int vis1[N][100], vis2[N][100];//vis1表示行,vis2表示列
void dfs(int x,int y){
    for (int i = 0; i <= 3;i++){
        

    }
} 

int main(){
    cin >> n >> r >> c;
    dfs(1, 1);//全部排一遍,在check一遍,要是符合所有条件就输出
    
    system("pause");
} 