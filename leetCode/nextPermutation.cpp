#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<int> nextPermutation(vector<int> &A) {
//     next_permutation(A.begin(), A.end());
//     return A;
// }

// Trying to solve
vector<int> nextPermutation(vector<int> &A)
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
        for (int i = n-1; i > bp; i--)
        {
            if (A[i] > A[bp])
            {
                swap(A[i], A[bp]);
                break;
            }
        }
        reverse(A.begin() + bp + 1, A.end());
    }
    return A;

}

int main()
{
    vector<int> v = {2,1,5,4,3,0,0}; //[2, 3, 0, 0, 1, 4, 5]
    v = nextPermutation(v);
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}