#include<bits/stdc++.h>

using namespace std;

// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
// {
//     int maxCnt = 0, row = -1;
//     for (int i = 0; i < n; i++) {
//         int cnt = 0;
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 1) {
//                 cnt++;
//             }
//         }
//         if (cnt > maxCnt) {
//             maxCnt = cnt;
//             row = i;
//         }
//     }
//     return row;
// }

// Binary Search
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int maxCnt = 0, row = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int low = 0, high = m - 1;
        if (matrix[i][low] == 1) return i;
        if (matrix[i][high] == 0) continue;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (matrix[i][mid] == 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
                cnt = m - mid;
            }
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            row = i;
        }
    }
    return row;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {{ 1,  1,  1 }, { 0,  0,  1 }, { 0,  0,  0 }};
    cout << rowWithMax1s(v1, v1.size(), v1[0].size()) << endl;
    return 0;
}