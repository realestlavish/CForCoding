#include <bits/stdc++.h>
using namespace std;

void stockseller(vector<int> stocks)
{
    int mini = stocks[0];
    int profit = 0;
    for (int i = 0; i < stocks.size(); i++)
    {
        int cost = stocks[i] - mini;
        mini = min(mini, stocks[i]);
        profit = max(profit, cost);
    }
}

int main()
{
    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    stockseller(stocks);

    return 0;
}