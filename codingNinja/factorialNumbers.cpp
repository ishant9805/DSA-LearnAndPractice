#include<iostream>
#include<vector>

using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

vector<long long> factorialNumbers(long long n) 
{
    vector<long long> vec;
    for (int i = 1; fact(i) <= n; i++)
    {
        vec.push_back(fact(i));
    }
    
    return vec;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> v;
    v = factorialNumbers(n);
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    
    cout << "]";
    return 0;
}