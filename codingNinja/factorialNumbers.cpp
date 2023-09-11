#include<iostream>
#include<vector>

using namespace std;

vector<long long> fact(long long n, vector<long long> v) 
{
    vector<long long> vec;
    if (n == 1)
    {
        vec.push_back(1);
        return vec;
    }
    else 
    {
        
    }
    return vec;
}

vector<long long> factorialNumbers(long long n) 
{
    vector<long long> vec;
    long long int mnc = 1;
    vec = fact(mnc, vec);
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