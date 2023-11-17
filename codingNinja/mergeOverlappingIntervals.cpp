#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    // Example vector :- {{1,2},{1,3},{1,6},{3,4},{4,4},{4,5},{5,5},{5,6},{6,6}}
    int nsz = 1;
    while (arr.size() > nsz)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int l1 = arr[i-1][0];
            int l2 = arr[i][0];
            int r1 = arr[i-1][1];
            int r2 = arr[i][1];
            if (l1 <= l2)
            {
                if (l2 <= r1)
                {
                    int mini = min(l1, l2);
                    int maxi = max(r1, r2);
                    arr[i] = {mini, maxi};
                    arr.erase(arr.begin()+i-1);
                    i -= 1;
                } else {
                    nsz += 1;
                }
                
            }
            
        }
    }
    cout << "NSZ: " << nsz << endl;
    return arr;
	
}

int main()
{
    // vector<vector<int>> v = {{1,2},{1,3},{1,6},{3,4},{4,4},{4,5},{5,5},{6,6},{6,6}};
    vector<vector<int>> v = {{1,4},{3,3},{3,3},{3,3},{3,4},{4,4},{5,5},{5,5},{5,6}};
    v = mergeOverlappingIntervals(v);
    int rowSize = v.size();
    int colSize = v[0].size();
    cout << "[";
    for (int i = 0; i < rowSize - 1; i++)
    {
        cout << "[";
        for (int j = 0; j < colSize - 1; j++)
        {
            cout << v[i][j] << ", ";
        }
        cout << v[i][colSize - 1] << "]" << endl << " ";
    }
    cout << "[";
    for (int i = 0; i < colSize - 1; i++)
    {
        cout << v[rowSize - 1][i] << ", ";
    }
    cout << v[rowSize - 1][colSize - 1] << "]]" << endl;
    return 0;
}