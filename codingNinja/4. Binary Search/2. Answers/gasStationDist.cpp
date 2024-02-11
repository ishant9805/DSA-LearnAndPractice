#include<bits/stdc++.h>

using namespace std;
// Priority Queue method
// double minimiseMaxDistance(vector<int> &arr, int k){
//     int n = arr.size();
//     vector<int> howMany(n-1, 0);
//     priority_queue<pair<long double, int>> pq;
// 	for (int i = 0; i < n - 1; i++)
//     {
//         pq.push({arr[i+1] - arr[i], i});
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         auto tp = pq.top(); pq.pop();
//         int secIndex = tp.second;
//         howMany[secIndex]++;
//         long double initDiff = arr[secIndex + 1] - arr[secIndex];
//         long double newLen = initDiff / (long double) (howMany[secIndex] + 1);
//         pq.push({newLen, secIndex});
//     }
    
//     return pq.top().first;
// }

// Binary Search Method
int maxDiff(vector<int> &arr, int sz) {
    int ans = INT_MIN;
    for (int i = 0; i < sz - 1; i++)
    {
        int diff = arr[i+1] - arr[i];
        ans = max(ans, diff);
    }
    return ans;
}

int check(vector<int> &vec, long double dist) {
    int cnt = 0;
    for (int i = 1; i < vec.size(); i++) {
        int numInBet = ((vec[i] - vec[i-1]) / dist);
        if (vec[i] - vec[i-1] / dist == numInBet * dist) {
            numInBet--;
        }
        cnt += numInBet;
    }
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0, high = maxDiff(arr, n);
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (high + low) / (2.0);
        int cnt = check(arr, mid);
        if (cnt > k)
        {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5,6,7};
    cout << minimiseMaxDistance(v1, 6) << endl;
    vector<int> v2 = {1,13,17,23};
    cout << minimiseMaxDistance(v2, 5) << endl;
    return 0;
}