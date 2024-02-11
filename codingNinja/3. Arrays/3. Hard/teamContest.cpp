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

int cnt = 0;

void diff(vector<int> &nums, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] > 2 * nums[right])
        {
            cnt += mid - left + 1;
            right++;
        } else {
            left++;
        }
        
    }
    
}

// Merge Sort
void merge(vector<int> &nums, int low, int high, int mid) {
    int left = low;
    int right = mid + 1;
    cout << "[";
    for (int i = low; i < mid; i++)
    {
       cout << nums[i] << ", ";
    }
    cout << nums[mid] << "] - ";
    cout << "[";
    for (int i = mid + 1; i < high; i++)
    {
       cout << nums[i] << ", ";
    }
    cout << nums[high] << "]" << endl;
    diff(nums, low, mid, high);
    vector<int> tmp;
    while (left <= mid && right <= high)
    {
        // if (nums[left] > 2*nums[right])
        // {
        //     cout << "Left: " << nums[left] << "; Right: " << nums[right] << endl;
        //     cnt += mid - left + 1;
        // }
        
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

void mergesort(vector<int> &nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(nums, low, mid);
    mergesort(nums, mid + 1, high);
    merge(nums, low, high, mid);
}

// 
int team(vector <int> & skill, int n)
{
    mergesort(skill, 0, skill.size()-1);

    return cnt;
}


int main()
{
    vector<int> v = {4,1,2,3,1};
    int k = team(v, v.size());
    cout << k << endl;
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
       cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << endl;
    return 0;
}