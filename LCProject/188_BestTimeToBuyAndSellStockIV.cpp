/******************************************************************************/
/*
* Question: #188 Best Time To Buy And Sell Stock IV
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// hold[i][j] - max profit at ith transaction and jth day if we hold some stock
// empty[i][j] - max profit at ith transaction and jth day if we don't hold any stock
int buySellAny(vector<int> & prices)
{
	int profit = 0;
	for (int i = 1; i<prices.size(); i++)
	{
		if (prices[i] > prices[i - 1])
		{
			profit = profit + (prices[i] - prices[i - 1]);
		}
	}
	return profit;
}

int maxProfitIV(int k, vector<int>& prices)
{
	int len = prices.size();
	if (k >= len / 2) return buySellAny(prices);

	vector<vector<int>> hold(k + 1, vector<int>(prices.size(), 0));
	vector<vector<int>> empty(k + 1, vector<int>(prices.size(), 0));

	// base case
	for (int j = 0; j < prices.size(); j++)
	{
		empty[0][j] = 0;  // if we don't hold stock
		hold[0][j] = -prices[j];  // if we hold stock
	}

	for (int i = 0; i <= k; i++)
	{
		empty[i][0] = 0;
		hold[i][0] = -prices[0];
	}

	// calculate empty[i][j] and hold[i][j]
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j < prices.size(); j++)
		{
			empty[i][j] = max(empty[i][j - 1], hold[i][j - 1] + prices[j]);
			hold[i][j] = max(hold[i][j - 1], empty[i - 1][j - 1] - prices[j]);
		}
	}

	return empty[k][prices.size() - 1];
}


// a consive solution - if we put profit[i][j] to be the max profit on day j up to i transactions
int maxProfitIV_consice(int k, vector<int>& prices)
{
	int n = prices.size();
	if (k >= n / 2) return buySellAny(prices);
	vector<vector<int>> profit(k + 1, vector<int>(n, 0));

	// calculate empty[i][j] and hold[i][j]
	for (int i = 1; i <= k; i++)
	{
		int tmpMax = -prices[0];
		for (int j = 1; j < n; j++)
		{
			profit[i][j] = max(profit[i][j - 1], tmpMax + prices[j]);
			tmpMax = max(tmpMax, profit[i - 1][j - 1] - prices[j]);
		}
	}

	return profit[k][n - 1];
}