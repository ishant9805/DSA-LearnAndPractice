#include<iostream>
#include<vector>
using namespace std;

// Kadane's Algo
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long max_sum = arr[0];
    int sum = 0;
    for (int a = 0; a < n; a++)
    {
        sum += arr[a];
        if (sum > max_sum) max_sum = sum;
        if (sum < 0) sum = 0;
    }
    if (max_sum <= 0) return 0;
    return max_sum;
}

int main()
{
    vector<int> v = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    long long it = maxSubarraySum(v, v.size());
    cout << it << endl;
    return 0;
}