#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int mx = INT_MIN;
    // vector<int> tmp;
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            sum = 0;
            // cout << "[";
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                // cout << " " << a[k] << ",";
            }
            // cout << "]" << endl;
            if (sum == k)
            {
                mx = max(mx, j - i + 1);
            }
            
        }
        
    }
    return mx;
}

int main()
{
    vector<int> v = {1,2,3,1,1,1,1};
    int a = longestSubarrayWithSumK(v, 3);
    cout << a << endl;
    return 0;
}