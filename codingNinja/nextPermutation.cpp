#include<iostream>
#include<vector>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    
}

int main()
{
    vector<int> v = {1,3,2};
    v = nextGreaterPermutation(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}