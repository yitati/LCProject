/******************************************************************************
* Question: #122 Best Time To Buy And Sell Stock II
* company tag: Facebook
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. 
* You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
* However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before
* you buy again).
* Follow-up:
* What if there is transaction fee every time we do the trade?
*****************************************************************************/

#include <vector>

using namespace std;

int maxProfitII(vector<int>& prices) 
{
	int profit = 0;
	for (int i = 1; i<prices.size(); i++)
	{
		if (prices[i] > prices[i - 1])  // we add check here the fee
		{
			profit = profit + (prices[i] - prices[i - 1]);
		}
	}

	return profit;
}
