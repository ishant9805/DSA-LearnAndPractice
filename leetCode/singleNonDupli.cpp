#include<iostream>
#include<vector>

using namespace std;

// Brute Force
int singleNonDuplicate(vector<int>& arr) {
    // when size > 1 and the first element is single
    if (arr.size() > 1 && arr[0] != arr[1]) {
        return arr[0];
    }
    // when any element is single till size - 2
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) continue;
        else return arr[i];
    }
    // if none of elements are single till size - 2 then arr[size - 1] is single
    return arr[arr.size() - 1];   
}

int main()
{
    vector<int> v = {1,1,4,4,15};
    cout << singleNonDuplicate(v) << endl;
    return 0;
}