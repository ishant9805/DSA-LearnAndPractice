#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int> v) {
	// Write your code here
    unordered_map<int, int> mp;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (mp.find(v[i]) != mp.end())
        {
            mp[v[i]] += 1;
        }
        else {
            mp[v[i]] = 1;
        }
    }
    pair<int, int> max = {0, 0};
    for (auto it:mp)
    {
        if (max.second < it.second)
        {
            max.first = it.first;
            max.second = it.second;
        }
        
    }
    return max.first;
}

int main()
{
    vector<int> v = {2,2,1,3,1,1,3,1,1};
    int n = majorityElement(v);
    cout << n << endl;
    return 0;
}