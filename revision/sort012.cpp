#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

// void sort012(int *arr, int n)
// {
//     int ump[3] = {0, 0, 0};
//     for (int  i = 0; i < n; i++)
//     {
//         if (arr[i] == 0){
//             ump[0]++;
//             continue;
//         }
//         if (arr[i] == 1){
//             ump[1]++;
//             continue;
//         }
//         if (arr[i] == 2){
//             ump[2]++;
//             continue;
//         }
//     }
//     for (int i = 0; i < ump[0]; i++)
//     {
//         arr[i] = 0;
//     }
//     for (int i = ump[0]; i < ump[0] + ump[1]; i++)
//     {
//         arr[i] = 1;
//     }
//     for (int i = ump[0] + ump[1]; i < n; i++)
//     {
//         arr[i] = 2;
//     }
    
   
// }

// Optimized version
void sort012(int *arr, int n)
{
    int low = 0, mid = 0, high = n-1;
    while (mid <= high)
    {
        if (arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    
}

int main()
{
    int arr[6] = { 0, 1, 2, 2, 1, 0 }; // 1 2 3 4 5 6 10 9 8 7 => m + (n-m) / 2
    sort012(arr, 6);
    cout << "[ ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}