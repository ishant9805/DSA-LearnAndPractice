#include<iostream>
#include<vector>
using namespace std;


vector<int> printNos(int x) 
{
    int n = x;
    vector<int> res;
    vector<int> tmp;
    if (n < 1)
    {
        return res;
    }
    res.push_back(n);
    tmp = printNos(n-1);
    for (int i = 0; i < tmp.size(); i++)
    {
        res.push_back(tmp[i]);
    }
    return res;
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