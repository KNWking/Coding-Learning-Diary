#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fLL; // 定义一个大数表示无穷大
const int N = 1e5 + 10; // 定义最大节点数

struct edge{
    int from, to;
    long long weight;
    edge(int a, int b, long long c) : from(a), to(b), weight(c) {}
};

vector<edge> e[N];

struct node{
    int id;
    long long dist;
    node(int a, long long b) : id(a), dist(b) {}
    bool operator< (const node &a) const {
        return dist > a.dist;
    }
};

int n, m;
long long dis[N];
bool vis[N];

void dijkstra(int s) {
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
        vis[i] = false;
    }
    dis[s] = 0;
    priority_queue<node> pq;
    pq.push(node(s, dis[s]));

    while(!pq.empty()) {
        node u = pq.top();
        pq.pop();
        int uid = u.id;
        if(vis[uid]) continue;
        vis[uid] = true;

        for(auto &edge : e[uid]) {
            int v = edge.to;
            long long weight = edge.weight;
            if(dis[v] > dis[uid] + weight) {
                dis[v] = dis[uid] + weight;
                pq.push(node(v, dis[v]));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        e[a].push_back(edge(a, b, c));
		// 本题是单向边，所以只有 a -> b.
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    if(dis[end] == INF) {
        cout << "STOP" << endl;
    } else {
        cout << dis[end] << endl;
    }

    return 0;
}
