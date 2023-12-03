#include<iostream>
using namespace std;
const int n = 1e5 + 10;
long long int a[n];
long long int N;
void quick_sort(long long int a[], int l, int r) {
	int x = a[(r+l)/2];
	int i = l-1;
	int j = r+1 ;
	if (l >= r)return;
	while (i <j) {
	//	cout << i << " " << j << endl;
		do i++; while (a[i] < x);
		do j--; while (a[j] > x);//一定要记住这个do while他和while 不一样，写while会死，直接咋-1死掉
		if (i < j) {
			swap(a[i], a[j]);
		}
	}quick_sort(a, l, j);
	quick_sort(a, j+1, r);
    
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> a[i];
	quick_sort(a, 0,N-1 );
	  for (int i = 0; i <N ; i++)cout << a[i]<<" ";

}