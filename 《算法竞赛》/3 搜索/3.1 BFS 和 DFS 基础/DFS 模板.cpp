#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node{
    char value;
    int lson, rson;
}tree[N];

int index = 1;  // tree[0] 不用，0 表示空节点。

int newNode(char val){
    tree[index].value = val;
    tree[index].lson = 0;
    tree[index].rson = 0;
    return index ++;
}

void insNode(int &father, int child, int l_r){
    if(l_r == 0) tree[father].lson = child;
    else         tree[father].rson = child;
}
// 以上部分和 BFS 同，均为建立二叉树，不再解释。

int dfn[N] = {0};  // dfn[i] 是结点 i 的时间戳。
int dfn_timer = 0;

void dfn_order (int father){
    if(father != 0){
        dfn[father] = ++dfn_timer;
        printf("dfn[%c]=%d; ", tree[father].value, dfn[father]);
        // 打印时间戳。
        dfn_order (tree[father].lson);
        dfn_order (tree[father].rson);
    }
}
// 基本原理就是像上面函数中的两次递归。
// 下面函数也基本是这样的。

int visit_timer = 0;

void visit_order (int father){  // 打印 DFS 序。
    if(father != 0){
        printf("visit[%c]=%d; ", tree[father].value, ++visit_timer);
        // 打印 DFS 序：第 1 次访问结点。
        visit_order (tree[father].lson);
        visit_order (tree[father].rson);
        printf("visit[%c]=%d; ", tree[father].value, ++visit_timer);
        // 打印 DFS 序：第 2 次回溯。
    }
}

int deep[N] = {0}; // deep[i] 是结点 i 的深度。
int deep_timer = 0;

void deep_node (int father){
    // 这里参数是 father，否则根节点无法使用该函数。
    if(father != 0){
        deep[father] = ++deep_timer;  // 打印树的深度，第一次访问时，深度 +1.
        printf("deep[%c]=%d; ",tree[father].value,deep[father]);
        deep_node (tree[father].lson);
        deep_node (tree[father].rson);
        deep_timer--;  // 回溯时，深度 -1.
    }
}

int num[N] = {0};  // num[i] 是以 i 为父亲的子树上的结点总数。

int num_node (int father){
    if(father == 0)  return 0;
    else{
        num[father] = num_node (tree[father].lson)
                    + num_node (tree[father].rson) + 1;
        printf("num[%c]=%d; ", tree[father].value, num[father]);
        // 打印数量。
        return num[father];
    }
}

void preorder (int father){  // 求先序序列。
    if(father != 0){
        cout << tree[father].value << " ";
        // 先序输出。
        preorder (tree[father].lson);
        preorder (tree[father].rson);
    }
}

void inorder (int father){  // 求中序序列。
    if(father != 0){
        inorder (tree[father].lson);
        cout << tree[father].value << " ";
        // 中序输出。
        inorder (tree[father].rson);
    }
}

void postorder (int father){  // 求后序序列。
    if(father != 0){
        postorder (tree[father].lson);
        postorder (tree[father].rson);
        cout << tree[father].value << " ";
        // 后序输出。
    }
}

int buildtree(){  // 测试用例，同 BFS，不再赘述。
    int A = newNode('A'); int B = newNode('B'); int C = newNode('C');
    int D = newNode('D'); int E = newNode('E'); int F = newNode('F');
    int G = newNode('G'); int H = newNode('H'); int I = newNode('I');
    insNode(E,B,0); insNode(E,G,1);
    insNode(B,A,0); insNode(B,D,1);
    insNode(G,F,0); insNode(G,I,1);
    insNode(D,C,0); insNode(I,H,0);
    int root = E;
    return root;
}

int main(){
    int root = buildtree();
    cout << "dfn order: ";     dfn_order(root); cout << endl;    //打印时间戳
    cout << "visit order: "; visit_order(root); cout << endl;    //打印DFS序
    cout << "deep order: ";    deep_node(root); cout << endl;    //打印结点深度
    cout << "num of tree: ";    num_node(root); cout << endl;    //打印子树上的结点数
    cout << "in order:   ";      inorder(root); cout << endl;    //打印中序序列
    cout << "pre order:  ";     preorder(root); cout << endl;    //打印先序序列
    cout << "post order: ";    postorder(root); cout << endl;    //打印后序序列
    return 0;
}

/* 输出是：
dfn order: dfn[E]=1; dfn[B]=2; dfn[A]=3; dfn[D]=4; dfn[C]=5; dfn[G]=6; dfn[F]=7; dfn[I]=8; dfn[H]=9;
visit order: visit[E]=1; visit[B]=2; visit[A]=3; visit[A]=4; visit[D]=5; visit[C]=6; visit[C]=7; visit[D]=8; visit[B]=9;
 visit[G]=10; visit[F]=11; visit[F]=12; visit[I]=13; visit[H]=14; visit[H]=15; visit[I]=16; visit[G]=17; visit[E]=18;
deep order: deep[E]=1; deep[B]=2; deep[A]=3; deep[D]=3; deep[C]=4; deep[G]=2; deep[F]=3; deep[I]=3; deep[H]=4;
num of tree: num[A]=1; num[C]=1; num[D]=2; num[B]=4; num[F]=1; num[H]=1; num[I]=2; num[G]=4; num[E]=9;
in order:   A B C D E F G H I
pre order:  E B A D C G F I H
post order: A C D B F H I G E

*/
