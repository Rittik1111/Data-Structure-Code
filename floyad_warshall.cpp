#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 999;
vector <pair<int, int>> G[M];
vector <int> All_pairs_shortest_paths(int & num, vector <vector<int>> E){

   for(int i = 1; i <= num; i++){
       E.push_back({0, i, 0});
   }
   vector <int> distance(num + 1, INT_MAX);
   distance[0] = 0;
   while(true){
       bool check = false;
       for(auto e : E){
           int u = e[0];
           int v = e[1];
           int w = e[2];
           if(distance[v] > distance[u] + w){
               distance[v] = distance[u] + w;
               check = true;
           }
       }
       if(!check)
           break;
   }
   return distance;
}
void Dijkstra(int p, vector <vector<int>> & path, int & num){
   priority_queue<pair<int, int>> q;
   vector <int> visited(num + 1);
   path[p][p] = 0;
   q.push({0, p});
   while(!q.empty()){
       int r = q.top().second;
       q.pop();
       if(!visited[r]){
           visited[r] = true;
           for(auto u : G[r]){
               int m = u.first;
               int w = u.second;
               if(path[p][r] + w < path[p][m]){
                   path[p][m] = path[p][r] + w;
                   q.push({-path[p][m], m});
               }
           }
       }
   }
}
signed main(){
   int A, B;
   cout << "Enter Edges and Vertices : ";
   cin >> A >> B;
   vector <vector<int>> edges;
    cout << "Enter Edges : " << endl << "\t\t\t";
   for(int i = 1; i <= B; i++){
       int u, v, w;
       cin >> u >> v >> w;
       edges.push_back({u, v, w});
       cout << "\t\t\t";
   }
   vector <int> C = All_pairs_shortest_paths(A, edges);
   for(int i = 0; i < B; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       edges[i][2] += (C[u] - C[v]);
   }
   vector <vector<int>> path(A + 1, vector <int> (A + 1, INT_MAX));
   for(auto e : edges){
       G[e[0]].push_back({e[1], e[2]});
   }
   for(int i = 1; i <= A; i++){
       Dijkstra(i, path, A);
   }
   for(int i = 1; i <= A; i++){
       for(int j = 1; j <= A; j++){
           if(path[i][j] == INT_MAX)
               cout << -1 << " ";
           else
               cout << path[i][j] - (C[i] - C[j]) << " ";
       }
       cout << "\n";
   }
   return 0;
}
