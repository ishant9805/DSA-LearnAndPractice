#include<iostream>
#include<vector>
using namespace std;

int getSingleElement(vector<int> &arr){
	int x;
    bool done = false;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] != arr[i-1] && arr[i] != arr[i + 1])
        {
            x = arr[i];
            done = true;
        }
        
    }
    if (done)
        return x;
    return arr[arr.size() - 1];
}

int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4,4};
    int x = getSingleElement(arr);
    cout << x << endl;
    return 0;
}