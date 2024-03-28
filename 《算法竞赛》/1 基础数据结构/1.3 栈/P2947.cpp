#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
stack<int> s;
int height[N];
int ans[N];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &height[i]);
    // 由题目，下标从 1 开始。
    for(int i = n; i > 0; --i){
        // 从后往前判断。
        while(!s.empty() && height[i] >= height[s.top()]) s.pop();
        // 维护一个从栈顶到栈底递增的单调栈，原理类似单调队列。
        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top();
        // 因为是从后往前维护单调栈，所以输出时要你箱输出，这就需要一个数组来存储。
        s.push(i);
    }
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}
