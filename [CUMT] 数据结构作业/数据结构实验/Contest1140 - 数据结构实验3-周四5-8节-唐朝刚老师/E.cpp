#include <bits/stdc++.h>
using namespace std;

int primMinimumCost(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> minEdge(n, INT_MAX);
    vector<bool> inMST(n, false);
    minEdge[0] = 0;
    int totalCost = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }
        inMST[u] = true;
        totalCost += minEdge[u];
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }
    return totalCost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    cout << primMinimumCost(graph) << endl;
    return 0;
}
