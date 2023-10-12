#include<iostream>
#include<vector>
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
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int wholeSum = 0;
    int partSum = 0;
    int mx = 0;
    for (int i = 0; i < a.size(); i++)
    {
        partSum = 0;
        wholeSum += a[i];
        cout << "i: " << i << " Whole Sum: " << wholeSum << " Part Sum: [";
        for (int j = 0; j <= i; j++)
        {
            partSum += a[j];
            cout << partSum << ",";
            if (wholeSum - partSum == k)
            {
                mx = max(mx, i - j);
            }
        }
        cout << "]" << endl;
    }
    return mx;
}

int main()
{
    // vector<int> v = {1,2,3,1,1,1,1};
    vector<int> v = {1,2,1,3};
    int a = longestSubarrayWithSumK(v, 2);
    cout << a << endl;
    return 0;
}