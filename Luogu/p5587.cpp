#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <stack>
using namespace std;
long long int  n=0, m=0, t;
long long int  cnt=0;
const int N = 1e4 + 10;
string s1[N],s2[N],s;
int main(){
    while (getline(cin, s) , s != "EOF")
    {
        n++;
        for (char i : s)
        {
            if (i == '<'){if(!s1[n].empty())
              s1[n].pop_back();}
            else
              s1[n].push_back(i);
         }
     }
    while(getline(cin,s),s!="EOF"){
    m++;
    if(m>n)
      break;
    for(char i:s){
        if(i=='<'){if(!s2[m].empty())
              s2[m].pop_back();}

        else
              s2[m].push_back(i);
    }
    for (int i = 0; i < min(s1[m].size(), s2[m].size());i++)
        cnt += s1[m][i] == s2[m][i];

}
cin >> t;
cout << (long long)(cnt * 60.0 / t + 0.5);
system("pause");
return 0;
}