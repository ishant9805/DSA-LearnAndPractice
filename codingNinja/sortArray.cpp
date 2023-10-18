#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(vector<int>& arr, int n)
{
    sort(arr.begin(), arr.end());
}

int main()
{
    vector<int> v = {2,2,2,2,0,0,1,0};
    sortArray(v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}