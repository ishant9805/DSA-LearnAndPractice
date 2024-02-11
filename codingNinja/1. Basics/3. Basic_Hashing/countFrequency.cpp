#include<iostream>
#include<vector>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> v(n + 1);
    for (int i = 0; i < nums.size(); i++)
    {
        v[nums[i]]++;
    }
    v.erase(v.begin());
    return v;
}

int main()
{
    int n = 6;
    int x = 4;
    vector<int> v = {1, 3, 4, 3, 4, 1};
    v = countFrequency(n, x, v);
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout <<"]";
    return 0;
}