#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	
}

int main()
{
    vector<vector<int>> v = {{1,2},{1,3},{1,6},{3,4},{4,4},{4,5},{5,5},{5,6},{6,6}};
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