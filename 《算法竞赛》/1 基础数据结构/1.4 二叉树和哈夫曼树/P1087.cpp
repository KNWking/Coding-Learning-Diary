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

int n;
string s;

int FBI(int sBeg, int sEnd);
// 学完 DFS 再来看吧。
void postorder(int father){
	if(father != 0){
		postorder(tree[father].lson);
		postorder(tree[father].rson);
		cout << tree[father].val;
	}
}

int main(){
	cin >> n;
	cin >> s;
	// 不能直接用 getline，
	// 因为有 n 后面的 '\n' 在缓冲区中。
	int root = FBI(0, s.size() - 1);
	postorder(root);
	cout << endl;
   return 0;
}

int FBI(int sBeg, int sEnd){
	// 纯纯递归。
	// 二叉树的每个子树在结构上都和原树相同，
	// 因此递归函数设计起来很简单。
	if(sBeg > sEnd) return 0;
	// 防错。
	int isb = 0, isi = 0;
	for(int i = sBeg; i <= sEnd; ++i){
    // 判断是 B，I 还是 F 串。
		if(s[i] == '0') isb = 1;
		if(s[i] == '1') isi = 1;
		if(isb && isi) break;
	}
	int rootIdx = 0;
	if(isb && isi) rootIdx = newNode('F');
	else if(isb == 1) rootIdx = newNode('B');
	else rootIdx = newNode('I');
	if(sEnd - sBeg > 0){
		// 注意终止条件。
    // 应该是 > 0，而不是 > 1，
    // 因为 = 1 时只是不需要判断左右串。
		int mid = (sEnd + sBeg) / 2;
		// 从中间截断。
		int lIdx = FBI(sBeg, mid);
		int rIdx = FBI(mid + 1, sEnd);
		insNode(rootIdx, lIdx, 0);
		insNode(rootIdx, rIdx, 1);
	}
	return rootIdx;
}
