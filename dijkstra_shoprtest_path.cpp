#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
using namespace std;

void Dijkstra_single_destination_shortest_path(int start, int destination, vector<vector<pair<int, int>>> &graph) {
    int Ver = graph.size();

    vector<int> distance(Ver, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    distance[start] = 0;
    p.push(make_pair(0, start));

    while (!p.empty()) {
        int u = p.top().second;
        p.pop();

        if (u == destination) {
            break;
        }

        for (auto v : graph[u]) {
            int w = v.second;
            int new_distance = distance[u] + w;
            if (new_distance < distance[v.first]) {
                distance[v.first] = new_distance;
                p.push(make_pair(new_distance, v.first));
            }
        }
    }
    cout << "Short distance from " << start << " to " << destination << " is: " << distance[destination] << endl;
}
int main() {
    int V, E;
    cout << "Enter Vertices and Edges : ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);
    cout << "Enter Edges and Weights :" << endl << "\t\t\t";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
        cout << "\t\t\t";
    }
    cout << endl;
    int start, destination;
    cout << "Enter the start vertices: ";
    cin >> start >> destination;
    Dijkstra_single_destination_shortest_path(start, destination, graph);
}
