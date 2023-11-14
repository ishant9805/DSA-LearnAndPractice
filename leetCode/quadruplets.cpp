#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < sz; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < sz; j++)
        {
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
            int k = j + 1, l = sz - 1;
            while (k < l)
            {
                long long sum = static_cast<long long> (nums[i]) + nums[j] + nums[k] + nums[l];
                if (sum > target) l--;
                else if (sum < target) k++;
                else {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++, l--;
                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                }
                
            }
            
        }
        
    }
    return res;
}

int main()
{
    vector<int> v = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> mat = fourSum(v, 0);
    if (mat.size() == 0) {
        cout << "Size: 0" << endl;
        return 0;
    }
    int rowSize = mat.size();
    int colSize = mat[0].size();
    cout << "[";
    for (int i = 0; i < rowSize - 1; i++)
    {
        cout << "[";
        for (int j = 0; j < colSize - 1; j++)
        {
            cout << mat[i][j] << ", ";
        }
        cout << mat[i][colSize - 1] << "]" << endl << " ";
    }
    cout << "[";
    for (int i = 0; i < colSize - 1; i++)
    {
        cout << mat[rowSize - 1][i] << ", ";
    }
    cout << mat[rowSize - 1][colSize - 1] << "]]" << endl;
    return 0;
}