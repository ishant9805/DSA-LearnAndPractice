#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int sz = a.size();
    int tot = (sz * (sz - 1)) / 2;
    int actSum = accumulate(a.begin(), a.end(), 0);
    int ab = actSum - tot;
    // sz = 4, tot = 6, actSum = 9, ab = 3
    return {ab, ab};
}

int main()
{
    vector<int> v = {1, 2, 3, 2};
    v = findMissingRepeatingNumbers(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}