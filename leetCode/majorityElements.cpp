#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Hashmap method
int majorityElementBetter(vector<int> v) {
	// Write your code here
    unordered_map<int, int> mp;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
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

// Moore's Voting Algorithm
int majorityElement(vector<int>& v) {
    // Write your code here
    int el; int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt == 0)
        {
            el = v[i];
        }
        if (v[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    
    return el;
}

int main()
{
    vector<int> v = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n = majorityElement(v);
    cout << n << endl;
    return 0;
}