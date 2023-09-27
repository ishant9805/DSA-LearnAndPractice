#include<iostream>
#include<vector>
using namespace std;

// vector<int> rotate(vector<int>& nums, int rotNum)
// {
//     vector<int> rot(nums.size());
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int k = i + rotNum;
//         if (k < nums.size())
//         {
//             rot[i] = nums[k];
//         }
//         else{
//             k = k - nums.size();
//             rot[i] = nums[k];
//         }
        
//     }
//     return rot;
// }

// bool isSorted(vector<int> a) {
//     for (int i = 0; i < a.size() - 1; i++)
//     {
//         if (!(a[i] <= a[i + 1]))
//         {
//             return false;
//         }
        
//     }
//     return true;
// }

// bool check(vector<int>& nums) {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         vector<int> temp;
//         temp = rotate(nums, i);
//         if (isSorted(temp))
//         {
//             return true;
//         }
        
//     }
//     return false;
// }

bool isSorted(vector<int> a) {
    int c = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            c++;
        }
    }

    if (a[0] < a[a.size() - 1])
    {
        c++;
    }
    

    return c <= 1;
}

// bool check(vector<int>& a) {
//     int i = 0;
//     while (i < a.size())
//     {
//         vector<int> temp;
//         temp = rotate(a, i);
//         if (!isSorted(temp))
//         {
//             i++;
//         }
//         else {
//             return true;
//         }

//     }
//     return false;
// }


int main()
{
    vector<int> v = {3,4,1,5,2};
    bool k = isSorted(v);
    cout << k << endl;
    return 0;
}