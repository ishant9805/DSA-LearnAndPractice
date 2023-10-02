#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        if (!(a[i] == 0))
        {
            tmp.push_back(a[i]);
        }
    }
    for (int i = tmp.size(); i < n; i++)
    {
        tmp.push_back(0);
    }
    return tmp;
}

int main()
{
    vector<int> v = {1,2,0,0,2,3};
    v = moveZeros(v.size(), v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}