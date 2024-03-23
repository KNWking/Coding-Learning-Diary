#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
queue<int> q;
int exist[N];
int ans;

int main () {
    int m = 0, n = 0; cin >> m >> n;
    for(int i = 0; i < n; ++i){
        int word = 0; cin >> word;
        if(!exist[word]){
            ++ans;
            q.push(word);
            exist[word] = 1;
            while(q.size() > m){
                // 本题使用 if 来判断也可以，
                // 但是如果一次加入多个，就要用 while
                exist[q.front()] = 0;
                q.pop();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
