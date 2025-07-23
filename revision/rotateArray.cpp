#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    k = k % arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
    return arr;
}


int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 }; 
    v = rotateArray(v, 3);
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}