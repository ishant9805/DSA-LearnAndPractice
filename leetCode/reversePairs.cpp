#include<iostream>
#include<vector>

using namespace std;
// Brute force approach
// int team(vector <int> & skill, int n)
// {
//     // Write your code here.
//     int rs = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (skill[i] > 2 * skill[j])
//             {
//                 rs++;
//             }
//         }   
//     }
//     return rs;
// }

// int cnt = 0;

int diff(vector<int> &nums, int low, int mid, int high) {
    int prs = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] > 2 * nums[right])
        {
            prs += mid - left + 1;
            right++;
        } else {
            left++;
        }
        
    }
    return prs;
}

// Merge Sort
void merge(vector<int> &nums, int low, int high, int mid) {
    int left = low;
    int right = mid + 1;
    vector<int> tmp;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            tmp.push_back(nums[left]);
            left++;
        } else {
            tmp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        tmp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        tmp.push_back(nums[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        nums[i] = tmp[i-low];
    }
        
}

int mergesort(vector<int> &nums, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergesort(nums, low, mid);
    cnt += mergesort(nums, mid + 1, high);
    cnt += diff(nums, low, mid, high);
    merge(nums, low, high, mid);
    return cnt;
}

// 
int reversePairs(vector <int> & skill, int n)
{
    int knt = mergesort(skill, 0, skill.size()-1);
    return knt;
}


int main()
{
    vector<int> v = {4,1,2,3,1};
    int k = reversePairs(v, v.size());
    cout << k << endl;
    return 0;
}