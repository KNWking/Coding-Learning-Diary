#include <bits/stdc++.h>
using namespace std;

const int N = 30;

struct Node {
    char val;
    int lson;
    int rson;
} tree[N];

int idx = 1;

int newNode(char v) {
    tree[idx].val = v;
    tree[idx].lson = 0;
    tree[idx].rson = 0;
    return idx++;
}

void insNode(int& father, int child, int l_r){
    if(l_r == 0) tree[father].lson = child;
    else tree[father].rson = child;
}

string ins, posts;
char c;

int buildTree(int inBeg, int inEnd, int postBeg, int postEnd);

void postorder(int father){
    if(father != 0){
        postorder(tree[father].lson);
        postorder(tree[father].rson);
        cout << tree[father].val;
    }
}

int main() {
    cin >> ins >> posts >> c;
    int root = buildTree(0, ins.size() - 1, 0, posts.size() - 1);
    if(c == 'L'){
        postorder(tree[root].lson);
    }else{
        postorder(tree[root].rson);
    }
    cout << endl;
    return 0;
}

int buildTree(int inBeg, int inEnd, int postBeg, int postEnd){
    if(inBeg > inEnd || postBeg > postEnd) return 0;
    char rootVal = posts[postEnd];
    int root = newNode(rootVal);
    int inroot = 0;
    for(inroot = inBeg; inroot <= inEnd; ++inroot)、
        // 不能用 ins.find(rootVal) 替代，因为 inBeg 不定为 0.
        if(ins[inroot] == rootVal)
            break;
    int len = inroot - inBeg;
    int lson = buildTree(inBeg, inBeg + len - 1, postBeg, postBeg + len - 1);
    // 注意参数如何定值。
    int rson = buildTree(inBeg + len + 1, inEnd, postBeg + len, postEnd - 1);
    insNode(root, lson, 0);
    insNode(root, rson, 1);
    return root;
}
