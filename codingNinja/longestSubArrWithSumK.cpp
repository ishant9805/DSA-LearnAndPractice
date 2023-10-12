#include<iostream>
#include<vector>
#include<map>
using namespace std;

// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     // Write your code here
//     int mx = INT_MIN;
//     // vector<int> tmp;
//     int sum = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         for (int j = i; j < a.size(); j++)
//         {
//             sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum += a[k];
//             }
//             if (sum == k)
//             {
//                 mx = max(mx, j - i + 1);
//             }
            
//         }
        
//     }
//     return mx;
// }

// Trying other method
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int wholeSum = 0;
//     int partSum = 0;
//     int mx = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         partSum = 0;
//         wholeSum += a[i];
//         cout << "i: " << i << " Whole Sum: " << wholeSum << " Part Sum: [";
//         for (int j = 0; j <= i; j++)
//         {
//             partSum += a[j];
//             cout << partSum << ",";
//             if (wholeSum - partSum == k)
//             {
//                 mx = max(mx, i - j);
//             }
//         }
//         cout << "]" << endl;
//     }
//     return mx;
// }

// A more better approach
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     // Write your code here
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         sum += a[i];
//         if (sum == k)
//         {
//             maxLen = max(maxLen, i + 1);
//         }
//         long long rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if (preSumMap.find(sum) == preSumMap.end())
//         {
//             preSumMap[sum] = i;
//         }
//     }
//     return maxLen;
// }


// Trying two pointer method
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int p1 = 0;
    int p2 = 0;
    int sum = a[0];
    int maxLen = 0;
    int size = a.size();
    while (p1 < size && p2 < size)
    {
        while (p2 <= p1 && sum > k)
        {
            sum -= a[p2];
            p2++;
        }
        if (sum == k) maxLen = max(maxLen, p1 - p2 + 1);
        p1++;
        if (p1 < size) sum += a[p1];
    }
    return maxLen;
}

int main()
{
    // vector<int> v = {1,2,3,1,1,1,1};
    vector<int> v = {1,2,1,3};
    int a = longestSubarrayWithSumK(v, 2);
    cout << a << endl;
    return 0;
}