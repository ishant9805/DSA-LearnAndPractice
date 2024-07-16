#include<bits/stdc++.h>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> visited;
    for (int i = 0; i < V; i++) {
        visited.push_back(0);
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    vector<int> path;
    path.push_back(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto adj_vertex : adj[curr])
        {
            if (!visited[adj_vertex]) {
                path.push_back(adj_vertex);
                visited[adj_vertex] = 1;
                q.push(adj_vertex);
            }
        }
    }
    return path;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> adjList[] = {{1,2,3},{},{4},{},{}};
    vector<int> path = bfsOfGraph(5, adjList);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] << ", ";
    }
    cout << path[path.size() - 1] << "}" << endl;
    return 0;
}