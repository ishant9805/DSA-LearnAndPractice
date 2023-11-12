#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> majorityElement(vector<int> v) {
	// Write your code here
    int ss = v.size();
    int maj = floor(ss/3);
    unordered_map<int,int> umpp;
    for (int i = 0; i < ss; i++) // {2,2,1,3,1,1,3,1,1}
    {
        umpp[v[i]] += 1;
    }
    v.clear();
    for (auto it:umpp)
    {
        if (it.second > maj)
        {
            v.push_back(it.first);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    vector<int> v = {2,2,1,3,1,1,3,1,1};
    // vector<int> v = {1,1,1,2,2,2};
    // vector<int> v = {4};
    v = majorityElement(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}