#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int singleNonDuplicate(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) continue;
        else return arr[i];
    }
    return arr[0];   
}

int main()
{
    vector<int> v = {1,1,4,4,15};
    cout << singleNonDuplicate(v) << endl;
    return 0;
}