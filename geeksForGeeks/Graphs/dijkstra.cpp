#include<bits/stdc++.h>

using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    int inf = 1e9;
    vector<int> vis(V, 0);
    vector<int> dist(V, inf);

    dist[S] = 0;
    
    for (int i = 0; i < V; i++) {
        int mind = 1e9;
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0 && dist[i] < mind) {
                mind = dist[i];
            }
        }
        vector<int> next_vertices;
        for (int i = 0; i < V; i++) {
            if(vis[i] == 0 && dist[i] == mind) {
                next_vertices.push_back(i);
            }
        }

        int next_vertex = next_vertices[0];
        vis[next_vertex] = 1;

        for (auto it:adj[next_vertex]) {
            if (!(vis[it[0]])) {
                if (dist[next_vertex] + it[1] < dist[it[0]]) {
                    dist[it[0]] = dist[next_vertex] + it[1];
                }
            }
        }
    }
    return dist;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> adj[] = {
        {}
    };
    vector<int> res = dijkstra(4, adj, 5);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res[res.size() - 1] << "}" << endl;
    return 0;
}