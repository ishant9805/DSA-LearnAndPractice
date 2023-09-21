#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& arr, int n){
	for (int i = 0; i < n; i++)
	{
        int j = 0;
		while (j < i)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
            j++;
        }
	}
    return -1;
}

int main()
{
    int j;
    vector<int> v = {1, 2, 7, 9, 10, 8, 9, 15};
    j = findDuplicate(v, v.size());
    cout << j << endl;
    return 0;
}
