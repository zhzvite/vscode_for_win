
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
const int N=310;
int a[N],s[N],dpm[N][N],dpn[N][N],n;
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++)
        s[i]=s[i-1]+a[i];//初始化}
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int l=i,r=i+len-1;
            dpm[l][r]=0;
            dpn[l][r]=1e8;
            for(int k=i;k<r;k++){//注意k的起始点
                dpm[l][r]=max(dpm[l][r],dpm[l][k]+dpm[k+1][r]+s[r]-s[l-1]);
                dpn[l][r]=min(dpn[l][r],dpn[l][k]+dpn[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    int rm=0;
    int rn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        rm=max(rm,dpm[i][i+n-1]);
        rn=min(rn,dpn[i][i+n-1]);

    } 
    cout<<rn<<endl;
     cout<<rm<<endl;
    system("pause");
}