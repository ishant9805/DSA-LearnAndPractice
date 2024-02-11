#include<bits/stdc++.h>

using namespace std;

// bool searchMatrix(vector<vector<int>>& mat, int target) {
//     int rowSize = mat.size(), colSize = mat[0].size();
//     // BS on rows
//     int low = 0, high = rowSize - 1;
//     while (low <= high) {
//         int mid = (low + high) >> 1;
//         int innerLow = 0, innerHigh = colSize - 1;
//         if (mat[mid][innerLow] <= target && mat[mid][innerHigh] >= target) {
//             // BS on each elements of row
//             while (innerLow <= innerHigh) {
//                 int innerMid = (innerLow + innerHigh) >> 1;
//                 if (mat[mid][innerMid] == target) {
//                     return true;
//                 } else if (mat[mid][innerMid] < target) {
//                     innerLow = innerMid + 1;
//                 } else {
//                     innerHigh = innerMid - 1;
//                 }
//             }
//         } else if (mat[mid][innerLow] > target) {
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return false;
// }

// Flatten then apply binary search
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rowS = matrix.size(), colS = matrix[0].size();
    int low = 0, high = (rowS * colS) - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int midR = mid / colS;
        int midC = mid % colS;
        if (matrix[midR][midC] == target) {
            return true;
        } else if (matrix[midR][midC] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << searchMatrix(v1, 8) << endl;
    return 0;
}