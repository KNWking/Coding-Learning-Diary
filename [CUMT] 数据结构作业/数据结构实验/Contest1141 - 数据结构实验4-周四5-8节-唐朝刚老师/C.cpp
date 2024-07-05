#include <bits/stdc++.h>
 
using namespace std;

struct Edge {
    char destination;
    int weight;
};
 
int calculateShortestTime(const unordered_map<char, vector<Edge>>& graph) {
    unordered_map<char, int> inDegree;
    unordered_map<char, int> earliestStartTime;
    for (const auto& node : graph) {
        char currentNode = node.first;
        inDegree[currentNode] = 0;
        earliestStartTime[currentNode] = -1;
    }
 
    for (const auto& node : graph) {
        char currentNode = node.first;
        for (const Edge& edge : node.second) {
            char nextNode = edge.destination;
            inDegree[nextNode]++;
        }
    }

    earliestStartTime['A'] = 0;
 
    queue<char> q;
    q.push('A');
 
    while (!q.empty()) {
        char currentNode = q.front();
        q.pop();
 
        auto it = graph.find(currentNode);
        if (it == graph.end()) {
            continue;
        }
 
        for (const Edge& edge : it->second) {
            char nextNode = edge.destination;
            int nextStartTime = earliestStartTime[currentNode] + edge.weight;
            earliestStartTime[nextNode] = max(earliestStartTime[nextNode], nextStartTime);
            if (--inDegree[nextNode] == 0) {
                q.push(nextNode);
            }
        }
    }

    return earliestStartTime['Z'];
}
 
int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<char, vector<Edge>> graph;
    for (int i = 0; i < M; ++i) {
        char startNode, endNode;
        int weight;
        cin >> startNode >> endNode >> weight;
        graph[startNode].push_back({ endNode, weight });
    }
 
    int shortestTime = calculateShortestTime(graph);
    cout << shortestTime << endl;
 
    return 0;
}
