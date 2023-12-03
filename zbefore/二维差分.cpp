//不想作一维差分了就，两个差分的重点都是，插入
//要有开始，要有结尾
#include<iostream>
using namespace std;
const int N = 10010;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;//这是一个重要的预处理步骤
	//不仅在前面完成了b数组的初始化，并且在插入过程中完成的b的增值
	//想理解建议画图辅助

}
int main() {
	int n, m,q, x1, x2, y1, y2,c;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		
	}//初始化a数组
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			insert( i,  j,  i,  j, a[i][j]);//先遍历一遍数组b，进行插入,使得b是a的差分
		}
	}
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
		//再求b的前缀和
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//求数组b的前缀和
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];//因为我们
			//最后要求的是加完了c后的a数组，而b的前缀和是a数组，所以我们直接算出b的前缀和就行
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << b[i][j] << " ";
		}cout << endl;
	}

}