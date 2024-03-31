#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;
stack<int> s;
int n;
int ele[N];
int ans[N];

int main(){
    // 和 P2947 类似，不再赘述。
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &ele[i]);
    for(int i = n; i >= 1; --i){
        while(!s.empty() && ele[i] >= ele[s.top()]) s.pop();
        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top();
        s.push(i);
    }
    for(int i = 1; i < n; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}
