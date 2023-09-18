#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> getFrequencies(vector<int>& v) {
    vector<int> res;
    cout << "[";
    
    return res;
}

int main()
{
    int n = 6;
    vector<int> v = {1,2,3,1,1,4};
    v = getFrequencies(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] <<", ";
    }
    cout << v[v.size() - 1] << "]";
    return 0;
}