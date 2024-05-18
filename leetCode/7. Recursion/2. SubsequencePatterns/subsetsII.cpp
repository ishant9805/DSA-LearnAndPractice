#include<bits/stdc++.h>

using namespace std;

void helper(int index, vector<int> &arr, vector<int> &sums, set<vector<int>> &res) {
    if (index == arr.size()) {
        res.insert(sums);
        return;
    }

    sums.push_back(arr[index]);
    helper(index + 1, arr, sums, res);
    sums.pop_back();

    helper(index + 1, arr, sums, res);
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> result;
    vector<int> sums;
    sort(nums.begin(), nums.end());
    helper(0, nums, sums, result);
    vector<vector<int>> ans;
    for (auto it: result) {
        ans.push_back(it);
    }
    return ans;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,2};
    vector<vector<int>> v2;
    v2 = subsetsWithDup(v1);
    for(auto it: v2) {
        cout << "{ ";
        for(auto iter: it) {
            cout << iter << " ";
        }
        cout << "}";
    }
    cout << endl;
    return 0;
}