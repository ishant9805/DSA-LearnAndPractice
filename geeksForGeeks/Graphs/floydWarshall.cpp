#include <bits/stdc++.h>
using namespace std;


void shortest_distance(vector<vector<int>>&matrix){

    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e8;
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][via] + matrix[via][j], matrix[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e8) {
                matrix[i][j] = -1;
            }
        }
    }
    
    return;
}


int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> matrix = {{0, 1, 43},{1, 0, 6},{-1, -1, 0}};
    shortest_distance(matrix);
    cout << "##### Printing Matrix (Start) #####" << endl;
    
    for (int i = 0; i < matrix.size(); i++) {
      cout << "[";
      for (int j = 0; j < matrix[0].size(); j++) {
        cout << matrix[i][j] << ", ";
      }
      cout << "]" << endl;
    }
    
    cout << "##### Printing Matrix (End) #####" << endl;
    return 0;
}