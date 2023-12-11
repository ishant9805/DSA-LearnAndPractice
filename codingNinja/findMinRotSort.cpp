#include<iostream>
#include<vector>

using namespace std;

// Brute force method
int findMin(vector<int>& arr) {
	int min = 1e9;
    for (int i = 0; i < arr.size(); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        
    }
    return min;
}
int main()
{
    vector<int> v = {3, 4, 1, 2};
    cout << findMin(v) << endl;
    return 0;
}