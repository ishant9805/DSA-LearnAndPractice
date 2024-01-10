#include<bits/stdc++.h>

using namespace std;

bool searchElement(vector<vector<int>> &mat, int target, int j) {
    int high = mat.size() - 1, low = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (mat[mid][j] == target) return true;
        else if (mat[mid][j] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;    
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int colSize = matrix[0].size();
    for (int j = 0; j < colSize; j++)
    {
        if (searchElement(matrix, target, j)) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    bool blbl = searchMatrix(v1, 5) ? "True" : "False";
    cout << blbl << endl;
    return 0;
}