#include<iostream>
#include<vector>
using namespace std;

vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int left = 0; int size = a.size();
    pair<vector<int>, vector<int>> p;
    while (left < size)
    {
        if (a[left] < 0)
        {
            p.first.push_back(a[left]);
        }
        if (a[left] > 0)
        {
            p.second.push_back(a[left]);
        }
        left++;
    }
    a.clear();
    size = min(p.first.size(), p.second.size());
    left = 0;
    while (left < size){
        a.push_back(p.second[left]);
        a.push_back(p.first[left]);
        left++;
    }
    return a;
}

int main()
{
    vector<int> A = {1,2,-3,-1,-2,3};
    A = alternateNumbers(A);
    cout << "[";
    for (int i = 0; i < A.size() - 1; i++)
    {
       cout << A[i] << ", ";
    }
    cout << A[A.size() - 1] << "]" << endl;
    return 0;
}