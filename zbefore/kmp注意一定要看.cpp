#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];
int main() {
	cin >> n >> p + 1 >> m >> s + 1;//p+1��ָ�ӵ�һλ��ʼ��
	//��next�Ĺ���,ģ�崮
	for (int i = 2, j = 0; i <= n; i++) {//�����ne��i��ָ����ǰ1-i��ɵ�������ǰ׺�ͺ�׺��ͬ�ĳ���
		while (j && p[i] != p[j + 1])j = ne[j];
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}
	
	//kmp ƥ�����
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != p[j + 1])j = ne[j];
		if (s[i] == p[j + 1])j++;
		if (j == n) {
			cout << i - n<<" ";
			j = ne[j];//ƥ��ɹ�
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