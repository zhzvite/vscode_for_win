#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<ctime>
#include<stack>
using namespace std;
template<typename T>
inline void read(T& x) {
	x = 0;
	bool flg = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')flg = 1;
	for (; isdigit(c); c = getchar())x = x * 10 + (c ^ 48);
	if (flg)x = -x;
}
//本题是将最长公共子序列的题,以条件全排列的性质转化成最长上升子序列,只能说是妙极了
int n;
const int N=1e5+10;
int a[N], q[N],b[N],mapp[N];
int main(){
    read(n);
    for (int i = 1; i <= n;i++)
        {
            read(a[i]);
            mapp[a[i]] = i;}

            for (int i = 1; i <= n; i++)
                read(b[i]);
            int len = 0;
            q[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                int l = -1, r = len + 1;
                while (l + 1 != r)
                {
                    int mid = (l + r) >> 1;
                    if (q[mid] < mapp[b[i]])
                        l = mid;
                    else
                        r = mid;
                }
                len = max(len, l + 1);
                q[l + 1] = mapp[b[i]];

                //cout <<i<<" "<< mapp[b[i]] << endl;
    }
    cout << len;
    system("pause");
}