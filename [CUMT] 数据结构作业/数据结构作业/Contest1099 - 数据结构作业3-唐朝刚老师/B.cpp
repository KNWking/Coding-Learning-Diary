#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int heap[N], len = 0;
// len 记录当前二叉树的长度。

void push(int x){
    // 因为只要整理，所以不需要写 pop() 函数。
    heap[++len] = x;
    int i = len;
    while (i > 1 && heap[i] < heap[i / 2]){
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

int main(){
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp = 0; cin >> tmp;
        push(tmp);
    }
    for(int i = 1; i <= len; ++i)
        cout << heap[i] << (i == len ? "\n" : " ");
    return 0;
}
