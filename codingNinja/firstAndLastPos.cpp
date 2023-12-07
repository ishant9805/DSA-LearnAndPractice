#include<iostream>
#include<vector>

using namespace std;
// Used STL in C++
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans = {-1, -1};
    ans.first = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    ans.second = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
    if(arr[ans.first] != k) {
        ans.first = -1;
    }
    if(arr[ans.second] != k) {
        ans.second = -1;
    }
    return ans;
}


int main()
{
    vector<int> v = {3,4,13,13,13,20,40};
    pair<int, int> k = firstAndLastPosition(v, v.size(), 13);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    v = {0, 0, 1, 1, 2, 2, 2, 2};
    k = firstAndLastPosition(v, v.size(), 2);
    cout << "pair<" << k.first << ", " << k.second << ">" << endl;
    return 0;
}