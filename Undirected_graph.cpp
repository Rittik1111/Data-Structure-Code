#include<bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<int>>& graph, int start) {
    int ver = graph.size();
    vector<int> distance(ver, INT_MAX);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : graph[u]) {
            if (distance[u] != INT_MAX && distance[u] + 1 < distance[v]) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "Shortest path from " << start << " to all other vertices:" << endl;
    for (int i = 0; i < ver; i++) {
        if (distance[i] != INT_MAX) {
            cout << i << ": " << distance[i] << endl;
        } else {
            cout << i << ": Not reachable" << endl;
        }
    }
}
int main() {
    int V, E;
    cout << "Enter Vertices and Edges : ";
    cin >> V >> E;
    vector<vector<int>> graph(V);
    cout << "Enter the Edges :" << endl << "\t\t\t";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        cout << "\t\t\t";
    }
    cout << endl;
    int start;
    cout << "Enter first vertices : ";
    cin >> start;
    Dijkstra(graph, start);
}
