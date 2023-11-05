#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    vector<int> res;
    int top = 0; int left = 0;
    int i = 0;
    int rows = MATRIX.size();
    int cols = MATRIX[0].size();
    int bottom = rows - 1; int right = cols - 1;
    while (top <= bottom && left <= right)
    {
        // Row left -> right
        for (int i = left; i <= right; i++)
        {
            res.push_back(MATRIX[top][i]);
        }
        top++;
        // Column top -> bottom
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(MATRIX[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            // row right -> left
            for (int i = right; i >= left; i--)
            {
                res.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        // column bottom -> top
        if (left <= right){
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(MATRIX[i][left]);
            }
            left++;
        }
        // completed one layer
    }
    
    return res;
}

int main()
{
    vector<vector<int>> v = {{1,3,7},{10,12,15},{19,20,21}};
    vector<int> k = spiralMatrix(v);
    cout << "[";
    for (int i = 0; i < k.size() - 1; i++)
    {
       cout << k[i] << ", ";
    }
    cout << k[k.size() - 1] << "]" << endl;
    return 0;
}