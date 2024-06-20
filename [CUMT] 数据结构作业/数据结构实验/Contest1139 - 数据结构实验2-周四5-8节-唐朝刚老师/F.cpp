#include <bits/stdc++.h>
using namespace std;

const int N = 110;

struct Node{
    char val;
    vector<int> children;
}tree[N];

int idx = 1;

int newNode(char v){
    tree[idx].val = v;
    return idx++;
}

void preOrder(int node) {
    if(node == 0) return;
    cout << tree[node].val << " ";
    for(auto child : tree[node].children) {
        preOrder(child);
    }
}

int main(){
    char p, c;
    int exist[26] = {0};
    while(cin >> p >> c){
        if(exist[p - 'A'] == 0){
            exist[p - 'A'] = newNode(p);
        }
        if(exist[c - 'A'] == 0){
            exist[c - 'A'] = newNode(c);
        }
        tree[exist[p - 'A']].children.push_back(exist[c - 'A']);
    }
    int root = -1;
    for(int i = 1; i < idx; ++i) {
        bool isRoot = true;
        for(int j = 1; j < idx; ++j) {
            for(int child : tree[j].children) {
                if(child == i) {
                    isRoot = false;
                    break;
                }
            }
            if(!isRoot) break;
        }
        if(isRoot) {
            root = i;
            break;
        }
    }
    preOrder(root);
    return 0;
}
