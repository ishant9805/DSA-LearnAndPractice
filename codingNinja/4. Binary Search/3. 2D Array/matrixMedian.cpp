#include<bits/stdc++.h>

using namespace std;

// Brute force
// int median(vector<vector<int>> &matrix, int m, int n) {
//     vector<int> flat;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             flat.push_back(matrix[i][j]);
//         }
        
//     }
//     sort(flat.begin(), flat.end());
//     m = (m*n) / 2;
//     return flat[m];
// }

int bbox(vector<vector<int>> &mat, int x) {
    auto cnt = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
    }
    return cnt;
}

int median(vector<vector<int>> &mat, int m, int n) {
    int low = 1e9;
    for (int i = 0; i < m; i++) {
        if (low > mat[i][0]) {
            low = mat[i][0];
        }
    }
    int high = 0;
    for (int i = 0; i < m; i++) {
        if (high < mat[i][n - 1]) {
            high = mat[i][n - 1];
        }
    }
    int rq = (m * n) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int small_eq = bbox(mat, mid);
        if (small_eq <= rq)
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        
    }
    return low;
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