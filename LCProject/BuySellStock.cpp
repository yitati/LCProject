/******************************************************************************/
/**
* Question: #121 Best Time to Buy and Sell Stock I
* Say you have an array for which the ith element is the price of a given stock on day i.
* If you were only permitted to complete at most one transaction (ie, buy one and sell
* one share of the stock), design an algorithm to find the maximum profit.
*
* Question: #122 Best Time to Buy and Sell Stock II
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete as many transactions as you like
* (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple
* transactions at the same time (ie, you must sell the stock before you buy again).
*
* Question: #123 Best Time to Buy and Sell Stock III
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
*
* Question: #188 Best Time to Buy and Sell Stock IV
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Stock {
public:
	// if only 1 transaction allowed
	int maxProfitI(vector<int>& prices) {
		int i;
		int minVal = INT_MAX, maxVal = INT_MIN;
		if (prices.size() < 2) return 0;
		int profit = 0;
		for (i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minVal) minVal = prices[i];
			profit = max(profit, prices[i] - minVal);
		}
		for (i = prices.size() - 1; i >= 0; i--)
		{
			if (prices[i] > maxVal) maxVal = prices[i];
			profit = max(profit, maxVal - prices[i]);
		}
		return profit;
	}

	// if unlimited transactions are allowed
	int maxProfitII(vector<int>& prices) {
		int i;
		int profit = 0;
		if (prices.size() < 2) return 0;
		for (i = 0; i < prices.size()-1; i++)
		{
			if (prices[i + 1] - prices[i] > 0) profit += prices[i + 1] - prices[i];
		}
		return profit;
	}

	// if 2 transactions are allowed
	int maxProfitIII(vector<int>& prices)
	{
		if (prices.size() < 2) return 0;
		int n = prices.size();
		int i;
		vector<int> profit_left(n, 0);
		vector<int> profit_right(n, 0);
		int max_profit = INT_MIN, minVal = INT_MAX, maxVal = INT_MIN;

		// profit_left[i] - the max profit to sell stock at day i (buy with minVal at a previous point)
		for (i = 0; i < n; i++) 
		{
			minVal = min(prices[i], minVal);
			if (i == 0) profit_left[i] = 0;
			else 
			{
				profit_left[i] = max(profit_left[i - 1], prices[i] - minVal);
			}
		}

		// profit_right[i] - the max profit to buy stock at day i (sell with maxVal at a coming point)
		for (i = n - 1; i >= 0; i--)
		{
			maxVal = max(prices[i], maxVal);
			if (i == n - 1) profit_right[i] = 0;
			else 
			{
				profit_right[i] = max(profit_right[i + 1], maxVal - prices[i]);
			}
		}

		// get the max value - sell happens after buy!!
		for (i = 0; i < n-1; i++)
		{
			max_profit = max(profit_left[i] + profit_right[i + 1], max_profit);
		}

		//max_profit = max(profit_left[n - 1], max_profit);
		return max_profit;
	}



};
