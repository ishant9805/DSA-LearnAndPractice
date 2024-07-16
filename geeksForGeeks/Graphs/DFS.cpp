#include<bits/stdc++.h>

using namespace std;

// Stack Approach
// vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//     // Code here
//     vector<int> visited;
//     for (int i = 0; i < V; i++) {
//         visited.push_back(0);
//     }
//     stack<int> st;
//     st.push(0);
//     vector<int> route;
//     while(!st.empty()) {
//         int curr = st.top();
//         route.push_back(curr);
//         st.pop();
//         if (visited[curr] == 0) {
//             visited[curr] = 1;
//             for(auto adj_vertex : adj[curr]) {
//                 if (!visited[adj_vertex]) {
//                     st.push(adj_vertex);
//                 }
//             }
//         }
//     }
//     return route;
// }

// Recursive Approach

void dfs(int node, vector<int> adj[], vector<int> &path, vector<bool> &viz) {
    viz[node] = true;
    path.push_back(node);
    for(auto adj_vertex : adj[node]) {
        if (!viz[adj_vertex]) {
            dfs(adj_vertex, adj, path, viz);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> viz;
    for (int i = 0; i < V; i++) {
        viz.push_back(false);
    }
    vector <int> path;
    dfs(0, adj, path, viz);
    return path;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> adjList[] = {{2,3,1} , {0}, {0,4}, {0}, {2}};
    vector<int> path = dfsOfGraph(5, adjList);
    cout << path[0] << endl;
    cout << path[1] << endl;
    return 0;
}