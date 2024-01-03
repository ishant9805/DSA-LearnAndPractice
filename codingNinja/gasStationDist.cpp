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
double minimiseMaxDistance(vector<int> &arr, int k) {

}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5,6,7};
    cout << minimiseMaxDistance(v1, 6) << endl;
    vector<int> v2 = {1,13,17,23};
    cout << minimiseMaxDistance(v2, 5) << endl;
    return 0;
}