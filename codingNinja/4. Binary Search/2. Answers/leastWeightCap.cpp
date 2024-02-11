#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool possi(vector<int> &weights, int d, int cap) {
    int tmp = 0;
    int i;
    for (i = 0; i < weights.size(); i++) {
        tmp += weights[i];
        if (tmp == cap) {
            d--;
            tmp = 0;
        } else if (tmp > cap) {
            i--;
            tmp = 0;
            d--;
        }
        if (d <= 0) {
            break;
        }
    }
    if (d < 0) return false;
    else if (d == 0 && i == weights.size() - 1) return true;
    else if (d > 0) return true;
    return false;
}

// Brute force method
// int leastWeightCapacity(vector<int> &weights, int d) {
//     // Write your code here.
//     int maxi = *max_element(weights.begin(), weights.end());
//     while (true) {
//         if (possi(weights, d, maxi)) {
//             return maxi;
//         } 
//         else {
//             maxi++;
//         }
//     }
//     return -1;
// }

// Binary Search
int leastWeightCapacity(vector<int> &weights, int d) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possi(weights, d, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        
    }
    return low;
}

int main()
{
    vector<int> v = {5,4,5,2,3,4,5,6};
    cout << leastWeightCapacity(v, 5) << endl;
    vector<int> v2 = {1,2,3,4,5,6,7,8,9,10};
    cout << leastWeightCapacity(v2, 1) << endl;
    return 0;
}