#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector <int> intOcc;
    int maj = n / 3;
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

int main()
{
    vector<int> v = {3,2,2,1,5,2,3};
    v = majorityElementII(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}