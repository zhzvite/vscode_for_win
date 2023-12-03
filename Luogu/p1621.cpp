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
const int N=1e5+10;
int ans=0;
int a,b,q;
int p[N];
int cnt=0;
bool st[N];
int pr[N];
//筛素数
void get_primes(int n) {//线性筛
	for ( int i = 2; i <= n; i++) {
		if (!st[i])pr[cnt++] = i;
		for (int j = 0; pr[j] <= n / i; j++) {
			st[pr[j] * i] = true;
			if (i % pr[j] == 0)break;//p[j]一定是i的最小质因子
		}
	}
}
int find(int x){
    if(p[x]!=x)return p[x]=find(p[x]);
    return  p[x];
}

int main(){
   read(a),read(b),read(q);
    get_primes(b);//找到质数,小于b的质数
   for(int i=a;i<=b;i++)p[i]=i;
   for(int i=0;i<cnt;i++){
    if(pr[i]<q)continue;
    int cc=0;
    while(cc*pr[i]<a)cc++;
    while(pr[i]*(cc+1)<=b){
        p[find(cc*pr[i])]=find((cc+1)*pr[i]);
        cc++;
    }
   }
   for(int i=1;i<=b;i++){
    if(p[i]==i)ans++;
   }
   cout<<ans<<endl;
   system("pause");
   return 0;

}