#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
    int s = b.size();
	for (auto it:b)
    {
        a.push_back(it);
    }
    sort(a.begin(), a.end());
    b.clear();
    int i = a.size() - s;
    while (i < a.size())
    {
        b.push_back(a[i]);
        a.erase(a.begin()+i);
    }
}

int main()
{
    vector<long long> v = {1,8,8};
    vector<long long> u = {2,3,4,5};
    mergeTwoSortedArraysWithoutExtraSpace(u, v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    cout << "[";
    for (int i = 0; i < u.size() - 1; i++)
    {
       cout << u[i] << ", ";
    }
    cout << u[u.size() - 1] << "]" << endl;
    return 0;
}