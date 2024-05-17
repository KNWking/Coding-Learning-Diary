#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct Node{
	char value;
	int lson, rson;
}tree[N];

int index = 1;
// tree[0] 不用，0 表示空节点。

int newNode(const char val){
	tree[index].value = val;
	tree[index].lson = 0;
	tree[index].rson = 0;
	return index++;
}

void insNode(int& father, int child, int l_r){
	if(l_r == 0) tree[father].lson = child;
	else tree[father].rson = child;
}
// 以上部分和 BFS 同，均为建立二叉树，不再解释。

int dfn[N] = {0};
// dfn[i] 是节点 i 的时间戳。
int dfn_timer = 0;

void dfn_order(int father){
	if(father != 0){
		dfn[father] = ++dfn_timer;
		printf("dfn[%c] = %d;", tree[father].value, dfn[father]);
		// 打印时间戳。
		dfn_order(tree[father].lson);
		dfn_order(tree[father].rson);
	}
}

int visit_timer = 0;

void visit_order(int father){
	// 打印 DFS 序。
	if(father != 0){
		printf("visit[%c] = %d;", tree[father].value, ++visit_timer);
		// 打印 DFS 序：第一次访问 node.
		visit_order(tree[father].lson);
		visit_order(tree[father].rson);
		printf("visit[%c] = %dl", tree[father].value, ++visit_timer);
		// 打印 DFS 序：第二次回溯 node.
	}
}

int deep[N] = {0};
// deep[i] 是节点 i 的深度。
int deep_timer = 0;

void deep_node(int father){
	// 这里参数是 father，否则根节点无法使用该函数。
	if(father != 0){
		deep[father] = ++deep_timer;
		// 打印树的深度，第 1 次访问时，深度加 1。
		printf("deep[%c] = %d;", tree[father].value, deep[father]);
		deep_node(tree[father].lson);
		deep_node(tree[father].rson);
		deep_timer--;
		// 回溯时，深度减 1。
	}
}

int num[N] = {0};
// num[i] 是以 i 为 father 的子树上的节点总数。
int num_node(int father){
	if(father == 0) return 0;
	else{
		num[father] = num_node(tree[father].lson)
		+ num_node(tree[father].rson) + 1;
		printf("num[%c] = %d;", tree[father].value, num[father]);
		// 打印数量。
		return num[father];
	}
}

void preorder(int father){
	// 求先序序列。
	if(father != 0){
		cout << tree[father].value << " ";
		preorder(tree[father].lson);
		preorder(tree[father].rson);
	}
}

void inorder(int father){
	// 求中序序列。
	if(father != 0){
		inorder(tree[father].lson);
		cout << tree[father].value << " ";
		inorder(tree[father].rson);
	}
}

void postorder(int father){
	// 求后序序列。
	if(father != 0){
		postorder(tree[father].lson);
		postorder(tree[father].rson);
		cout << tree[father].value << " ";
	}
}

// 测试用例，同 BFS，不再赘述。
int buildtree(){
	int A = newNode('A'); int B = newNode('B'); int C = newNode('C');
	int D = newNode('D'); int E = newNode('E'); int F = newNode('F');
	int G = newNode('G'); int H = newNode('H'); int I = newNode('I');
	insNode(E, B, 0); insNode(E, G, 1);
	insNode(B, A, 0); insNode(B, D, 1);
	insNode(G, F, 0); insNode(G, I, 1);
	insNode(D, C, 0); insNode(I, H, 0);
	int root = E;
	return root;
}

int main(){
	int root = buildtree();
	cout << "dfn order: ";    dfn_order(root);   cout << endl;
	cout << "visit order: ";  visit_order(root); cout << endl;
	cout << "deep order: ";   deep_node(root);   cout << endl;
	cout << "num of tree: ";  num_node(root);    cout << endl;
	cout << "in order";       inorder(root);     cout << endl;
	cout << "pre order: ";    preorder(root);    cout << endl;
	cout << "post order: ";   postorder(root);   cout << endl;
	return 0;
}
