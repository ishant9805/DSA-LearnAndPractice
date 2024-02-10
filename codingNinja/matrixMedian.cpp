#include<bits/stdc++.h>

using namespace std;

int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> flat;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            flat.push_back(matrix[i][j]);
        }
        
    }
    sort(flat.begin(), flat.end());
    m = (m*n) / 2;
    return flat[m];
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {
        { 1, 5, 7, 9, 11 },
        { 2, 3, 4, 8, 9 },
        { 4, 11, 14, 19, 20 },
        { 6, 10, 22, 99, 100 },
        { 7, 15, 17, 24, 28 }
    };
    cout << median(v1, 5, 5) << endl;
    
    return 0;
}