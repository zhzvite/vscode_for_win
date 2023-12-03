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
int n;
const int N=1e5+10;
int e[N],l[N],r[N],idx;
bool st[N];
void remove(int k) {
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
void add(int k,int x)//在idx为k的右边插入x这个数字
{
    e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}
int main(){
  read(n);
  r[0]=1;
  l[1]=0;
  idx=2;
  //第i号同学的idx=idx-1;
  add(0,1); 
  for(int i=2;i<=n;i++){
        int a,b;
        read(a),read(b);
        if(b==0){
            add(l[a+1],i);
        }
        else add(a+1,i);
  }
  int m;
  read(m);
  while(m--){
    int a;
    read(a);
    if(!st[a+1])remove(a+1);
    st[a+1]=true;
  }
  for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<" ";
  system("pause");
}