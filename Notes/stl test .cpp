// #include<vector>
// #include<iostream>
// using namespace std;
// int main(){
//     vector<int> v1;
//     vector<int> v2;
//     v1.push_back(1);
//     v1.push_back(2);
//     v1.push_back(3);
//     v1.push_back(4);
//     v1.push_back(5);
//     v1.push_back(6);
//     v1.push_back(7);
//     //v1.erase(v1.begin() );
//     int a=v1.front();
//     cout << a;
//     cout << v1.capacity();
//     v2.assign(v1.begin(), v1.end());
//     for (auto tt = v2.begin(); tt != v2.end();++tt)
//         cout << *tt << " ";
//     system("pause");
//     return 0;
// }
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//     string a = "Hello world";
//     string b("hellp world");
//     string c(a, 6);
//     string d = b.substr(6, 6);
//     string e = b.substr(6);
//     string f = a.replace(5, 5, "fuck");
//     cout << a << endl;
//     cout << b << endl;
//     cout << c << endl;
//     cout << d << endl;
//     cout << e << endl;
//     cout << a[1] << endl;

//     cout << f << endl;


//     system("pause");
// }
#include <iostream>
#include <map>
#include <string>
#include<algorithm>

using namespace std;
bool cmp (map<string,size_t> a,map<string,size_t> b){
    return a < b;
}
typedef pair<int, int> pii;
int main()
{
    // 统计每个单词在输入中出现的次数
    map<string, size_t> word_count; // string到map的空map
    string word;
    map<pii, int> m;
    // while (cin >> word)
    // {
    //     word_count[string(word)]++;
    //     //++word_count[word]; // 提取word的计数器并将其加1
    // }
    
    // for (const auto w : word_count) // 遍历map的每个元素
    // {
    //     cout << w.first << "出现的次数为: " << w.second << endl;
    // }
    int x, y;
    while(cin>>x>>y){
        m[make_pair(x, y)]++;

    }
    auto t = m.find(make_pair(1, 4));
    cout << t->second;
    for(auto w:m){
        cout << w.first.first << " " << w.first.second << " " << w.second;
    }
    system("pause");
    return 0;
}
//map示例
// #include <iostream>
// #include "string.h"
// #include "stdio.h"
// #include <map>
// using namespace std;

// int main()
// {
//     map<string, int> strMap; // 以string为键值，以int为实值
//     strMap[string("jjhou")] = 1;
//     strMap[string("jerry")] = 2;
//     strMap[string("jason")] = 3;
//     strMap[string("jimmy")] = 4;

//     pair<string, int> value(string("david"), 5);
//     strMap.insert(value); // 插入新元素
//     // 或 strMap[健]=键值；

//     // 遍历
//     map<string, int>::iterator iter = strMap.begin();
//     for (; iter != strMap.end(); iter++)
//     {
//         cout << iter->first << ' ' << iter->second << endl;
//     }
//     cout << endl;

//     int number = strMap[string("jjhou")];
//     cout << number << endl;
//     cout << endl;

//     // 查找元素
//     map<string, int>::iterator iter3;
//     // 面对关联式容器，应该使用其所提供的find函数来搜索元素，会比使用STL算法find()更有效率。因为STL算法find()只是循环搜索。
//     iter3 = strMap.find(string("mchen"));
//     if (iter3 == strMap.end())
//         cout << "mchen no fount" << endl;
//     cout << endl;

//     iter3 = strMap.find(string("jerry"));
//     if (iter3 != strMap.end())
//         cout << "jerry fount" << endl;
//     cout << endl;

//     // 修改实值，键值不可修改
//     iter3->second = 9; // 可以通过map迭代器修改“value”(not key)
//     int number1 = strMap[string("jerry")];
//     cout << number1 << endl;

//     map<string, int>::iterator iter1 = strMap.begin();
//     for (; iter1 != strMap.end(); iter1++)
//     {
//         cout << iter1->first << ' ' << iter1->second << endl;
//     }
//     cout << endl;

//     // 删除元素
//     strMap.erase(iter1);           // 删除一个条目
//     strMap.erase(string("jason")); // 根据键值删除

//     map<string, int>::iterator iter2 = strMap.begin();
//     for (; iter2 != strMap.end(); iter2++)
//     {
//         cout << iter2->first << ' ' << iter2->second << endl;
//     }
// }
