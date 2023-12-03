#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<ctime>
#include<stack>
using namespace std;
template<typename T>
inline void read(T& x) {
	x = 0;
	bool flg = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')flg = 1;
	for (; isdigit(c); c = getchar())x = x * 10 + (c ^ 48);
	if (flg)x = -x;
}
const int N=1500;
int n,m;
char op[2];
int p[N];
int d[N];
int find(int x){
    if(p[x]!=x)return p[x]=find(p[x]);
    return p[x];
}
void init(int a,int b){
    if(find(a)==find(b))return ;
    p[find(a)]=find(b);
}

int main(){
    read(n),read(m);
    for(int i=1;i<=2*n;i++)p[i]=i;
   for(int i=1;i<=m;i++){
        char op[2];
        int a,b;
        cin>>op;
        read(a),read(b);
        if(op[0]=='E'){
            init(b+n,a);
            init(a+n,b);//反集
        }
        else {
            init(a,b);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i)cnt++;
    }
    cout<<cnt;
    system("pause");
    return 0;
   
}