#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            if (cnt >= max)
            {
                max = cnt;
            }
        }
        else 
        {
            cnt = 0;
        }
    }
    return max;
}

int main()
{
    vector<int> arr = {1,1,0,1,1,1};
    int x = findMaxConsecutiveOnes(arr);
    cout << x << endl;
    return 0;
}