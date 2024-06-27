#include <bits/stdc++.h>
using namespace std;
// 勾石题目。
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d): data(d), left(NULL), right(NULL) {}
};

Node* buildTree(string& s, int& i) {
    if (i >= s.size() || s[i] == ' ') return NULL;
    Node* root = new Node(s[i]);
    i++;
    root->left = buildTree(s, i);
    i++;
    root->right = buildTree(s, i);
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder1(Node* root) {
    if (root == NULL) return;
    inOrder1(root->left);
    cout << root->data << " ";
    inOrder1(root->right);
}

void inOrder2(Node* root) {
    if (root == NULL) return;
    inOrder2(root->left);
    cout << root->data << " ";
    inOrder2(root->right);
}

int main() {
    string s;
    getline(cin, s);
    int i = 0;
    Node* root = buildTree(s, i);
    preOrder(root);
    cout << endl;
    inOrder1(root);
    cout << endl;
    inOrder2(root);
    cout << endl;
    return 0;
}
