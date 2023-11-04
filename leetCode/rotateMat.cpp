#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>> &mat){
	// Write your code here.
    int n = mat.size();
    vector<vector<int>> new_mat(n);
    for (int coli = 0; coli < n; coli++)
    {
        for (int row = n - 1; row >= 0; row--)
        {
            new_mat[coli].push_back(mat[row][coli]);
        }
    }
    for (int rowi = 0; rowi < n; rowi++)
    {
        for (int icol = 0; icol < n; icol++)
        {
            mat[rowi][icol] = new_mat[rowi][icol];
        }
        
    } 
}
// 1 2 3    7 4 1
// 4 5 6 -> 8 5 2
// 7 8 9    9 6 3
int main()
{
    vector<vector<int>> k = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(k);
    int arowSize = k.size();
    int bcolSize = k[0].size();
    cout << "[";
    for (int i = 0; i < arowSize - 1; i++)
    {
    cout << "[";
    for (int j = 0; j < bcolSize - 1; j++)
    {
        cout << k[i][j] << ", ";
    }
    cout << k[i][bcolSize - 1] << "]" << endl << " ";
    }
    cout << "[";
    for (int i = 0; i < bcolSize - 1; i++)
    {
    cout << k[arowSize - 1][i] << ", ";
    }
    cout << k[arowSize - 1][bcolSize - 1] << "]]" << endl;
    return 0;
}