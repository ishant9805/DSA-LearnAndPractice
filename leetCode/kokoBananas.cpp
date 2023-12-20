#include<iostream>
#include<vector>
#include<numeric>
#include<xutility>

using namespace std;
// using binary search
long long possibility(vector<int> &v, int rate) {
    long long hrs = 0;
    for (int i = 0; i < v.size(); i++)
    {
        hrs += ceil((double)(v[i]) / (double) (rate));
    }
    
    return hrs;
}

int maxEle(vector<int> &v) {
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int minEatingSpeed(vector<int> &v, int h) {
    int high = maxEle(v);
    int low = 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (possibility(v, mid) <= (long long)(h)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> v = {3,6,2,8};
    cout << minEatingSpeed(v, 7) << endl;
    v = {7,15,6,3};
    cout << minEatingSpeed(v, 8) << endl;
    
    return 0;
}