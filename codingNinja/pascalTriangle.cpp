#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans = {{1}};
    for (int i = 1; i <= N; i++)
    {
        vector<int> jj = {1};
        for (int j = 0; j < ans[i -1].size() -1; j++)
        {
            jj.push_back(ans[i-1][j]+ans[i-1][j+1]);
        }
        jj.push_back(1);
        ans.push_back(jj);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v = pascalTriangle(n);

    int rowSize = v.size();
    cout << "[";
    for (int i = 0; i < rowSize - 1; i++)
    {
        cout << "[";
        int colSize = v[i].size();

        for (int j = 0; j < colSize - 1; j++)
        {
            cout << v[i][j] << ", ";
        }
        cout << v[i][colSize - 1] << "]" << endl << " ";
    }
    cout << "[";
    for (int i = 0; i < v[rowSize - 1].size() - 1; i++)
    {
        cout << v[rowSize - 1][i] << ", ";
    }
    cout << v[rowSize - 1][v[rowSize - 1].size() - 1] << "]]" << endl;
    
    return 0;
}