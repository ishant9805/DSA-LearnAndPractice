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

vector<int> generateFibonacciNumbers(int n) 
{
    vector<int> vec;
    vec.push_back(0);
    if (n == 1)
    {
        return vec;
    }
    
    vec.push_back(1);
    int i = 0;
    int j = 1;
    if (n == 1)
    {
        return vec;
    }
    else
    {
        vec = gFN(i, j, vec, n);
        return vec;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v = generateFibonacciNumbers(n);
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]" << endl;
    
    return 0;
}