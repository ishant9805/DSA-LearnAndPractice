#include<iostream>
#include<vector>
using namespace std;

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i < j && a[i] > a[j])
            {
                res++;
            }
            
        }
        
    }
    return res;
}

int main()
{
    vector<int> v = {5,3,2,1,4};
    int k = numberOfInversions(v, v.size());
    cout << "K: " << k << endl;
    return 0;
}