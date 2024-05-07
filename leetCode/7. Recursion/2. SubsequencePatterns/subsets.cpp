#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& s)
{
    vector<vector<int>> res;
    int n = s.size();
    for (int i = 0; i < (1<<n); i++) {
        vector<int> nums;
        for (int j = 0; j < n; j++) {
            // & = AND operator not binary comparison operator
            if (i & (1<<j)) {
                nums.push_back(s[j]);
            }
        }
        res.push_back(nums);
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {1,2,3};
    vector<vector<int>> v1 = subsets(v);
    cout << v1.size() << endl;
    cout << "------Printing Vector------\nVector: {";
    for (int i = 0; i < v1.size() - 1; i++)
    {
        for (int j = 0; j < v1[i].size() - 1; j++)
        {
            cout << v1[i][j];
        }
        cout << v1[i][v1[i].size() - 1] << ",";
    }
    for (int j = 0; j < v1[v1.size() - 1].size() - 1; j++)
    {
        cout << v1[v1.size() - 1][j];
    }
    int v1_sz = v1.size();
    int last_sz = v1[v1_sz-1].size();
    cout << v1[v1_sz-1][last_sz-1] << "}" << endl;
    return 0;
}