#include<iostream>
#include<vector>
using namespace std;

void custom(int i, vector<int> &vec)
{
    if (i == 0)
    {
        return;
    }
    vec.push_back(i);
    custom(i - 1, vec);
    return;    
}

vector<int> printNos(int x) 
{
    vector<int> v;
    custom(x, v);
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p;
    p = printNos(n);
    cout << "[";
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << ",";
    }
    cout << "]";
    
    return 0;
}