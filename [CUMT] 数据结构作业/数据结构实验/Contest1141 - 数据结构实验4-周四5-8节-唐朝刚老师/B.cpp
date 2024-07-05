#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

vector<Edge> adj[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

void dijkstra(int source, int n) {
    memset(visited, false, sizeof(visited));
    fill(dist, dist + n + 1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        
        if (visited[v]) continue;
        visited[v] = true;
        
        for (const Edge& edge : adj[v]) {
            int u = edge.to;
            int weight = edge.weight;
            
            if (dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                pq.push({dist[u], u});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    int target;
    cin >> target;
    
    dijkstra(1, n);
    
    if (dist[target] == INF) {
        cout << "-1" << endl;
    } else {
        cout << dist[target] << endl;
    }
    
    return 0;
}
