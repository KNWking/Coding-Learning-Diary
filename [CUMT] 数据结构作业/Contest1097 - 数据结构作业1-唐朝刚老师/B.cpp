#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

list<int> l;
list<int>::iterator iter[N];

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
