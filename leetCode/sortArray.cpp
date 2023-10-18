#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Naive Approach
// void sortArray(vector<int>& arr, int n)
// {
//     sort(arr.begin(), arr.end());
// }

// Three pointer approach
void sortArray(vector<int>& arr, int n)
{
    int zeroPos = 0; int onePos = 0; int twoPos = n - 1;
    while (onePos <= twoPos)
    {
        if (arr[onePos] == 0)
        {
            swap(arr[onePos], arr[zeroPos]);
            onePos++;
            zeroPos++;
        }
        else if (arr[onePos] == 1) onePos++;
        else if (arr[onePos] == 2)
        {
            swap(arr[onePos], arr[twoPos]);
            twoPos--;
        }
        
    }
    
}

int main()
{
    vector<int> v = {2,2,2,2,0,0,1,0};
    sortArray(v, v.size());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}