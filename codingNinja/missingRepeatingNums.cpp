#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    auto bg = a.begin();
    int sz = a.size();
    sort(bg, bg+sz); //O(nlogn)
    vector<int> ans;
    int actSum = accumulate(bg, bg+sz, 0);
    int totSum = ((sz) * (sz + 1))/2;
    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i + 1] == a[i])
        {
            ans.push_back(a[i]);
            ans.push_back(totSum-(actSum-a[i]));
            break;
        }
        
    }
    
    return ans;
}

int main()
{
    vector<int> v = {4,3,6,2,1,1};
    v = findMissingRepeatingNumbers(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}