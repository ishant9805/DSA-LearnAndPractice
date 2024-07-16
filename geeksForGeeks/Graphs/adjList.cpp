#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
    // Code here
    vector<vector<int>> AList;
    for (int i = 0; i < V; i++) {
        vector<int> v;
        AList.push_back(v);
    }
    for (auto it : edges) {
        AList[it.first].push_back(it.second);
        AList[it.second].push_back(it.first);
    }
    return AList;
}

int main() {
    cout << "Starting Program" << endl;
    vector<pair<int, int>> edges = {{1,2},{2,3},{3,0},{0,1}};
    vector<vector<int>> v1 = printGraph(4, edges);
    cout << "##### Printing Matrix (Start) #####" << endl;
    
    for (int i = 0; i < v1.size(); i++) {
      cout << "[";
      for (int j = 0; j < v1[0].size(); j++) {
        cout << v1[i][j] << ", ";
      }
      cout << "]" << endl;
    }
    
    cout << "##### Printing Matrix (End) #####" << endl;
    return 0;
}