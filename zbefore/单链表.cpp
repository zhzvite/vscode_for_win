//这里努力写个程序实现静态链表（以数组构成链表
//还是要画图理解
#include<iostream>
using namespace std;
const int N = 100010;
//head=头结点
//e【i]表示节点i的值
//ne【i】表示节点i的next指针
//idx表示储存的点的次序
int head, e[N], ne[N], idx;//标准邻接表
//定义4个全局变量
void init() {
	head = -1;
	idx = 0;
}//对head和idx进行初始化
//将x插到头结点
void addhead(int x) {
	//e[idx] = x;//将x存到e【idx】中
	//ne[idx] = head;//
	//head = idx;
	//idx++;	//idx每次都会加加
	e[idx] = x, ne[idx] = head, head = idx++;
}
void addk(int k,int x) {
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}//将x插到k后面，和头插法没什么区别
//将下标是k后面的一个点删掉
void remove(int k) {
	ne[k] = ne[ne[k]];//链表是一个递归，可以理解为ne记录的是下一个数据的idx
}

int main() {
	int t;
	init();//要先将head和idx进行初始化
	int k, x;
	cin >> t;
	while (t--) {
		char op;
		cin >> op;
		if (op == 'H')
		{
			cin >> x;
			addhead(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k)head = ne[head];//第k个插入的点下标是k-1
			remove(k-1);
		}
		else {
			cin >> k>>x;
			addk(k-1, x);

		}
	}for (int i = head; i != -1; i=ne[i])cout << e[i] << " ";
}
/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
*/
//输出 6 4 6 5
