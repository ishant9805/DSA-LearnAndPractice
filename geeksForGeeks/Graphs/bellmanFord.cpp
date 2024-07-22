#include<bits/stdc++.h>

using namespace std;


vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    int inf = 1e8;
    vector<int> dist(V,inf);
    dist[S] = 0;
    for (int i = 0; i < V-1; i++) {
        for (auto edge: edges) {
            int src = edge[0];
            int dst = edge[1];
            int wt = edge[2];
            if (dist[src] != inf && dist[src] + wt < dist[dst]) {
                dist[dst] = dist[src] + wt;
            }
        }
    }

    for(auto edge: edges) {
        int src = edge[0];
        int dst = edge[1];
        int wt = edge[2];
        if (dist[src] != inf && dist[src] + wt < dist[dst]) {
            return {-1};
        }
    }

    return dist;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> adj = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    vector<int> res = bellman_ford(3, adj, 2);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res[res.size() - 1] << "}" << endl;
    return 0;
}