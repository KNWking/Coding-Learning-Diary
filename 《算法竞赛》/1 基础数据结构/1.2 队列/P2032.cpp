#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
deque<int> dq;
int n, k;
int num[N];

int main () {
    // 和 P1886 类似，不再赘述。
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
    for(int i = 0; i < n; ++i){
        while(!dq.empty() && num[i] >= num[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i + 1 >= k){
            while(!dq.empty() && dq.front() + k <= i) dq.pop_front();
            printf("%d\n", num[dq.front()]);
        }
    }
    return 0;
}
