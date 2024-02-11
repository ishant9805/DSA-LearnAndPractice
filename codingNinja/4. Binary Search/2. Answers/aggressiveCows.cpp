#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPoss(vector<int> &stalls, int a, int k) {
    int prevS = 0;
    k--;
    for (int i = 1; i < stalls.size(); i++)
    {
        int diff = stalls[i] - stalls[prevS];
        if(diff >= a) {
            prevS = i; //0 3 4 7 9 10
            k--;
        }
    }
    if (k < 1)
    {
        return true;
    }
    return false;
}
// Brute force
// int aggressiveCows(vector<int> &stalls, int k) {
//     sort(stalls.begin(), stalls.end());
//     int maxa = stalls[stalls.size() - 1];
//     for (int i = 1; i < maxa; i++)
//     {
//         if (isPoss(stalls, i, k))
//         {
//             continue;
//         }
//         return i - 1;
//     }
//     return maxa - 1;
// }

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int high = stalls[stalls.size() - 1];
    int low = 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (isPoss(stalls, mid, k))
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> v = {1,2,3};
    cout << aggressiveCows(v, 2) << endl;
    vector<int> v2 = {0,3,4,7,10,9};
    cout << aggressiveCows(v2, 4) << endl;
    return 0;
}