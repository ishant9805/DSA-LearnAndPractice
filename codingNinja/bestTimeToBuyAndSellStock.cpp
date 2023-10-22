#include<iostream>
#include<vector>
using namespace std;

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int max_profit = 0;
    for (int it = 0; it < prices.size(); it++)
    {
        for (int i = it + 1; i < prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i] - prices[it]);
        }
    }
    
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 7, 9, 8, 6, 7, 6, 10, 5};
    int k = bestTimeToBuyAndSellStock(prices);
    cout << k << endl;
    return 0;
}