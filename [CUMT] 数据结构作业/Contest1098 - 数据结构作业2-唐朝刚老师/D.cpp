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

string ins, pres;

int buildTree(int preBeg, int preEnd, int inBeg, int inEnd);

void postorder(int father){
    if(father != 0){
        postorder(tree[father].lson);
        postorder(tree[father].rson);
        cout << tree[father].val;
    }
}

int main() {
    while(cin >> pres >> ins){
        int idx = 1;  // 多组数据，所以每次要重新赋值!!!
        int root = buildTree(0, pres.size() - 1, 0, ins.size() - 1);
        postorder(root);
        cout << endl;
    }
    return 0;
}

int buildTree(int preBeg, int preEnd, int inBeg, int inEnd){
    if(inBeg > inEnd || preBeg > preEnd) return 0;
    char rootVal = pres[preBeg];
    int root = newNode(rootVal);
    int inroot = 0;
    for(inroot = inBeg; inroot <= inEnd; ++inroot)
        if(ins[inroot] == rootVal)
            break;
    int len = inroot - inBeg;
    int lson = buildTree(preBeg + 1, preBeg + len, inBeg, inBeg + len - 1);
    // 注意这里的第二个参数，不是 preBeg + len - 1.
    int rson = buildTree(preBeg + len + 1, preEnd, inBeg + len + 1, inEnd);
    insNode(root, lson, 0);
    insNode(root, rson, 1);
    return root;
}
