#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

list<int> l;
list<int>::iterator iter[N];
// 使用迭代器数组。
// list 迭代器的一个特点是，插入/删除一个节点，
// 原迭代器指向的结点不会变。

int n = 0, m = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int tmp = 0; cin >> tmp;
        l.push_back(tmp);
        iter[i] = prev(l.end());
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        int pos = 0, val = 0;
        cin >> pos >> val;
        l.insert(iter[pos], val);
    }
    for(auto it = l.begin(); it != l.end(); ++it)
        cout << *it << (next(it) != l.end() ? ' ' : '\n');
    return 0;
}
