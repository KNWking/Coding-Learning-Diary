#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node{
    char val;
    int lson;
    int rson;
}tree[N];

int idx = 1;

int newNode(char v){
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
// 学完 DFS 再来看吧。
void preorder(int father){
    if(father != 0){
        cout << tree[father].val;
        preorder(tree[father].lson);
        preorder(tree[father].rson);
    }
}

int buildTree(int inBeg, int inEnd, int postBeg, int postEnd);

int main(){
    cin >> ins >> posts;
    int root = buildTree(0, ins.size() - 1, 0, posts.size() - 1);
    preorder(root);
    cout << endl;
    return 0;
}

int buildTree(int inBeg, int inEnd, int postBeg, int postEnd){
    if(inBeg > inEnd || postBeg > postEnd) return 0;
    char rootVal = posts[postEnd];
    int rootIdx = newNode(rootVal);
    int inroot = 0;
    for(inroot = inBeg; inroot <= inEnd; ++inroot)
        if(ins[inroot] == rootVal)
            break;
    int lSize = inroot - inBeg;
    int lIdx = buildTree(inBeg, inroot - 1, postBeg, postBeg + lSize - 1);
    // 因为左子树在后序遍历的前面，所以后两个参数是 postBeg 和 postBeg + lSize - 1。
    int rIdx = buildTree(inroot + 1, inEnd, postBeg + lSize, postEnd - 1);
    // 同上。
    insNode(rootIdx, lIdx, 0);
    insNode(rootIdx, rIdx, 1);
    return rootIdx;
}
