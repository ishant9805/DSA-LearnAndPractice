#include<bits/stdc++.h>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &g){
    int rowSz = g.size();
    int colSz = g[0].size();
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {{8, 6}, {10, 1}};
    vector<int> vv1 = findPeakGrid(v1);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < vv1.size() - 1; i++)
    {
        cout << vv1[i] << ", ";
    }
    cout << vv1[vv1.size() - 1] << "}" << endl;
    vector<vector<int>> v2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vv2 = findPeakGrid(v2);
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < vv2.size() - 1; i++)
    {
        cout << vv2[i] << ", ";
    }
    cout << vv2[vv2.size() - 1] << "}" << endl;
    return 0;
}