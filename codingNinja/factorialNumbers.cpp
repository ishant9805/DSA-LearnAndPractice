#include<iostream>
#include<vector>

using namespace std;

vector<long long> factorialNumbers(long long n) 
{
    vector<long long> vec;
    long long ff = 1;
    for (int i = 1; ff * i <= n; i++)
    {
        ff = ff * i;
        vec.push_back(ff);
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