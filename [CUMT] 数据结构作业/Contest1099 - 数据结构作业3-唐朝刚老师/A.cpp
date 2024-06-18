#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int vis[N];
int n, m;
int temp;
vector<vector<int>> map1;
// 存储无向图的常用数据结构。

void dfs(int node){
    vis[node] = 1;  // 经典首先判断，剪枝。
    cout << node << (--temp != 0 ? " " : "\n");
    for(int i = 0; i < map1[node].size(); ++i)
        if(!vis[map1[node][i]])
            dfs(map1[node][i]);
        // 别忘判断是否访问后再进行 dfs 递归。
}

int main(){
    cin >> m >> n;
    temp = m;
    map1.resize(m);
    // 此处需要初始化，否则类似 map1[a].push_back(b)
    // 的语句可能会溢出。
    for(int i = 0; i < n; ++i){
        int a = 0, b = 0; cin >> a >> b;
        map1[a].push_back(b);
        map1[b].push_back(a);
        // 因为是无向图，所以要存储两条有向边。
    }
    for(int i = 0; i < m; ++i)
        sort(map1[i].begin(), map1[i].end());
    // 题目要求编号小的优先访问，所以要排序。
    dfs(0);
    return 0;
}
