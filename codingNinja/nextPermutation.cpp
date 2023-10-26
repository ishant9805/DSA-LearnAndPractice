#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<int> nextGreaterPermutation(vector<int> &A) {
//     next_permutation(A.begin(), A.end());
//     return A;
// }

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int bp = -1;
    int n = A.size();
    pair<int,int> mini = {1e9, 0};
    for (int i = n - 1; i > 0; i--)
    {
        if (A[i] > A[i-1])
        {
            bp = i - 1;
            break;
        }
        
    }
    if (bp == -1) {
        reverse(A.begin(), A.end());
    } else {
        for (int i = bp + 1; i < n; i++)
        {
            if (mini.first > A[i] && A[i] > A[bp])
            {
                mini.first = A[i];
                mini.second = i;
            }
        }
        swap(A[bp], A[mini.second]);
        reverse(A.begin() + bp + 1, A.end());
    }
    return A;

}

int main()
{
    vector<int> v = {1,3,2};
    v = nextGreaterPermutation(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}