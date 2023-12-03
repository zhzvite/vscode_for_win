//优化版本时间复杂度(nlogn)
#include<iostream>
using namespace std;
int n;
const int N=210;
int a[N],q[N];//q负责记录每个长度的尾元素的最小值
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int len=0;
    q[0]=0;
    for(int i=0;i<n;i++){
        int l=-1,r=len+1;
        while(l+1!=r){
            int mid=(l+r)>>1;
            if(q[mid]<a[i])l=mid;//找到小于a[i]的最大f值,f是严格单调递增的
            else r=mid;
        }
        len=max(len,l+1);//如果可以更新,则长度加一
        q[l+1]=a[i];//将新的元素接到后面
    }
    cout<<len;
    system("pause");
}