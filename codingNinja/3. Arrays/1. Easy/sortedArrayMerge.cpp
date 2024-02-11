#include<iostream>
#include<vector>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    vector<int> temp;
    int aInt = 0;
    int bInt = 0;
    while (aInt < a.size() && bInt < b.size())
    {
        if (a[aInt] <= b[bInt])
        {
            temp.push_back(a[aInt]);
            aInt++;
        } else {
            temp.push_back(b[bInt]);
            bInt++;
        }     
    }

    while (aInt < a.size())
    {
        temp.push_back(a[aInt]);
        aInt++;
    }
    while (bInt < b.size())
    {
        temp.push_back(b[bInt]);
        bInt++;
    }
    for (int k = aInt + bInt; k > 0; k--)
    {
        if (temp[k] == temp[k - 1])
        {
            temp.erase(temp.begin() + k);
        }
        
    }
    
    return temp;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    vector<int> u = {2,3,3,5};
    v = sortedArray(u, v);
    // v = merger(v, 3);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}