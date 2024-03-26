#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
deque<int> dq;
int n, m;
int num[N];

int main () {
    // 和 P1886 类似，不再赘述。
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
    printf("0\n");
    for(int i = 0; i < n - 1; ++i){
        // 不是 for(int i = 0; i < n; ++i)，注意题目要求。
        while(!dq.empty() && num[i] <= num[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && i - dq.front() >= m) dq.pop_front();
        printf("%d\n", num[dq.front()]);
    }
    return 0;
}
