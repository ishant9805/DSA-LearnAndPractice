#include<iostream>
#include<vector>
using namespace std;

vector<int> gFN(int i, int j, vector<int> vec, int n)
{
    if (vec.size() == n)
    {
        return vec;
    }
    
    vec.push_back(i + j);
    i = j;
    j = vec[vec.size() - 1];
    vec = gFN(i, j, vec, n);
    return vec;
}

int generateFibonacciNumbers(int n) 
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    int sum0 = 0;
    int i = 0;
    int j = 1;
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        vec = gFN(i, j, vec, n);
        sum0 = vec[n - 2] + vec[n - 1];
        return sum0;
    }
}

int main()
{
    int n;
    cin >> n;
    n = generateFibonacciNumbers(n);
    cout << n;    
    return 0;
}