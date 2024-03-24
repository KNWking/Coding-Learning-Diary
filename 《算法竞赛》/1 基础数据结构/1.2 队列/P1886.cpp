#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
deque<int> dq; // 存放索引
int n, k;
int num[N];

void print_min();
void print_max();

int main () {
    // 本题一个难点是准确判断各种范围。
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
    print_min();
    dq.clear(); // !!! 注意要清空 dq。
    print_max();
    return 0;
}

void print_min(){
    for(int i = 0; i < n; ++i){
        while(!dq.empty() && num[i] <= num[dq.back()]) dq.pop_back();
        // 保持 deque 从 front 到 back 为递减顺序，去尾。
        dq.push_back(i);
        if(i >= k - 1){ // 注意什么时候要输出最值。
            // 不是 i >= k。因为 i >= k - 1 时，窗口中已经有三个元素，需要开始处理输出了。
            while(!dq.empty() && i - dq.front() >= k) dq.pop_front();
            // 头部超出窗口范围，删头。
            printf("%d ", num[dq.front()]);
        }
    }
    printf("\n");
}

void print_max(){
    for(int i = 0; i < n; ++i){
        while(!dq.empty() && num[i] >= num[dq.back()]) dq.pop_back();
        // 保持 deque 从 front 到 back 为递增顺序，去尾。
        dq.push_back(i);
        if(i >= k - 1){ // 注意什么时候要输出最值
            // 不是 i >= k。因为 i >= k - 1 时，窗口中已经有三个元素，需要开始处理输出了。
            while(!dq.empty() && i - dq.front() >= k) dq.pop_front();
            // 头部超出窗口范围，删头。
            printf("%d ", num[dq.front()]);
        }
    }
    printf("\n");
}
