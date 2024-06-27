#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int heap[N], len;
// 此处演示的是最小堆 (小根堆)。
// len 为 heap 节点数，初始值为 0，
// 但是根节点为 1.

void push(int x){
    // 上浮，插入新元素。
    heap[++len] = x;
    int i = len; // x 的索引。
    while(i > 1 && heap[i] < heap[1 / 2]){
        swap(heap[i], heap[1 / 2]);
        // x 的根节点和 x 互换。
        i = i / 2;
    }
}

void pop(){
    // 下沉，删除堆头，调整堆。
    heap[1] = heap[len--];
    // 根节点替换为最后一个节点，节点数量减 1.
    int i = 1;
    while(2 * i <= len){
        // 至少有左儿子。
        int son = 2 * i;
        // 左儿子。
        if(son < len && heap[son + 1] < heap[son])
            // son < len 表示有右儿子，选儿子中较小的。
            son++;
        if(heap[son] < heap[i]){
            // 与较小的儿子交换。
            swap(heap[son], heap[i]);
            i = son;
        }else break; // 如果不比儿子小，就停止下沉。
    }
}

int top(){return heap[1];}

int main() {
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp = 0; cin >> tmp;
        push(tmp);
    }
    for(int i = 0; i < n; ++i){
        cout << top() << " ";
        pop();
    }
    return 0;
}
