#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int> &is, int x) {
    for (int i = 0; i < is.size(); i++)
    {
        if (is[i] == x)
        {
            return true;
        }
    }
    return false;
}

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int ss = 0;
    vector<int> is;
    for (int i = 0; i < n; i++)
    {
        if (isPresent(is, arr[i]))
        {
            continue;
        }
        else {
            is.push_back(arr[i]);
        }
    }
    return is.size();
}

int main()
{
    vector<int> v = {1,3,1,4,2};
    int k = removeDuplicates(v, v.size());
    cout << k << endl;
    return 0;
}