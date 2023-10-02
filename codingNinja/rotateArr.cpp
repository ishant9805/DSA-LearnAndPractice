#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    vector<int> tmp;
    int n = arr.size();
    for (int i = k; i < n; i++) {
        tmp.push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        tmp.push_back(arr[i]);
    }
    return tmp;
}

int main()
{
    vector<int> v = {7, 5, 2, 11, 2, 43, 1, 1};
    v = rotateArray(v, 2);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}