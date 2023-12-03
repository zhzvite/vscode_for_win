#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];
int main() {
	cin >> n >> p + 1 >> m >> s + 1;//p+1是指从第一位开始存
	//求next的过程,模板串
	for (int i = 2, j = 0; i <= n; i++) {//这里的ne【i】指的是前1-i项构成的序列中前缀和后缀相同的长度
		while (j && p[i] != p[j + 1])j = ne[j];
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}
	
	//kmp 匹配过程
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != p[j + 1])j = ne[j];
		if (s[i] == p[j + 1])j++;
		if (j == n) {
			cout << i - n<<" ";
			j = ne[j];//匹配成功
		}
	}
	return 0;
}
/*
3
aba
5 
ababa
*/
/*
0 2
*/												