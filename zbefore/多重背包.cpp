//多重背包问题，多重背包是单重背包的变式，同时是完全背包问题加了部分约束
//这里是暴力做法加上一点维数优化
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e4+10;
int a[N], b[N], s[N];
int f[N];//这是对二维的优化
int n, x,sum;

int main() {
	cin >> n >> x ;
	f[0] = 1;
	for (int i = 1; i <= n; i++)cin >> a[i] >> b[i];//将a[i],b[i]输入
	for (int i = 1; i <= n; i++) {
		for (int j = x; j >= 0;j--) {
			for (int k = 1; k <= b[i]; k++) {
				if (k * a[i] <= j)
				{
               f[j] =max( f[j],f[j - k * a[i]]);		 
				}		
			}
		}
	}
	if (f[x])cout << "Yes";
	else cout << "No";
}
//优化思路，例如有s=200，可以把他降成多个2的几次幂和加上一个差的数，从而将较大的数转化成要不要选较少的几个选项及01背包变式
//及二进制优化