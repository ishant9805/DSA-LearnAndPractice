#include<iostream>
#include<vector>
using namespace std;

// Kadane's Algo
int maxSubarraySum(vector<int> arr)
{
    // Write your code here.
    int max_sum = arr[0];
    int sum = 0;
    for (int a = 0; a < arr.size(); a++)
    {
        sum += arr[a];
        if (sum > max_sum) max_sum = sum;
        if (sum < 0) sum = 0;
    }
    return max_sum;
}

int main()
{
    vector<int> v = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    long long it = maxSubarraySum(v);
    cout << it << endl;
    return 0;
}