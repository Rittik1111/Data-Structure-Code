#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
void Dijkstra(vector<vector<p>>& graph, int start, int destination) {
    int ver = graph.size();
    vector<int> distance(ver, INT_MAX);
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    if (distance[destination] != INT_MAX) {
        cout << "Short distance from " << start << " to " << destination << " is: " << distance[destination] << endl;
    } else {
        cout << "There is no path from " << start << " to " << destination << endl;
    }

}

int main() {
    int Ver, Edge;
    cout << "Enter Vertices and Edges: ";
    cin >> Ver >> Edge;
    vector<vector<p>> graph(Ver);
    cout << "Enter Edges and Weights :" << endl<< "\t\t\t";
    for (int i = 0; i < Edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        cout << "\t\t\t";
    }
    cout << endl;
    int start, destination;
    cout << "Enter the first vertices : ";
    cin >> start >> destination;
    Dijkstra(graph, start, destination);
    return 0;
}
