#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// vector<int> superiorElements(vector<int>&a) {
//     // Write your code here.
//     set<int> res;
//     int sz = a.size();
//     for (int i = 0; i < sz; i++)
//     {
//         bool isSup = true;
//         for (int j = i; j < sz; j++)
//         {
//             if (a[i] < a[j])
//             {
//                 isSup = false;
//                 break;
//             }
//         }
//         if (isSup) res.insert(a[i]);
//     }
//     a.clear();
//     for (auto it: res) {
//         a.push_back(it);
//     }
//     return a;
// }

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int sz = a.size();
    int max = a[sz - 1];
    vector<int> ldrs;
    ldrs.push_back(max);
    for (int i = sz - 1; i >= 0; i--)
    {
        if (a[i] > max)
        {
            max = a[i];
            ldrs.push_back(a[i]);
        }
        
    }
    return ldrs;
}

int main()
{
    vector<int> v = {1,2,2,1};
    v = superiorElements(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}