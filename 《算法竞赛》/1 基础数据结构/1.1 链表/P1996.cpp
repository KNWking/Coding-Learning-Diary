#include <bits/stdc++.h>
using namespace std;

list<int> lst;

int main () {
    int n = 0, m = 0; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) lst.push_back(i);
    auto it = lst.begin();
    while(!lst.empty()){
        for(int i = 1; i < m; ++i){
            ++it;
            if(it == lst.end()) it = lst.begin();
            // ！注意 it 碰到 end() 时不会自动回到 begin()，需要手动处理
        }
        if(lst.size() == 1) printf("%d\n", *it);
        else printf("%d ", *it);
        it = lst.erase(it);
        if(it == lst.end()) it = lst.begin();
        // ！注意 it 碰到 end() 时不会自动回到 begin()，需要手动处理
    }
    return 0;
}
