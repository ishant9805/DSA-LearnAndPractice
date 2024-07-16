#include<bits/stdc++.h>

using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>> adj, int start_vertex) {
    // Code here    
    vector<int> visited;
    for (int i = 0; i < V; i++) {
        visited.push_back(0);
    }
    queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i<V; i++) {
            if (adj[curr][i] == 1 && (!visited[i])) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return visited;
}

int numProvinces(vector<vector<int>> adj, int V) {

    vector<int> component;
    for (int i = 0; i < V; i++) {
        component.push_back(-1);
    }

    int compid = 0;
    int seen = 0;

    while (seen < V) {
        vector<int> chose;
        for (int i = 0; i < V; i++) {
            if (component[i] == -1) {
                chose.push_back(i);
            }
        }
        int startv = 1e9;
        for (auto it: chose) {
            if (it < startv) {
                startv = it;
            }
        }
        vector<int> visited = bfsOfGraph(V, adj, startv);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 1) {
                seen = seen + 1;
                component[i] = compid;
            }
        }
        compid = compid + 1;
    }
    return compid;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> adjList = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    cout << "Number of provinces: " << numProvinces(adjList, 3);
    return 0;
}