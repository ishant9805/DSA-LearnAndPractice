#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.begin()+n);
    return {arr[k-1], arr[n-k]};
}


int main()
{
    vector<int> arr = { 1,2,5,4 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    vector<int> v = kthSmallLarge(arr, 4, 3);
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}