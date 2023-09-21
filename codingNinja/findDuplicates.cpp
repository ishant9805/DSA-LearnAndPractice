#include<iostream>
#include<vector>
#include<array>
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

// int findDuplicate(vector<int>& arr, int n)
// {
//     int hashArray[n] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         hashArray[arr[i]]++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (hashArray[i] > 1)
//         {
//             return i;
//         }
        
//     }
    
// }

int main()
{
    int j;
    vector<int> v = {1, 2, 7, 9, 10, 8, 9, 15};
    j = findDuplicate(v, v.size());
    cout << j << endl;
    return 0;
}
