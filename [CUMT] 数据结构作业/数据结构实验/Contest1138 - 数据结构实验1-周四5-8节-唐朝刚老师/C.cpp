#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main() {
    ios::sync_with_stdio(false);
    int n = 0, m = 0; cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        l.push_back(i);
    auto iter = l.begin();
    while(l.size() != 1){
        for(int i = 1; i < m; ++i){
            if(next(iter) != l.end()) ++iter;
            else iter = l.begin();
        }
        iter = l.erase(iter);
        if(iter == l.end()) iter = l.begin();
    }
    cout << l.front() << endl;
    return 0;
}
