#include<iostream>
#include<vector>

using namespace std;

// Brute Force Approach
// int subarrayWithMaxProduct(vector<int> &arr){
// 	// Write your code here.
//     long long maxi = 0;
//     int sz = arr.size();
//     if (sz == 1) return arr[0];
//     for (int i = 0; i < sz; i++)
//     {
//         for (int j = 1; j < sz; j++)
//         {
//             long long prd = 1;
//             for (int k = i; k <= j; k++)
//             {
//                 prd *= arr[k];
//             }
//             if (prd > maxi)
//             {
//                 maxi = prd;
//             }
            
//         }
        
//     }
//     return maxi;
// }

// Intuitive Observation
int subarrayWithMaxProduct(vector<int> &arr){
	// INT_MIN
    long long max_prd = -2147483648;
    long long pre = 1;
    long long suff = 1;
    int sz = arr.size();
    // long long prev_prd = prd;
    for (int i = 0; i < sz; i++)
    {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[sz - i - 1];
        max_prd = max(max_prd, max(pre, suff));
    }
    return max_prd;
}

int main()
{
    int k;
    vector<int> v = {1,-2,3,-4};
    k = subarrayWithMaxProduct(v);
    cout << k << endl;
    v = {-2,3,-4,0,4};
    k = subarrayWithMaxProduct(v);
    cout << k << endl;
    v = {-1, 3, 0, -4, 3};
    k = subarrayWithMaxProduct(v);
    cout << k << endl;
    return 0;
}