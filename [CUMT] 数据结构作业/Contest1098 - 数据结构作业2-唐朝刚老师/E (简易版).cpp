#include <bits/stdc++.h>
using namespace std;

string ins, posts;
char c;

/*
	讲一下思路：
 	
	因为题目给出了后序遍历，而要求的是子树的后序遍历，
	所以不需要建树，只要在原后序遍历中找到子树的遍历就行了。

	中序遍历和后序遍历，对于子树，默认都是先遍历左子树，
	因此左子树和右子树的节点各自是连续的。
	因此只要知道左/右子树的长度，就能直接求得答案。

	后序遍历，最后一个值即为根节点的值。
	再在中序遍历中找到根节点的位置，
	因为根节点的左边都是左子树的结点，
	根节点的右边都是右子树的结点，
	因此直接计数中序遍历中根节点左/右节点的个数就能得到需要的长度了。
	然后再在给出的后序遍历中找到输出序列即可。
 */

int main() {
    cin >> ins >> posts >> c;
    char rootVal = posts[posts.size() - 1];
	// 后序遍历，最后一个值即为根节点的值。
    int inroot = ins.find(rootVal);  // 在中序遍历中找到根节点的位置。
    int leftSize = inroot;  // 左子树的长度。
    int rightSize = ins.size() - inroot - 1;
	// 右子树的长度。
    if (c == 'L') {
        for (int i = 0; i < leftSize; ++i)
            cout << posts[i];
    } else {
        for (int i = leftSize; i < leftSize + rightSize; ++i)
            cout << posts[i];
    }
    cout << endl;
    return 0;
}
