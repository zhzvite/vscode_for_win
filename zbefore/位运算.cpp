//这里重点记录以下位运算的基本和应用
#include<iostream>
using namespace std;
int lowbit(int x) {
     return x & (-x);
}//巧妙的利用了源码和补码的性质，返回x的二进制最后以一结尾的一串二进制码

int main()
{
	int x;
//	x=10;
//	for (int i = 0; i < 4; i++) {
//	cout << (x << i)<<endl;
//	}
	int n;
	cin >> n;
	while (n--) {
		cin >> x;
		int res = 0;
		while (x) {
			x -= lowbit(x);
			res++;
		}
		cout << res << " ";//利用此段程序，算出录入的每个数字的二进制一有多少个
	}
}