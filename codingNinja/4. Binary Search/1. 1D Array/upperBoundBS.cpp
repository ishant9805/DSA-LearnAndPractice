#include<iostream>
#include<vector>

using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	int low = 0; // 1 2 5 6 10
    int high = n - 1;
    int mid;
    int ans = n;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1,2,5,6,10};
    int k = upperBound(v, 10, v.size()); // 5
    cout << k << endl;
    v = {1,4,7,8,10};
    k = upperBound(v, 7, v.size()); // 3
    cout << k << endl;
    v = {1,5,5,7,7,9,10};
    k = upperBound(v, 5, v.size()); // 3
    cout << k << endl;
    v = {5, 12, 12, 15, 18, 21, 35, 37, 38, 46, 47, 48, 48, 50};
    k = upperBound(v, 45, v.size()); // 3
    cout << k << endl;
    v = {2, 5, 6, 19, 24, 25, 26, 26, 32, 42, 44};
    k = upperBound(v, 42, v.size()); // 3
    cout << k << endl;
    v = {0, 0, 1, 1, 2, 2, 2, 2};
    k = upperBound(v, 2, v.size());
    cout << k << endl;
    
    return 0;
}