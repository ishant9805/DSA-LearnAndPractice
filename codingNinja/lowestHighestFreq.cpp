#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> getFrequencies(vector<int>& v) {
    pair<int, int> max = {0, 0};
    pair<int, int> min = {0, 999};
    unordered_map<int, int> umpp;
    for (int i = 0; i < v.size(); i++)
    {
        umpp[v[i]]++;
    }
    for(auto it : umpp)
    {
        if (max.second <= it.second)
        {
            if (max.second == it.second)
            {
                if (max.first > it.first)
                {
                    max.first = it.first;
                }
                
            } else {            
                max.first = it.first;
                max.second = it.second;
            }
        }
        if (min.second >= it.second)
        {
            if (min.second == it.second)
            {
                if (min.first > it.first)
                {
                    min.first = it.first;
                }

            } else { 
                min.first = it.first;
                min.second = it.second;
            }
        }
        
    }
    return {max.first, min.first};
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