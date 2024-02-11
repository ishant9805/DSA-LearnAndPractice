#include<iostream>
#include<vector>
using namespace std;

int partitionArray(int input[], int start, int end) {
	int pivot = input[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (input[i] <= pivot && i < end)
        {
            i++;
        }
        while (input[j] >= pivot && j > start)
        {
            j--;
        }
        if (i < j)
        {
            // cout << "input[i]: " << input[i] << " | input[j]: " << input[j] << endl;
            swap(input[i], input[j]);
        }
    }
    // cout << "[Outside Loop] input[i]: " << input[i] << " | input[j]: " << input[j] << endl;
    swap(input[start], input[j]);
    // cout << "i: " << i << " | j: " << j << endl;
    return j;
}

void quickSort(int input[], int start, int end) {
    if (start < end)
    {
        int pIndex = partitionArray(input, start, end);
        quickSort(input, start, pIndex - 1);
        quickSort(input, pIndex + 1, end);
    }
    
}

int main()
{
    int arr[6] = {2, 6, 8, 5, 4, 3};
    quickSort(arr, 0, 5);
    cout << "[";
    for (int i = 0; i < 5; i++)
    {
       cout << arr[i] << ", ";
    }
    cout << arr[5] << "]" << endl;
    return 0;
}