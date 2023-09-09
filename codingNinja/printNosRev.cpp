#include<iostream>
#include<vector>
using namespace std;

vector<int> printNos(int x) 
{
    int n = 1;
    vector<int> res;
    vector<int> tmp;
    if (x != n)
    {
        res = printNos(n + 1);
        res.push_back(n);
        return res;
    }
    else
    {
        res.push_back(1);
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