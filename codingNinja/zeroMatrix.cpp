#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
    set<int> ss;
    set<int> ii;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
               ss.insert(i);
               ii.insert(j); 
            }
            
        }
        
    }
    for (auto it:ss)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[it][i] = 0;
        }
        
    }
    for (auto it:ii)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][it] = 0;
        }
        
    }
    return matrix;
}

int main()
{
    vector<vector<int>> v = {{2, 4, 3}, {1, 0, 0}};
    int rowSize = v.size();
    int colSize = v[0].size();
    v = zeroMatrix(v, rowSize, colSize);
    cout << "[";
    for (int i = 0; i < rowSize - 1; i++)
    {
       cout << "[";
       for (int j = 0; j < colSize - 1; j++)
       {
          cout << v[i][j] << ", ";
       }
       cout << v[i][colSize - 1] << "]" << endl;
    }
    cout << "[";
    for (int i = 0; i < colSize - 1; i++)
    {
       cout << v[rowSize - 1][i] << ", ";
    }
    cout << v[rowSize - 1][colSize - 1] << "]]" << endl;
    return 0;
}