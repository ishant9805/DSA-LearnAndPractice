#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices) {
    // Write your code here.
    int max_profit = 0;
    int min_price = 1e9;
    for (int it = 0; it < prices.size(); it++)
    {
        if (min_price > prices[it])
        {
            min_price = prices[it];
        }
        max_profit = max(max_profit, prices[it] - min_price);
    }
    
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 7, 9, 8, 6, 7, 6, 10, 5};
    int k = maxProfit(prices);
    cout << k << endl;
    return 0;
}