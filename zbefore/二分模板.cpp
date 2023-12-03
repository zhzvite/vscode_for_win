//写一个二分查找
//思路输入数组大小进行排序后，找到第一个大于或者等于他的数
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N],k;
//依靠递归实现二分

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, less<int>());//进行升序排序
	sort(a, a + n, greater<int>());//降序排序
	//	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cin >> k;
	int i = -1, j = n;//这是重点,把起点放在数组外面
	if (i + 1 == j){
		cout << " false" << endl; return 0;
      }

	if (k<a[0] || k>a[n - 1]) {
		cout << " out" << endl;
		return 0;//判断极端情况
	}
	while (i+1!=j) {
		int x = (i + j) / 2;
		//	cout << i << " " << j;
		if (k <= a[x])j = x;//这些不等关系要依据条件,根据红区蓝区来分析
		if (k > a[x])i = x;
	}
	cout << j;
}