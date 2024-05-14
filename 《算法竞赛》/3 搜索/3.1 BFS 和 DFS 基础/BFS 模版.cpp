#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node {
    char value;
    int lson, rson;
    // 左右 son 的 index.
} tree[N];

int index = 1;

int newNode(char val) {
    // 新建 Node 并初始化。
    tree[index].value = val;
    tree[index].lson = 0;
    tree[index].rson = 0;
    // 初始化时，lson & rson 都没有，
    // 所以 index 均为 0.
    return index++;
    // 返回节点的 index.
}

void insNode(int &father, int child, int l_r) {
    // 插入 Node. l_r 说明是 father 的 lson 还是 rson.
    if (l_r == 0) tree[father].lson = child;  // lson。
    else tree[father].rson = child;  // rson。
}

int buildTree(){  // 测试用例。
    int A = newNode('A'); int B = newNode('B');
    int C = newNode('C'); int D = newNode('D');
    int E = newNode('E'); int F = newNode('F');
    int G = newNode('G'); int H = newNode('H');
    int I = newNode('I');
    insNode(E, B, 0); insNode(E, G, 1);
    // 把 B 作为 E 的 lson 插入，把 G 作为 E 的右孩子插入。
    insNode(B, A, 0); insNode(B, D, 1);
    insNode(G, F, 0); insNode(G, I, 1);
    insNode(D, C, 0); insNode(I, H, 0);
    int root = E;  // 设置根节点为 E。
    return root;
}

int main() {
    int root = buildTree();
    queue<int> q;
    q.push(root);
    // 从根节点开始遍历，BFS。
    while (!q.empty()) {
        // 输出为 "E B G A D F I C H"。
        int tmp = q.front();
        // 当前搜索的 index。
        cout << tree[tmp].value << " ";
        q.pop();  // 搜索完要弹出队列。
        if (tree[tmp].lson != 0)
            q.push(tree[tmp].lson);
        if (tree[tmp].rson != 0)
            q.push(tree[tmp].rson);
    }
    return 0;
}
