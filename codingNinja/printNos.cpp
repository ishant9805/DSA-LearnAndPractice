#include<iostream>
#include<vector>
using namespace std;

vector<int> printNos(int x) 
{
    vector<int> res;
    if (x == 1)
    {
        res.push_back(1);
        return res;
    }
    else
    {
        res = printNos(x - 1);
        res.push_back(x);
        return res;
    }
    
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