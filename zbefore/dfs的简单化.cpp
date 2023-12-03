
/*
//简单学习下如何写dfs深度优先搜索(递归
有 n 件物品，每件物品的重量为 w[i] ，价值为 c[i] 。
现在需要选出若干件物品放入一个容量为 V 的背包中，使得在选入背包的物品
重量和不超过容量 V 的前提下，让背包中物品的价值之和最大，求最大价值。（1≤n≤20）
//思路分析,确定岔路口和死胡同分别为选与不选和超过条件
#include<iostream>
using namespace std;
const int maxn = 30;
int w[maxn], c[maxn],n,maxvalue=0,v;
void dfs(int idx, int sumw, int sumc)//idx表示物品编号
{
	if (idx == n) {
		if (sumw<=v && sumc>maxvalue)maxvalue = sumc;//这种递归特别简单,没有回溯步骤就是一步一部遍历
		return;
	}
	dfs(idx+1, sumw, sumc);
	dfs(idx+1, sumw + w[idx], sumc + c[idx]);//暴力枚举，枚举所有的可能
}
int main() {
	cin >> n>>v;
	for (int i = 0; i < n; i++)cin >> w[i];
	for (int i = 0; i < n; i++)cin >> c[i];
	dfs(0, 0, 0);
	cout << maxvalue << endl;
}

5 8
3 5 1 2 2
4 5 2 1 3

*/

/*//全排列问题
#include<iostream>
using namespace std;
const int  N = 10;
int n;
int p[N];
bool st[N];
void dfs(int u) {
	if (u == n)//即跑完了，撞墙了输出
	{
		for (int i = 0; i < n; i++)cout << p[i] << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			p[u] = i;
			st[i] = true;//做标记，防止后面再用
			dfs(u + 1);//往后搜索
			st[i] = false;//从递归中回来要恢复,即回溯
		}
	}
	}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}
*/
//n皇后问题
//也是简单的dfs
#include<iostream>
using namespace std;
const int N = 20;
int n;
char gg[N][N];
bool col[N], dg[N], udg[N];//col表示列，dg表示对角线，udg表示副对角线
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)cout << gg[i][j] << " ";//撞墙输出
			cout << endl;
		}cout << endl;
		return;
	}
		for (int i = 0; i < n; i++) {//每一列分别枚举,即穷举
			if (!col[i] && !dg[u + i] && !udg[n - u + i]) {//挨个遍历
				gg[u][i] = 'Q';
				col[i] = dg[u + i] = udg[n - u + i] = true;
				dfs(u + 1);
				gg[u][i] = '.';//回溯
				col[i] = dg[u + i] = udg[n - u + i] =false;
			}
	     }
	}
int main() {
	cin >> n;
	//cout << n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)gg[i][j] = '.';
	}
	dfs(0);
	return 0;
/*
//下面是更为原始的搜索方式，更慢
#include<iostream>
using namespace std;
const int N = 20;
int n;
char gg[N][N];
bool row[N],col[N], dg[N], udg[N];//col表示列，dg表示对角线，udg表示副对角线
void dfs(int x,int y,int s) {//x表示按行搜索，y表示按列搜索，搜索完了归零重置跳行
	if (y == n)y = 0, x++;
	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i++)puts(gg[i]);
			puts("");
		}
		return;
	}
	//不放皇后
	dfs(x, y + 1, s);
	//放皇后
	if (!row[x] && !col[y] && !dg[x + y] && !udg[n - y + x]) {
		gg[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[n - y + x] = true;
		dfs(x, y + 1, s + 1);
		gg[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[n - y + x] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)gg[i][j] = '.';
	}
	dfs(0,0,0);
	return 0;

}

	*/

}
