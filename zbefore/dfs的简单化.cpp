
/*
//��ѧϰ�����дdfs�����������(�ݹ�
�� n ����Ʒ��ÿ����Ʒ������Ϊ w[i] ����ֵΪ c[i] ��
������Ҫѡ�����ɼ���Ʒ����һ������Ϊ V �ı����У�ʹ����ѡ�뱳������Ʒ
�����Ͳ��������� V ��ǰ���£��ñ�������Ʒ�ļ�ֵ֮�����������ֵ����1��n��20��
//˼·����,ȷ����·�ں�����ͬ�ֱ�Ϊѡ�벻ѡ�ͳ�������
#include<iostream>
using namespace std;
const int maxn = 30;
int w[maxn], c[maxn],n,maxvalue=0,v;
void dfs(int idx, int sumw, int sumc)//idx��ʾ��Ʒ���
{
	if (idx == n) {
		if (sumw<=v && sumc>maxvalue)maxvalue = sumc;//���ֵݹ��ر��,û�л��ݲ������һ��һ������
		return;
	}
	dfs(idx+1, sumw, sumc);
	dfs(idx+1, sumw + w[idx], sumc + c[idx]);//����ö�٣�ö�����еĿ���
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

/*//ȫ��������
#include<iostream>
using namespace std;
const int  N = 10;
int n;
int p[N];
bool st[N];
void dfs(int u) {
	if (u == n)//�������ˣ�ײǽ�����
	{
		for (int i = 0; i < n; i++)cout << p[i] << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			p[u] = i;
			st[i] = true;//����ǣ���ֹ��������
			dfs(u + 1);//��������
			st[i] = false;//�ӵݹ��л���Ҫ�ָ�,������
		}
	}
	}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}
*/
//n�ʺ�����
//Ҳ�Ǽ򵥵�dfs
#include<iostream>
using namespace std;
const int N = 20;
int n;
char gg[N][N];
bool col[N], dg[N], udg[N];//col��ʾ�У�dg��ʾ�Խ��ߣ�udg��ʾ���Խ���
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)cout << gg[i][j] << " ";//ײǽ���
			cout << endl;
		}cout << endl;
		return;
	}
		for (int i = 0; i < n; i++) {//ÿһ�зֱ�ö��,�����
			if (!col[i] && !dg[u + i] && !udg[n - u + i]) {//��������
				gg[u][i] = 'Q';
				col[i] = dg[u + i] = udg[n - u + i] = true;
				dfs(u + 1);
				gg[u][i] = '.';//����
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
//�����Ǹ�Ϊԭʼ��������ʽ������
#include<iostream>
using namespace std;
const int N = 20;
int n;
char gg[N][N];
bool row[N],col[N], dg[N], udg[N];//col��ʾ�У�dg��ʾ�Խ��ߣ�udg��ʾ���Խ���
void dfs(int x,int y,int s) {//x��ʾ����������y��ʾ�����������������˹�����������
	if (y == n)y = 0, x++;
	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i++)puts(gg[i]);
			puts("");
		}
		return;
	}
	//���Żʺ�
	dfs(x, y + 1, s);
	//�Żʺ�
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
