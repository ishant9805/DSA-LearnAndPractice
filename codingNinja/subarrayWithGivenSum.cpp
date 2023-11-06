#include<iostream>
#include<vector>

using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int num = 0;
    int left = 0, right = 1;
    int summ = 0;
    while (left <= right && right < arr.size())
    {
        summ = 0;
        // 6 3 5 2
        for (int i = left; i <= right; i++)
        {
            summ += arr[i];
            if (summ == k) {
                num++;
                left++;
                right++;
            } else if (summ > k)
            {
                left++;
            }
            
        }
        right++;
    }
    
    return num;
}

int main()
{
    vector<int> v = {6,3,5,2};
    int k;
    k = findAllSubarraysWithGivenSum(v, 9);
    cout << k << endl;
    return 0;
}