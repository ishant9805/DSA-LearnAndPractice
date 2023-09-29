#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int> &is, int x) {
    for (int i = 0; i < is.size(); i++)
    {
        if (is[i] == x)
        {
            return true;
        }
    }
    return false;
}

int removeDuplicates(vector<int> &arr, int n) {
    int ss = 0;
    vector<int> is;
    for (int i = 0; i < n; i++)
    {
        if (isPresent(is, arr[i]))
        {
            continue;
        }
        else {
            is.push_back(arr[i]);
        }
    }
    ss = is.size();
    for (int i = 0; i < ss; i++)
    {
        arr[i] = is[i];
    }
    return ss;
}

int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(v, v.size());
    cout << k << endl;
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}