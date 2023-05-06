#include<bits/stdc++.h>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void vertices_cost_distance(int start, vector<vector<pair<int, int>>> &graph, vector<int> &vertices_cost) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    unordered_map<int, int> short_path;
    p.push(make_pair(vertices_cost[start], start));
    short_path[start] = vertices_cost[start];

    while (!p.empty()) {
        int current_vertex = p.top().second;
        p.pop();
        if (short_path.count(current_vertex) == 0) {
            short_path[current_vertex] = p.top().first;
        }
        for (auto n : graph[current_vertex]) {
            int n_vertex = n.first;
            int path_cost = n.second;
            if (short_path.count(n_vertex) == 0) {
                int newest_cost = short_path[current_vertex] + path_cost + vertices_cost[n_vertex];
                p.push(make_pair(newest_cost, n_vertex));
            }
            else if (short_path[current_vertex] + path_cost + vertices_cost[n_vertex] < short_path[n_vertex]) {
                short_path[n_vertex] = short_path[current_vertex] + path_cost + vertices_cost[n_vertex];
                p.push(make_pair(short_path[n_vertex], n_vertex));
            }
        }
    }

    for (auto vertices : short_path) {
        cout << "Best path - " << vertices.first << " = " << vertices.second << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter Vertices and Edges : ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);
    vector<int> vertices_cost(V);

    cout << "Enter the edges :" << endl << "\t\t\t";
    for (int i = 0; i < E; i++) {
        int a, destination, w;
        cin >> a >> destination >> w;
        graph[a].push_back(make_pair(destination, w));
        graph[destination].push_back(make_pair(a, w));
        cout << "\t\t\t" ;
    }
    cout << endl;
    cout << "Enter Vertics Cost : ";
    for (int i = 0; i < V; i++) {
        cin >> vertices_cost[i];
    }
    int start;
    cout << "Enter 1st Vertics : ";
    cin >> start;
    vertices_cost_distance(start, graph, vertices_cost);
}
