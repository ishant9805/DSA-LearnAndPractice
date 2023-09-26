#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    return {a[1], a[a.size() - 2]};
}

int main()
{
    vector<int> arr = {4, 5, 3, 6, 7};
    vector<int> v = getSecondOrderElements(6, arr);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}