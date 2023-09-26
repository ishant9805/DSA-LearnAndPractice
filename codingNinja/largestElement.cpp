#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int max = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    return max;
}

int main()
{
    vector<int> arr = {4, 7, 8, 6, 7, 6};
    int max = largestElement(arr, 6);
    cout << max << endl;
    return 0;
}