#include<iostream>
#include<vector>

using namespace std;
// Used BS like in upper and lower bound
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans = {-1, -1};
    int low = 0, high = n - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            high = mid;
            ans.first = mid;
        } else {
            low = mid + 1;
        }
        
    }
    cout << "Low: " << low << endl;
    for (int i = low; i < n && i > 0; i++)
    {
        if (arr[i] != k)
        {
            ans.second = i - 1;
        } else {
            ans.second = i;
        }
        
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