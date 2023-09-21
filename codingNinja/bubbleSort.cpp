#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n) 
{
    //write your code here
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }   
        }
    }
}

int main()
{
    int n = 7;
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28};
    bubbleSort(arr, n);
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
       cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << "]" << endl;
    return 0;
}