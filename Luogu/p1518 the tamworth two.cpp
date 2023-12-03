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
char g[12][12];
int f[3],c[3],ans=0;
int tt;
bool z[1000000];
void move(int x,int y,int mi,int h){//移动函数
	if (mi==0){
		if (g[x-1][y]=='*') if (h==0) f[0]=1; else c[0]=1;
		else if (h==0) f[1]--; else c[1]--;
	}else if (mi==1){
		if (g[x][y+1]=='*') if (h==0) f[0]=2; else c[0]=2;
		else if (h==0) f[2]++; else c[2]++;
	}else if (mi==2){
		if (g[x+1][y]=='*') if (h==0) f[0]=3; else c[0]=3;
		else if (h==0) f[1]++; else c[1]++;
	}else{
		if (g[x][y-1]=='*') if (h==0) f[0]=0; else c[0]=0;
		else if (h==0) f[2]--; else c[2]--;
	}
}
bool pd(){
    if(f[1]==c[1]&&f[2]==c[2])return 0;
    return 1;
}
int main(){
    for(int i=0;i<=11;i++)g[i][0]='*',g[i][11]='*';
    for(int i=1;i<=11;i++)g[0][i]='*',g[11][i]='*';
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>g[i][j];
            if(g[i][j]=='C')c[1]=i,c[2]=j;
            if(g[i][j]=='F')f[1]=i,f[2]=j;
        }
    }
     memset(z,false,sizeof z);
    while(pd()){
      tt=f[1]+f[2]*10+c[1]*100+c[2]*1000+f[0]*10000+c[0]*40000;
      if(z[tt]){
        cout<<0<<endl;
        return 0;
      }
      z[tt]=true;
      move(f[1],f[2],f[0],0);
      move(c[1],c[2],c[0],1);
      ans++;
    }
    cout<<ans;
    
    system("pause");
    return 0;
}
