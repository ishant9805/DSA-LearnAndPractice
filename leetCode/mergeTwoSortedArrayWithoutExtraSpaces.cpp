#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int> &a, int m, vector<int> &b, int n){
        bool toRmv = false;
        for (int i = 0; i < m; i++)
        {
            if ((toRmv || i == 0) && (a[i] == 0))
            {
                a.erase(a.begin() + i);
                i--;
                m--;
            } else if (a[i] > 0) {
                toRmv = true;
            }
        }
        
        for (auto it:b)
        {
            a.push_back(it);
        }
        sort(a.begin(), a.end());
        // b.clear();
        
    }

int main()
{
    vector<int> v = {2,5,6};
    vector<int> u = {1,2,3,0,0,0};
    // vector<int> v = {1,2,2};
    // vector<int> u = {-1,0,0,3,3,3,0,0,0};
    merge(u, u.size(), v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    cout << "[";
    for (int i = 0; i < u.size() - 1; i++)
    {
       cout << u[i] << ", ";
    }
    cout << u[u.size() - 1] << "]" << endl;
    return 0;
}