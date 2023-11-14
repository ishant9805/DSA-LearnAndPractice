#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int sz = nums.size();
    set<vector<int>> res;
    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < sz; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - (sum);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> tmp = {nums[i], nums[j], nums[k], (int) fourth};
                    sort(tmp.begin(), tmp.end());
                    res.insert(tmp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> v(res.begin(), res.end());
    return v;
}

int main()
{
    vector<int> v = {2,2,2,2,1,3};
    vector<vector<int>> mat = fourSum(v, 8);
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