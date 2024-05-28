#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main() {
    ios::sync_with_stdio(false);
    int n = 0, m = 0; cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        l.push_back(i);
    auto iter = l.begin();
    while(!l.empty()){
        for(int i = 1; i < m; ++i){
            if(next(iter) != l.end()) ++iter;
            else iter = l.begin();
        }
        cout << *iter << (l.size() > 1 ? " " : "\n");
        iter = l.erase(iter);
        if(iter == l.end()) iter = l.begin();  // !!!
    }
    return 0;
}
