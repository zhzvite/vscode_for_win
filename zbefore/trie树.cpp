//高效存储和查询字符串集合的数据结构
//通过一颗多分枝的树来高效存储,每一个分支都是一个字符串
#include<iostream>
using namespace  std;
const int N = 100010;
int son[N][26],cnt[N],idx;//下标是0的点,既是空节点,又是根节点
char str[N];//输入字符串
void insert(char str[]) {//输入一整个字符串
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';//将字符串转化成数字
		if (!son[p][u])son[p][u] = ++idx;//idx储存的是当前用到的下标,下标唯一，往里面存储位置
		p = son[p][u];
		//cout << "p=" << p << " ";
	}
	cnt[p]++;//p是标记，类似于终止标记
	//注意这里son[0][]存的是字符串的第一个字母，之后p会++，若该存的位置有被占用了，则会跳过，p自动继承，进行下一次循环
}
//查询的道理和插入基本一致
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main() {
	int n;
	cin >> n;//n为n次操作
	while (n--) {
		char op[2];
		cin >> op;
	//	cout << op[0] << " " << op[1]<<endl;
		cin >> str;
		if (op[0] == 'I')insert(str);//执行插入操作
		else cout << query(str);//执行寻找操作
	}
	
	return 0;
}
/*		
6
I abc
Q abc
Q ab
I ab
Q ab
Q bc
*/