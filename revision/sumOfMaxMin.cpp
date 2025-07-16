#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sumOfMaxMin(int arr[], int n){
	// Write your code here.
	int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return max+min;

}

int main()
{
    int arr[] = { -1, -4, 5, 8, 9, 3 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    cout << "Result: " << sumOfMaxMin(arr, 6) << endl;
    
    
    return 0;
}